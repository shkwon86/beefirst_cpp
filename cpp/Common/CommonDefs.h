#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <list>
#include <random>
#include "Singleton.h"

/**
* 공용 기능 클래스
*/
class CommonUtils : public Singleton<CommonUtils>
{
	friend Singleton;
	CommonUtils();

public :

	template<class T>
	static bool GetRandom(const T& min, const T& max, __out T& result);

	template<class T>
	static bool GetRandoms(const T& min, const T& max, const int& genCount, __out std::vector<T>& result);

private :

	static std::random_device RandomDevice;
	static std::mt19937 RandomGen;
};

template<class T>
inline bool CommonUtils::GetRandom(const T& min, const T& max, __out T& result)
{
	if (min >= max)
		return false;

	std::uniform_int_distribution<T> distr(min, max);
	result = distr(RandomGen);

	return true;
}

template<class T>
inline bool CommonUtils::GetRandoms(const T& min, const T& max, const int& genCount, __out std::vector<T>& result)
{
	if (min >= max || genCount <= 0)
		return false;

	std::uniform_int_distribution<T> distr(min, max);

	result.reserve(genCount);
	for (int i = 0; i < genCount; ++i)
	{
		result.emplace_back(distr(RandomGen));
	}

	return true;
}
