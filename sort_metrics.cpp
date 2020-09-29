// ECE 4050 / CSC 5050 - Project 3
// Nathan Lucas

#include "sort.h"

std::ostream& operator<<(std::ostream& os, const SortMetrics& metrics)
{
	return os << metrics.accesses << " accesses, "
		<< metrics.comparisons << " comparisons\n";
}
