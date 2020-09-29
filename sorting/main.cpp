//Shubh Patel
//Main driver function
#include <iostream>
#include <ostream>
#include <vector>
#include <list>
#include <set>
#include "random.h"
#include "sort.h"
#include "operators.h"
using namespace std;

int main()
{
    int n = 10;
    auto vect = random_vector(n);
    auto list = vector_to_list(vect);
    auto set = vector_to_set(vect);

    cout << "\nn = " << n << "\n";
    cout << "\nBefore sort: " << vect << "\n";

    SortMetrics metrics;

    //bubble sort
    bubble_sort(vect, metrics);
    cout << "----------Bubble Sort----------\n";
    cout << "After sorting with vector: " << vect << "\n";
    cout << metrics << "\n";

    bubble_sort(list, metrics);
    cout << "After sorting with list: " << list << "\n";
    cout << metrics << "\n";


    bubble_sort(set, metrics);
    cout << "After sorting with set: " << set << "\n";
    cout << metrics << "\n";

    //insertion sort
    cout << "----------Insertion Sort----------\n";
    insertion_sort(vect, metrics);
    cout << "After sorting with vector: " << vect << "\n";
    cout << metrics << "\n";

    //insertion_sort(list, metrics); //not correct
    //cout << "After sorting with list: " << list << "\n";
    //cout << metrics << "\n";

    insertion_sort(set, metrics);
    cout << "After sorting with set: " << set << "\n";
    cout << metrics << "\n";

    //merge sort
    cout << "----------Merge Sort----------\n";
    merge_sort(vect, metrics);
    cout << "After sorting with vector: " << vect << "\n";
    cout << metrics << "\n";

    merge_sort(set, metrics);
    cout << "After sorting with set: " << set << "\n";
    cout << metrics << "\n";

    //quicksort
    cout << "----------Quicksort----------\n";
    quicksort(vect, metrics, 0, n - 1);
    cout << "After sorting with vector: " << vect << "\n";
    cout << metrics << "\n";

    quicksort(set, metrics);
    cout << "After sorting with set: " << set << "\n";
    cout << metrics << "\n";


    return 0;
}

