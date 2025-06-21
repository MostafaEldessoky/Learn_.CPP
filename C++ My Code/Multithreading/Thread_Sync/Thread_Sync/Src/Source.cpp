#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::string data = "";
bool predicate = false;
bool predicate_process = false;
std::mutex mtx;
std::mutex mtx_process;
std::condition_variable progresscv;
std::condition_variable processcv;


void download()
{
	int i = 1;
	while (i < 10) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		mtx.lock();
		data = data + "block_";
		predicate = true;
		progresscv.notify_all();
		mtx.unlock();
		i++;
	}
	mtx_process.lock();
	predicate_process = true;
	mtx_process.unlock();
	processcv.notify_all();
}

void progress()
{
	while (true)
	{
		std::unique_lock<std::mutex> lock(mtx);
		progresscv.wait(lock, [] { return predicate; });
		std::cout << "Downloading: " << data << std::endl;
		predicate = false;
		lock.unlock();
		std::unique_lock<std::mutex> lock_process(mtx_process);
		if (predicate_process)
		{
			break;
		}
	}

}

void process()
{
	std::unique_lock<std::mutex> lock(mtx_process);
	processcv.wait(lock, [] { return predicate_process; });
	lock.unlock();
	std::cout << "Processing: " << data << std::endl;
	std::cout << "Processing complete." << std::endl;
}


int main() {

	std::thread t1(download);
	std::thread t2(progress);
	std::thread t3(process);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}