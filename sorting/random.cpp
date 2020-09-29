#include "random.h"
#include <algorithm>    // std::shuffle
#include <random>       // std::random_device, std::mt19937

std::vector<int> random_vector(const std::size_t n)
{
	std::vector<int> v;
	for (int i = 0; i != n; ++i)
	{
		v.push_back(i);
	}
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(v.begin(), v.end(), g);
	return v;
}

std::list<int> vector_to_list(const std::vector<int>& v)
{
	return std::list<int>(v.begin(), v.end());
}

std::set<int> vector_to_set(const std::vector<int>& v)
{
	return std::set<int>(v.begin(), v.end());
}