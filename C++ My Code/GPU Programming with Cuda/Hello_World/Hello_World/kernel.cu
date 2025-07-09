#include <cuda_runtime.h>
#include <iostream>
// This is a simple CUDA kernel that prints the block number, thread number, and wrap number
__global__ void print() {
	printf("block number %d -- thread number %d -- wrap number %d\n",blockIdx.x,threadIdx.x,threadIdx.x/32);
}

int main() {

	// Launching the kernel with 1 block and 1 thread
	print << <1, 1 >> > ();
	// Launching the kernel with 1 block and 1024 threads
	print << <1, 1024 >> > ();
	// Launching the kernel with 32 blocks and 1024 threads
	print << <32, 1024 >> > ();


	return 0;
}
