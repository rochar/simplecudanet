#ifndef ADD_VECTORS_CU
#define ADD_VECTORS_CU
#include "driver_types.h"
cudaError_t RunAddVectorsKernel(int elementsToAdd, int* device_v1, int* device_v2, int* device_result);
#endif