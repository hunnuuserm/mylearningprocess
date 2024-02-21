#include"smartPtr.h"
#include<thread>

class Date
{
public:
	int _year = 0;
	int _month = 0;
	int _day = 0;
};

void test1()
{
	m::auto_ptr<int> p1 = new int(1);
	(*p1) = 2;
	std::cout << (*p1) << std::endl;

	m::auto_ptr<Date> p2 = new Date;
	std::cout << p2->_year << ": " << p2->_month << ": " << p2->_day << std::endl;
}

void test2()
{
	m::auto_ptr<int> p1 = new int(1);
	//m::auto_ptr<int> p2(p1);
	*p1;
}
void test3()
{
	std::auto_ptr<int> p1(new int(1));
	std::auto_ptr<int> p2(new int(2));
	p2 = p1;
	int a = 1;

}

void test4()
{
	m::unique_ptr<int> p1(new int(1));
	m::unique_ptr<int> p2(new int(2));
	//p2 = p1;

}

void test5()
{
	m::shared_ptr<int> p1(new int(1));
	m::shared_ptr<int> p2 = p1;

	m::shared_ptr<int> p3(new int(3));
	p3 = p2;
	
	int a = 1;
}

void test6()
{
	int n = 1000;
	m::shared_ptr<int> p1(new int(1));
	std::thread t1([&]()
		{
			for (int i = 0; i < n; i++)
			{
				m::shared_ptr<int> pInThread(p1);
			}
		});
	std::thread t2([&]()
		{
			for (int i = 0; i < n; i++)
			{
				m::shared_ptr<int> pInThread(p1);
			}
		});

	t1.join();
	t2.join();

	std::cout << "p1.getPcount(): " << p1.use_count() << std::endl;
}

void test7()
{
		int n = 1000000;
		//m::shared_ptr<Date> p1(new Date);
		std::shared_ptr<Date> p1(new Date);

		std::mutex mtx;
		std::thread t1([&]()
			{
				for (int i = 0; i < n; i++)
				{
					//m::shared_ptr<Date> pInThread(p1);
					std::shared_ptr<Date> pInThread(p1);

					mtx.lock();
					pInThread->_year++;
					pInThread->_month++;
					pInThread->_day++;
					mtx.unlock();
				}
			});
		std::thread t2([&]()
			{
				for (int i = 0; i < n; i++)
				{
					//m::shared_ptr<Date> pInThread(p1);
					std::shared_ptr<Date> pInThread(p1);

					mtx.lock();
					pInThread->_year++;
					pInThread->_month++;
					pInThread->_day++;
					mtx.unlock();
				}
			});

		t1.join();
		t2.join();

		std::cout << "p1.use_count(): " << p1.use_count() << std::endl;
		std::cout << "year: " << p1->_year << std::endl;
		std::cout << "month: " << p1->_month << std::endl;
		std::cout << "day: " << p1->_day << std::endl;
}

void test8()
{
	struct node
	{
	
		/*m::shared_ptr<node> _prve;
		m::shared_ptr<node> _next;*/
		std::weak_ptr<node> _prve;
		std::weak_ptr<node> _next;

		int _val = 0;

		~node()
		{
			std::cout << "struct node: ~node()" << std::endl;
		}
	};

	//std::cout << sizeof(node) << std::endl;

	std::shared_ptr<node> p1 (new node);
	std::shared_ptr<node> p2 (new node);

	p1->_next = p2;
	p2->_prve = p1;

}

void test9()
{
	std::shared_ptr<int> p1(new int[10], [](int* p) {
		std::cout << "lambda delete[]" << std::endl;
		delete[] p;
		});

}

int main()
{
	test9();








	//std::thread t1([]() {
	//	int a = 1;
	//	});

	//t1.join();

	return 0;
}