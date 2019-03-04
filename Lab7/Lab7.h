#pragma once

#include <iostream>
#include <vector>
#include <map>
namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;
		int len = keys.size() < values.size() ? static_cast<int>(keys.size()) : static_cast<int>(values.size());
		for (int index = 0; index < len; index++)
		{
			m.insert(std::make_pair(keys[index], values[index]));
		}
		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		typename std::map<K, V>::const_iterator it = m.begin();
		std::vector<K> v;
		while (it != m.end())
		{
			v.push_back(it->first);
			it++;
		}
		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		typename std::map<K, V>::const_iterator it = m.begin();
		std::vector<V> v;
		while (it != m.end())
		{
			v.push_back(it->second);
			it++;
		}
		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		for (int index = v.size() - 1; index >= 0; index--)
		{
			rv.push_back(v[index]);
		}
		return rv;
	}

}

template <typename T>
std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
{
	std::vector<T> combined;
	for (int index = 0; index < static_cast<int>(v1.size()); index++)
	{
		combined.push_back(v1[index]);
	}
	for (int index = 0; index < static_cast<int>(v2.size()); index++)
	{
		int index2 = 0;
		for (index2; index2 < static_cast<int>(combined.size()); index2++)
		{
			if (combined[index2] == v2[index])
				break;
		}
		if (index2 == static_cast<int>(combined.size()))
			combined.push_back(v2[index]);
	}
	return combined;
}

template <typename K, class V>
std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
{
	std::map<K, V> combined;
	typename std::map<K, V>::const_iterator it = m1.begin();

	while (it != m1.end())
	{
		combined.insert(std::make_pair(it->first, it->second));
		it++;
	}
	typename std::map<K, V>::const_iterator it2 = m2.begin();
	while (it2 != m2.end())
	{
		combined.insert(std::make_pair(it2->first, it2->second));
		it2++;
	}
	return combined;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	int len = static_cast<int>(v.size() - 1);
	for (int index = 0; index < len; index++)
	{
		os << v[index] << ", ";
	}
	os << v[len];
	return os;
}

template <typename K, class V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
{
	typename std::map<K, V>::const_iterator it = m.begin();
	while (it != m.end())
	{
		os << "{ " << it->first << ", " << it->second << " }\n";
		it++;
	}
	return os;
}