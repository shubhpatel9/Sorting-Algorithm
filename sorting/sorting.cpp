//Shubh Patel
//Function for sorting

#include <list>
#include <set>
#include <iostream>
#include <vector>
#include "sort.h"
using namespace std;

//Bubble sort with vector
bool bubble_sort(vector<int>& vec, SortMetrics& metrics) {
	metrics.accesses = 0;
	metrics.comparisons = 0;
	//output before to compare

	bool swap_ = true;
	while (swap_) {
		swap_ = false; //loop active until all the elements are sorted in the vector
		for (size_t i = 0; i < (vec.size() - 1); i++) {
			//vec accessed twice, vec[i] and vec[i+1] and both of them compared with each other once
			metrics.accesses += 2; //if
			metrics.comparisons++; //if

			if (vec[i] > vec[i + 1]) {
				metrics.accesses += 3; 
					//vec[i] being accessed two extra times and vec[i+1] one extra time
				//swap
				vec[i] += vec[i + 1];
				vec[i + 1] = vec[i] - vec[i + 1];
				vec[i] -= vec[i + 1];

				swap_ = true;
			}
		}
	}
	return (!swap_);
}

//Bubble sort with list
bool bubble_sort(list<int>& list, SortMetrics& metrics) {
	metrics.accesses = 0;
	metrics.comparisons = 0;

	for (auto i = begin(list); i != end(list); i++)
	{
		auto key = begin(list); //setting the new first element of the list
		metrics.accesses++;

		for (auto itr = key; itr != end(list); itr++)
		{
			metrics.accesses += 2; //i and itr
			metrics.comparisons++ ; 
			if (*i < *(itr))
			{
				int temp = *i;
				*i = *itr;
				*itr = temp;
			}
		}
	}
	return 0;
}

//Bubble sort with set
bool bubble_sort(set<int>& set, SortMetrics& metrics) {
	metrics.accesses = 0;
	metrics.comparisons = 0;
	return 0;
}

//insertion sort with vector
bool insertion_sort(vector<int>& vec, SortMetrics& metrics) {
	metrics.accesses = 0;
	metrics.comparisons = 0;

	for (size_t j = 1; j < vec.size(); j++) {
		metrics.accesses++; //vec[j]
		int key = vec[j];
		int i = j - 1;

		metrics.accesses += 2; //vec[i] and vec[i+1]
		metrics.comparisons++;//vec[i] and key(=vec[j])

		while (i >= 0 && vec[i] > key) {
			vec[i + 1] = vec[i];
			i--;
		}
		metrics.accesses++; //vec[i+1]
		vec[i + 1] = key;
	}

	return 1;
}

//insertion sort with list
//helper function to sort the list: mergeSort
/*bool quicksort(list<int>& list, SortMetrics& metrics)
	{
		call mergeSort to take its first element

		  for j <- 2 to list[size]
        key <- list[j]
         Insert list[j] into the sorted sequence list[1...j - 1].
        i <- j - 1
        while i > 0
		list[i] > key
          do A[i + 1] <- A[i]
              i <- i - 1
        list[i + 1] <- key
*/

//insertion sort with set
bool insertion_sort(set<int>& set, SortMetrics& metrics) {
	metrics.accesses = 0;
	metrics.comparisons = 0;
	return 0;
}

//merge sort with vector
//helper function
vector<int> merge(vector<int> l, vector<int> r,SortMetrics& metrics) {
	vector<int> re;

	//using push_back to push elements into the vector from the back. The contents of the vector is placed after the 'current' last element in the loop

	while (l.size() > 0 || r.size() > 0) {
		if (l.size() > 0 && r.size() > 0) {
			if (l.at(0) <= r.at(0)) {
				metrics.comparisons++;
				metrics.accesses += 2; //accessing and comparing the first elements in both halves
				re.push_back(l.at(0)); //organizing the vector behind the smallest element in the portion
				l.erase(l.begin()); //resseting the vector to use push_back again
			}
			else {
				metrics.accesses++; //accessing the element in r
				re.push_back(r.at(0));
				r.erase(r.begin());
			}
		}
		else if (r.size() > 0) {
			for (int i = 0; i < r.size(); i++) {
				metrics.accesses++; //accessing the vector element of r at i
				re.push_back(r[i]);
			}
			break;
		}
		else if (l.size() > 0) {
			for (int i = 0; i < l.size(); i++) {
				metrics.accesses++; //accessing the vector element of l at i
				re.push_back(l[i]);
			}
			break;
		}
	}
	return re;
}
//sorting function
vector<int> mergeSort(vector<int> vec, SortMetrics& metrics) {
	vector<int> l, r, re;

	if (vec.size() < 2)
		return vec; //returning if the vector is of 2 elements

	int mid = (vec.size() + 1) / 2;//finding the middle element of the vector

	for (int i = 0; i < mid; i++) {
		metrics.accesses++;
		l.push_back(vec.at(i)); //if the element at i is smaller than mid, push_back
	}

	for (int i = mid; i < vec.size(); i++) {
		metrics.accesses++;
		r.push_back(vec.at(i));
	}

	//sorting the vector portions recursively by reapplying the mergesort
	l = mergeSort(l, metrics); 
	r = mergeSort(r, metrics);
	re = merge(l, r, metrics);

	return re;
}

bool merge_sort(vector<int>& vec, SortMetrics& metrics) {
	vec = mergeSort(vec, metrics); //recursively sorting the vector by calling the sorting function which uses the helper function to sort the vector

	return 1;
}

//merge sort with list

//merge sort with set
bool merge_sort(set<int>& set, SortMetrics& metrics){
	metrics.accesses = 0;
	metrics.comparisons = 0;
	return 0;
}

//quicksort with vectors
bool quicksort(vector<int>& vec, SortMetrics& metrics, int left, int right) {
	metrics.accesses = 0;
	metrics.comparisons = 0;

	int i, j, mid, pivot;
	i = left; // left partition of the vector
	j = right; //right partition of the vector
	mid = left + (right - left) / 2; 
	//pivot (chosen by using the middle element of the vector) 
	pivot = vec[mid];
	metrics.accesses++; //acccessing the vector element at mid

	while (j > left || i < right) {
		metrics.comparisons += 2; //vector elements at i and j being compared with the pivot
		
		while (vec[i] < pivot) {
			metrics.accesses++;
			i++; //incrementing i to find the element larger than the pivot
		}
		while (vec[j] > pivot) {
			metrics.accesses++;
			j--; //decrementing j to find the element smaller than the pivot
		} 

		if (i <= j) {
			swap(i, j); //with the two elements found from the while loops above, if i side elements is smaller than the j side elements, swtich. if not, no action taken as they are already in the right order
			i++;
			j--;
		}
		else {
			// right side is larger
			if (i < right)
				quicksort(vec, metrics, i, right);
			// left is larger
			if (j > left)
				quicksort(vec, metrics, left, j);
			return 1;
		}
	}
	return 1;
}

//quicksort with list

//quicksort with set
bool quicksort(set<int>& set, SortMetrics& metrics) {
	metrics.accesses = 0;
	metrics.comparisons = 0;
	return 0;
}