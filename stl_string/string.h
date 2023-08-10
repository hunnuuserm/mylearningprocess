#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

namespace myString
{
	class string
	{
	public:
		#define BUFFSIZE 32
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin();
		iterator end();
		const_iterator begin()const;
		const_iterator end()const;
		void swap(string& s);
		string();
		string(const string& s);
		string(const char* s);
		~string();
		size_t size()const;
		size_t capacity()const;
		bool empty()const;
		void clear();
		void reserve(size_t size = 0);
		void resize(size_t n, char ch = '\0');
		const char* c_str()const;
		char& operator[](size_t pos);
		const char& operator[](size_t pos)const;
		void push_back(const char& ch);
		void append(const char* s);
		void append(const string& s);
		string& operator+=(const char& ch);
		string& operator+=(const char* s);
		string& operator+=(const string& s);
		size_t find(const char& ch, const size_t pos = 0)const;
		size_t find(const char* s, size_t pos = 0)const;
		string& insert(size_t pos, const char* s);
		string& insert(size_t pos, const string& s);
		string& erase(size_t pos = 0, size_t len = npos);
		string& operator=(string s);
		string substr(size_t pos = 0, size_t len = npos)const;
		bool operator>(const string& s)const;
		bool operator==(const string& s)const;
		bool operator>=(const string& s)const;
		bool operator<(const string& s)const;
		bool operator<=(const string& s)const;
		bool operator!=(const string& s)const;


	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos = -1;
	};
	//const size_t string::npos = -1;
	ostream& operator<<(ostream& out, const string& s);
	istream& operator>>(istream& in, string& s);
}