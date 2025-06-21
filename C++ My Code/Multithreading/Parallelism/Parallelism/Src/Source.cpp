#include <algorithm>
#include <array>
#include <future>
#include <iostream>
#include <numeric>
#include <vector>

const int cut = 8;

int acc(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	std::this_thread::sleep_for(std::chrono::seconds(10));
	return std::accumulate(start, end, 0);
}

int main() {

	std::vector<int> v(1000000);
	std::iota(v.begin(), v.end(), 1);


	std::array<std::future<int>, cut> arr;

	for (int i = 1, j = 0; i <= cut; i++, j++)
	{
		arr.at(j) = std::async(std::launch::async, acc, v.begin() + (j * v.size() / cut), v.begin() + (i * v.size() / cut));
	}

	int y = 0;
	std::for_each(arr.begin(), arr.end(), [&y](std::future<int>& x)
		{
			y += x.get();
		});

	std::cout << "Sum with parallelism : " << y << std::endl;

	std::cout << "Sum as normal : " << std::accumulate(v.begin(), v.end(), 0) << std::endl;


	return 0;
}