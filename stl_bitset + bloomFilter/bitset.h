#pragma once
#include<vector>
using namespace std;

namespace m
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bit.resize(N / 8 + 1, 0);
		}
		void set(size_t x)
		{
			size_t hashi = x / 8;
			size_t hashj = x % 8;
			_bit[hashi] = _bit[hashi] | 1 << hashj;//_bit[hashi] |= 1 << hashj;
		}
		void reset(size_t x)
		{
			size_t hashi = x / 8;
			size_t hashj = x % 8;
			_bit[hashi] = _bit[hashi] & (~(1 << hashj));//_bit[hashi] &= (~(1 << hashj));
		}
		bool test(size_t x)
		{
			size_t hashi = x / 8;
			size_t hashj = x % 8;

			return _bit[hashi] & (1 << hashj);
		}
	private:
		vector<char> _bit;
	};


	struct BKDRHash
	{
		size_t operator()(const string& s)
		{
			size_t hashsum = 0;
			for (auto e : s)
			{
				hashsum += e;
				hashsum *= 31;
			}
			return hashsum;
		}
	};
	struct APHash
	{
		size_t operator()(const string& s)
		{
			size_t hash = 0;
			for (long i = 0; i < s.size(); i++)
			{
				size_t ch = s[i];
				if ((i & 1) == 0)
				{
					hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
				}
				else
				{
					hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
				}
			}
			return hash;
		}
	};
	struct DJBHash
	{
		size_t operator()(const string& s)
		{
			size_t hash = 5381;
			for (auto ch : s)
			{
				hash += (hash << 5) + ch;
			}
			return hash;
		}
	};

	template<size_t N,
		class hashFunc1 = BKDRHash,
		class hashFunc2 = APHash,
		class hashFunc3 = DJBHash,
		class K = string>
		class bloomFilter
	{
	public:
		void set(const K& key)
		{
			size_t len = N * _X;
			size_t hashi1 = hashFunc1()(key);
			size_t hashi2 = hashFunc2()(key);
			size_t hashi3 = hashFunc3()(key);
			_bit.set(hashi1 % len);
			_bit.set(hashi2 % len);
			_bit.set(hashi3 % len);
		}
		bool test(const K& key)
		{
			size_t len = N * _X;
			size_t hashi1 = hashFunc1()(key);
			size_t hashi2 = hashFunc2()(key);
			size_t hashi3 = hashFunc3()(key);

			return _bit.test(hashi1 % len)
				&& _bit.test(hashi2 % len)
				&& _bit.test(hashi3 % len);
		}
	private:
		const static size_t _X = 4;
		bitset<N* _X> _bit;
	};
}