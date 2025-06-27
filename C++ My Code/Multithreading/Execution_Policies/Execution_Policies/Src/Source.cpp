#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <numeric>
#include <mutex>

std::mutex mutex;

int main( ) {

	int count = 100000;
	std::vector<int> numbers(count);
	std::vector<int> numbers2(count);
	std::vector<int> numbers3(count);
	std::vector<int> numbers4(count);
	std::iota(numbers.begin(), numbers.end(), 1);
	std::iota(numbers2.begin(), numbers2.end(), 1);
	std::iota(numbers3.begin(), numbers3.end(), 1);
	std::iota(numbers4.begin(), numbers4.end(), 1);
	int sum = 1;
	int sum2 = 1;
	int sum3 = 1;
	int sum4 = 1;
	std::this_thread::sleep_for(std::chrono::seconds(1)); 
	std::for_each(std::execution::seq, numbers.begin(), numbers.end(), [&sum](int& n) {
		sum += n; 
		});
	std::cout << "Sum using sequential execution: " << sum << std::endl;
	std::for_each(std::execution::par, numbers2.begin(), numbers2.end(), [&sum2](int& n) {
		mutex.lock();
		sum2 += n; 
		mutex.unlock();
		});
	std::cout << "Sum using parallel execution: " << sum2 << std::endl;
	std::for_each(std::execution::unseq, numbers3.begin(), numbers3.end(), [&sum3](int& n) {
		sum3 += n; 
		});
	std::cout << "Sum using unsequenced execution: " << sum3 << std::endl;
	std::for_each(std::execution::par_unseq, numbers4.begin(), numbers4.end(), [&sum4](int& n) {
		//mutex.lock();
		sum4 += n; 
		//mutex.unlock();
		});
	std::cout << "Sum using parallel unsequenced execution: " << sum4 << std::endl;
	return 0;
	}