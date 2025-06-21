#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> x{ 0 };

void func()
{
	for (int i = 0; i < 10; i++)
	{
		x++;
		printf("%d\n", x.load());
	}
}

int main() {

	std::thread t1(func);
	std::thread t2(func);
	t1.join();
	t2.join();
	return 0;
}
