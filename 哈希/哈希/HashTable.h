#pragma once
#include<map>
#include<vector>
using namespace std;

enum Nature{
	EMPTY,
	EXIST,
	DELETE
};

template<class T, class K>
class hashTable {
	
	struct elem {
		Nature m_nature;
		pair<T, K> m_data;
		elem(Nature nature = EMPTY, const T& key = T(), const K& val = K())
			:m_nature(nature)
			,m_data(key, val)
		{

		}
	};

public:
	vector<elem> _data;
	size_t _size;
	size_t  count;
public:
	hashTable(size_t Size = 10)
		:_size(Size)
		,count(0)
	{
		_data.resize(_size);
	}

bool insert(const pair<T, K>& val)
	{
		size_t key = hashfun(val.first);
		
		if (_data[key].m_data.first == val.first)
		{
			return false;
		}

		while (_data[key].m_nature == EXIST)
		{
			key++;
			if (key == _data.size())
			{
				key = 0;
			}
		}

		count++;
		_data[key].m_data = val;
		_data[key].m_nature = EXIST;
		return true;
	}

		int Find(const T key)
		{
			size_t Key = hashfun(key);
			for (int i = 0; i < _size; i++)
			{
				if (_data[Key].m_nature == EXIST && key == _data[Key].m_data.first)
				{
					return Key;
				}
				Key++;
				if (Key == _size)
				{
					Key = 0;
				}
			}
			return -1;
		}

	bool erase(const T& key)
	{
		size_t Key = hashfun(key);
		for (int i = 0; i < _size; i++)
		{
			if (_data[Key].m_nature == EXIST && key == _data[Key].m_data.first)
			{
				_data[Key].m_nature = DELETE;
				count--;
				return true;
			}
			Key++;
			if (Key == _size)
			{
				Key = 0;
			}
		}
		return false;
	}

	size_t hashfun(const T& val)
	{
		size_t key;
		key = val % _size;
		return key;
	}
};