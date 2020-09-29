#pragma once
using namespace std;

#include <ostream>
#include <vector>
#include <list>
#include <set>

// Measures of sort algorithm operations
struct SortMetrics
{
	int accesses{ 0 };         // Count of array accesses
	int comparisons{ 0 };      // Count of value comparisons
};

// Insert formatted sort metrics into output stream
ostream& operator<<(ostream& os, const SortMetrics& metrics);


// All sort algorithms return `true` if
// successful, or `false` if an error occurred


// Bubble sort algorithm
bool bubble_sort(vector<int>& vec, SortMetrics& metrics);
bool bubble_sort(list<int>& list, SortMetrics& metrics);
bool bubble_sort(set<int>& set, SortMetrics& metrics);

// Insertion sort algorithm
bool insertion_sort(vector<int>& vec, SortMetrics& metrics);
//bool insertion_sort(list<int>& list, SortMetrics& metrics);
bool insertion_sort(set<int>& set, SortMetrics& metrics);

// Merge sort algorithm
bool merge_sort(vector<int>& vec, SortMetrics& metrics);
//bool merge_sort(list<int>& list, SortMetrics& metrics);
bool merge_sort(set<int>& set, SortMetrics& metrics);

//// Quick sort algorithm
bool quicksort(vector<int>& vec, SortMetrics& metrics, int left, int right);
//bool quicksort(list<int>& list, SortMetrics& metrics);
bool quicksort(set<int>& set, SortMetrics& metrics);
