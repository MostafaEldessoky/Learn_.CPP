#include <iostream>
#include <vector>


class wrap_cuda {

	int* a;
	int* b;
	int* c;

	public:

		wrap_cuda(int size)  {
			cudaMalloc(&a,size * sizeof(int));
			cudaMalloc(&b,size * sizeof(int));
			cudaMalloc(&c,size * sizeof(int));
		}

		~wrap_cuda() {
			cudaFree(a);
			cudaFree(b);
			cudaFree(c);
		}

		void copy_to_device(int* host_a, int* host_b, int size) {
			cudaMemcpy(a, host_a, size * sizeof(int), cudaMemcpyHostToDevice);
			cudaMemcpy(b, host_b, size * sizeof(int), cudaMemcpyHostToDevice);
		}

		void copy_to_host(int* host_c, int size) {
			cudaMemcpy(host_c, c, size * sizeof(int), cudaMemcpyDeviceToHost);
		}
		template<typename F>
		void exc(int blocks,int threads,F f){
			f <<<blocks,threads>>>(a,b,c,threads);
			cudaDeviceSynchronize();
		}

};

// generic pointer void* can take any pointer type
void fn(void* ptr) {
	std::cout << *(int*)ptr << std::endl;
	
}

// Kernel function to add two vectors
__global__ void add_vec(int* a, int* b, int* c,int threads) {
	c[blockIdx.x*threads + threadIdx.x] = a[blockIdx.x * threads + threadIdx.x] + b[blockIdx.x * threads + threadIdx.x];
}


int SIZE = 1024;

int main() {

	int* host_a = new int[SIZE*2];
	int* host_b = new int[SIZE*2];
	int* host_c = new int[SIZE*2];

	wrap_cuda cuda_wrapper(SIZE*2);

	for (int i = 0; i < SIZE*2; ++i) {
		host_a[i] = i;
		host_b[i] = SIZE*2 - i;
	}

	cuda_wrapper.copy_to_device(host_a, host_b, SIZE*2);
	cuda_wrapper.exc(2, SIZE, add_vec);
	cuda_wrapper.copy_to_host(host_c, SIZE*2);

	fn(host_c);

	for (int i = 0; i < SIZE*2; i++) {
		std::cout << *(host_c + i) << " ";
	}
	std::cout << std::endl;

	delete[] host_a;
	delete[] host_b;
	delete[] host_c;

	return 0;
}