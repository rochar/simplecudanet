#include "AddVectorsKernel.h"
#include "AddVectorsKernel.cuh"

#include <cstdlib>
#include <cuda_runtime.h>

using namespace System::Runtime::InteropServices;

array<int>^  AddVectorsKernel::AddVectors(array<int>^ v1, array<int>^ v2, int elementsToAdd)
{
	int* dev_v1 = nullptr;
	int* dev_v2 = nullptr;
	int* dev_result = nullptr;
	int* result = nullptr;
	int size = sizeof(int);
	try
	{
		cudaMalloc((void**)&dev_v1, size * elementsToAdd);
		cudaMalloc((void**)&dev_v2, size * elementsToAdd);
		cudaMalloc((void**)&dev_result, size * elementsToAdd);

		pin_ptr<int> pV1 = &v1[0];
		pin_ptr<int> pV2 = &v2[0];

		cudaMemcpy(dev_v1, pV1, size * elementsToAdd, cudaMemcpyHostToDevice);
		cudaMemcpy(dev_v2, pV2, size * elementsToAdd, cudaMemcpyHostToDevice);

		RunAddVectorsKernel(elementsToAdd, dev_v1, dev_v2, dev_result);

		result = (int*)malloc(size * elementsToAdd);
		cudaMemcpy(result, dev_result, size * elementsToAdd, cudaMemcpyDeviceToHost);

		array<int>^ managedResult = gcnew array<int>(elementsToAdd);

		Marshal::Copy((System::IntPtr)result, managedResult, 0, elementsToAdd);

		return managedResult;
	}
	finally 
	{
		cudaFree(dev_v1);
		cudaFree(dev_v2);
		cudaFree(dev_v2);

		free(result);
	}
	
}