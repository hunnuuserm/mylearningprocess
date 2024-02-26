#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

//饿汉模式
class Singleton
{
public:
	static Singleton* getInstance()
	{
		return _instancePtr;
	}
	//允许手动释放单例对象
	static void destroyInstance()
	{
		_mtx.lock();
		if (_instancePtr)
		{
			delete _instancePtr;
			_instancePtr = nullptr;
		}
		_mtx.unlock();
	}
	//实现一个内嵌垃圾回收类
	class GC
	{
	public:
		~GC()
		{
			destroyInstance();
		}
	};
private:
	Singleton(int val = 0)
		:_val(val)
	{}
	Singleton(const Singleton& cp) = delete;
	Singleton& operator=(const Singleton& cp) = delete;
	~Singleton()
	{
		//可以自定义清理工作
	}
private:
	int _val;
private:
	static Singleton* _instancePtr;
	static GC _gc;
	static mutex _mtx;
};

Singleton* Singleton::_instancePtr = new Singleton;
Singleton::GC Singleton::_gc;
mutex Singleton::_mtx;

//懒汉模式
class singLeton
{
public:
	static singLeton* getInstance(int val = 0)
	{
		if (_instancePtr == nullptr)//双检查加锁，既保证线程安全，又保证效率
		{
			_mtx.lock();
			if (_instancePtr == nullptr)
			{
				_instancePtr = new singLeton(val);
			}
			_mtx.unlock();
		}

		return _instancePtr;
	}
	//允许手动释放单例对象
	static void destroyInstance()
	{
		_mtx.lock();
		if (_instancePtr)
		{
			delete _instancePtr;
			_instancePtr = nullptr;
		}
		_mtx.unlock();
	}

	//实现一个内嵌垃圾回收类
	class GC
	{
	public:
		~GC()
		{
			destroyInstance();
		}
	};
private:
	singLeton(int val = 0)
		:_val(val)
	{}
	singLeton(const singLeton& cp) = delete;
	singLeton& operator=(const singLeton& cp) = delete;
	~singLeton()
	{
		//可以自定义清理工作
	}
private:
	int _val = 0;
private:
	static singLeton* _instancePtr;
	static mutex _mtx;
	static GC _gc;
};

singLeton* singLeton::_instancePtr = nullptr;
mutex singLeton::_mtx;
singLeton::GC singLeton::_gc;


//C++11之后可以这样写单例类
class SingLeton
{
public:
	static SingLeton& getInstance(int val = 0)
	{
		static SingLeton SL(0);//C++11之后，这样写可以保证初始化静态对象的线程安全问题
		return SL;
	}
	~SingLeton()
	{
		//自定义清理工作，如数据持久化等
	}

private:
	SingLeton(int val = 0)
		:_val(val)
	{}
	SingLeton(const SingLeton& cp) = delete;
	SingLeton& operator=(const SingLeton& cp) = delete;
private:
	int _val;
};