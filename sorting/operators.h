// ECE 4050 / CSC 5050 - Project 3
// Nathan Lucas

/*  Stream insertion operator overloads

    Example usage:

        int n = 10;
        auto vec = random_vector(n);    // Create vector of unsorted data
        std::cout << vec << "\n";       // Output unsorted data to console
        SortMetrics metrics;
        bubble_sort(vec, metrics);      // Sort data using bubble sort
        std::cout << vec << "\n";       // Output sorted data to console
*/
#pragma once

#include <ostream>      // std::ostream
#include <vector>       // std::vector
#include <list>         // std::list
#include <set>          // std::set

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec);
std::ostream& operator<<(std::ostream& os, const std::list<int>& list);
std::ostream& operator<<(std::ostream& os, const std::set<int>& set);

