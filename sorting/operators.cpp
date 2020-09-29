
// ECE 4050 / CSC 5050 - Project 3
// Nathan Lucas

#include "operators.h"

// Insert `vec` into stream `os`
std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec)
{
	os << "vector : { ";
	for (const auto element : vec)
	{
		os << element << " ";
	}
	return os << "}\n";
}

// Insert `list` into stream `os`
std::ostream& operator<<(std::ostream& os, const std::list<int>& list)
{
	os << "list   : { ";
	for (const auto element : list)
	{
		os << element << " ";
	}
	return os << "}\n";
}

// Insert `set` into stream `os`
std::ostream& operator<<(std::ostream& os, const std::set<int>& set)
{
	os << "set    : { ";
	for (const auto element : set)
	{
		os << element << " ";
	}
	return os << "}\n";
}
