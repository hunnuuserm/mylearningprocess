#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

int main()
{
	int n = 100;
	std::mutex mtx;
	std::condition_variable cond;
	//t1打印奇数,t2打印偶数
	int i = 1;
	std::thread t1([&,n]() {
		while (true)
		{
			std::unique_lock<std::mutex> u_lock(mtx);

			if (i > n) break;


			if (i % 2 == 0)
			{
				cond.wait(u_lock);
			}

			if (i > n) break;

			std::cout << std::this_thread::get_id() << ": " << i << std::endl;
			i++;
			cond.notify_one();
		}
		});
	std::thread t2([&, n]() {
		while (true)
		{
			std::unique_lock<std::mutex> u_lock(mtx);

			if (i > n) break;

			if (i % 2 == 1)
			{
				cond.wait(u_lock);
			}

			if (i > n) break;

			std::cout << std::this_thread::get_id() << ": " << i << std::endl;
			i++;
			cond.notify_one();
		}
		});

	t1.join();
	t2.join();
	return 0;
}