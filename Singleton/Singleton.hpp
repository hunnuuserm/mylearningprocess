#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

//����ģʽ
class Singleton
{
public:
	static Singleton* getInstance()
	{
		return _instancePtr;
	}
	//�����ֶ��ͷŵ�������
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
	//ʵ��һ����Ƕ����������
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
		//�����Զ���������
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

//����ģʽ
class singLeton
{
public:
	static singLeton* getInstance(int val = 0)
	{
		if (_instancePtr == nullptr)//˫���������ȱ�֤�̰߳�ȫ���ֱ�֤Ч��
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
	//�����ֶ��ͷŵ�������
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

	//ʵ��һ����Ƕ����������
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
		//�����Զ���������
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


//C++11֮���������д������
class SingLeton
{
public:
	static SingLeton& getInstance(int val = 0)
	{
		static SingLeton SL(0);//C++11֮������д���Ա�֤��ʼ����̬������̰߳�ȫ����
		return SL;
	}
	~SingLeton()
	{
		//�Զ����������������ݳ־û���
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