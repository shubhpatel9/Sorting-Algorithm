#pragma once
#include <vector>       // std::vector
#include <list>         // std::list
#include <set>          // std::set


// Generate a vector `n` random numbers
std::vector<int> random_vector(const std::size_t n);

// Convert vector `v` into a list
std::list<int> vector_to_list(const std::vector<int>& v);

// Convert vector `v` into a set
std::set<int> vector_to_set(const std::vector<int>& v);

