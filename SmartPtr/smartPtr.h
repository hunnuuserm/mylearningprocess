#pragma once

#include<iostream>
#include<memory>
#include<mutex>
namespace m
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}
		//auto_ptr进行拷贝构造会出现管理权限转移的问题
		auto_ptr(const auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}
		~auto_ptr()
		{
			std::cout << "~auto_ptr()" << std::endl;
			delete _ptr;
		}
		T& operator*()const noexcept
		{
			return *_ptr;
		}
		T* operator->()const noexcept
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		unique_ptr(const unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;

		~unique_ptr()
		{
			std::cout << "~unique_ptr()" << std::endl;
			delete _ptr;
		}
		T& operator*()const noexcept
		{
			return *_ptr;
		}
		T* operator->()const noexcept
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new std::mutex)
		{}
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			(*_pmtx).lock();
			(*_pcount) += 1;
			(*_pmtx).unlock();
		}
		T& operator*()const
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				(*_pmtx).lock();
				if (--(*_pcount) == 0)
				{
					delete _ptr;
					delete _pcount;
					std::cout << "shared_ptr<T>& operator=(const shared_ptr<T>& sp): delete _ptr; delete _pcount;" << std::endl;

					(*_pmtx).unlock();
					delete _pmtx;
				}
				else
				{
					(*_pmtx).unlock();
				}

				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;

				(*_pmtx).lock();
				++(*_pcount);
				(*_pmtx).unlock();
			}

			return *this;
		}
		int use_count()const
		{
			return *_pcount;
		}
		~shared_ptr()
		{
			(*_pmtx).lock();
			if (--(*_pcount) == 0)
			{
				std::cout << "~shared_ptr(): delete _ptr; delete _pcount;" << std::endl;
				delete _ptr;
				delete _pcount;

				(*_pmtx).unlock();
				delete _pmtx;
				return;
			}
			(*_pmtx).unlock();
		}
	private:
		T* _ptr;
		int* _pcount;
		std::mutex* _pmtx;
	};
}