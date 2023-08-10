#include"string.h"

namespace myString
{
	string::iterator string::begin()
	{
		return _str;
	}
	string::iterator string::end()
	{
		return _str + _size;
	}

	string::const_iterator string::begin()const
	{
		return _str;
	}
	string::const_iterator string::end()const
	{
		return _str + _size;
	}
	void string::swap(string& s)
	{
		::swap(_str, s._str);
		::swap(_size, s._size);
		::swap(_capacity, s._capacity);
	}
	string::string()
		:_str(new char[1])
		, _size(0)
		, _capacity(0)
	{
		_str[0] = '\0';
	}
	string::string(const string& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		string tmp(s._str);
		swap(tmp);
	}
	string::string(const char* s)
	{
		assert(s);
		_size = strlen(s);
		_capacity = _size;
		_str = new char[_capacity + 1];
		strcpy(_str, s);
	}
	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}
	size_t string::size() const
	{
		return _size;
	}
	size_t string::capacity()const
	{
		return _capacity;
	}
	bool string::empty()const
	{
		return _size == 0;
	}
	void string::clear()
	{
		_str[0] = '\0';
		_size = 0;
	}
	void string::reserve(size_t size)
	{
		if (_capacity < size)
		{
			char* tmp = new char[size + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = size;
		}
	}
	void string::resize(size_t n, char ch )
	{
		if (n > _size)
		{
			reserve(n);
			for (size_t i = _size; i < n; i++)
			{
				_str[i] = ch;
			}
			_size = n;
			_str[_size] = '\0';
		}
		else if (n <= _size)
		{
			_str[n] = '\0';
			_size = n;
		}
	}
	const char* string::c_str()const
	{
		return _str;
	}
	char& string::operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}
	const char& string::operator[](size_t pos)const
	{
		assert(pos < _size);
		return _str[pos];
	}
	void string::push_back(const char& ch)
	{
		//复用reserve
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size] = ch;
		_size++;
		_str[_size] = '\0';
	}
	void string::append(const char* s)
	{
		size_t s_len = strlen(s);
		if (_size + s_len > _capacity)
		{
			reserve(_size + s_len);
		}
		strcpy(_str + _size, s);
		_size += s_len;
	}
	void string::append(const string& s)
	{
		append(s.c_str());
	}
	string& string::operator+=(const char& ch)
	{
		push_back(ch);
		return *this;
	}
	string& string::operator+=(const char* s)
	{
		append(s);
		return *this;
	}
	string& string::operator+=(const string& s)
	{
		append(s);
		return *this;
	}
	size_t string::find(const char& ch, const size_t pos)const
	{
		assert(pos < _size);
		size_t i = pos;
		while (i < _size)
		{
			if (_str[i] == ch)
			{
				return i;
			}
			i++;
		}
		return npos;
	}
	size_t string::find(const char* s, size_t pos)const
	{
		assert(pos < _size);
		assert(s);
		size_t len = strlen(s);
		assert(pos + len <= _size);
		char* ret = strstr(_str + pos, s);
		if (ret != nullptr)
		{
			return ret - _str;
		}
		return npos;
	}
	string& string::insert(size_t pos, const char* s)
	{
		assert(pos <= _size);
		size_t len = strlen(s);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		size_t end = _size + len;
		while (end >= pos + len)
		{
			_str[end] = _str[end - len];
			end--;
		}
		strncpy(_str + pos, s, len);
		_size += len;
		return *this;
	}
	string& string::insert(size_t pos, const string& s)
	{
		return insert(pos, s.c_str());
	}
	string& string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len == npos || pos + len >= _size)
		{
			_str[pos] = '\0';
			_size = pos;
			return *this;
		}
		strcpy(_str + pos, _str + pos + len);
		_size -= len;
		return *this;
	}
	//传统写法的赋值重载
		/*string& string::operator=(const string& s)
		{
			assert(!s.empty());
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s.c_str());
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return*this;
		}*/
		//现代写法的赋值重载1
		//string& string::operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s._str);
		//		swap(tmp);//this->swap(tmp);
		//	}
		//	return *this;
		//}
		//现代写法的赋值重载2
	string& string::operator=(string s)
	{
		swap(s);//this->swap(s);
		return *this;
	}
	string string::substr(size_t pos, size_t len)const
	{
		/*	assert(pos < _size);
			string retStr;
			retStr.reserve(_size - pos);
			if (len == npos || pos + len > _size)
			{
				strcpy(retStr._str, _str + pos);
				retStr._size = _size - pos;
				return retStr;
			}
			else
			{
				strncpy(retStr._str, _str + pos, len);
				retStr._size = len;
				retStr._str[retStr._size] = '\0';
				return retStr;
			}*/
		string sub;
		size_t realLen = len;
		if (len == npos || pos + len > _size)
		{
			realLen = _size - pos;
		}
		for (size_t i = 0; i < realLen; i++)
		{
			sub += _str[pos + i];
		}
		return sub;
	}
	bool string::operator>(const string& s)const
	{
		return strcmp(_str, s._str) > 0;
	}
	bool string::operator==(const string& s)const
	{
		return strcmp(_str, s._str) == 0;
	}
	bool string::operator>=(const string& s)const
	{
		return *this > s || *this == s;
	}
	bool string::operator<(const string& s)const
	{
		return !(*this >= s);
	}
	bool string::operator<=(const string& s)const
	{
		return!(*this > s);
	}
	bool string::operator!=(const string& s)const
	{
		return !(*this == s);
	}
	ostream& operator<<(ostream& out, const string& s)
	{
		size_t i = 0;
		for (i = 0; i < s.size(); i++)
		{
			cout << s[i];
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		//方法1
		/*s.clear();
		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s.push_back(ch);
			ch = in.get();
		}
		return in;*/
		//方法2（减少扩容消耗）
		s.clear();
		char buff[BUFFSIZE + 1] = { 0 };
		size_t i = 0;
		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == BUFFSIZE)
			{
				buff[BUFFSIZE] = '\0';
				i = 0;
				s += buff;
			}
			ch = in.get();
		}
		buff[i] = '\0';
		s += buff;
		return in;
	}
}