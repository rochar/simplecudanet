#include "AddVectorsKernel.cuh"

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
__global__ void AddVectorsKernel(int n, int* v1, int* v2, int* result)
{
	int index = blockIdx.x * blockDim.x + threadIdx.x;

	if (index < n)
	{
		result[index] = v1[index] + v2[index];
	}
}


cudaError_t RunAddVectorsKernel(int elementsToAdd, int* device_v1, int* device_v2, int* device_result)
{
	int blockSize = 256;
	int numBlocks = (elementsToAdd + blockSize - 1) / blockSize;
	
	AddVectorsKernel <<<numBlocks, blockSize >>> (elementsToAdd, device_v1, device_v2, device_result);

	return cudaDeviceSynchronize();
}