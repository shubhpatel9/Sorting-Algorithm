# Sorting-Algorithm
# In this project, I sort algorithms and data structures as specified in the abstract. My main goals of this project are:
# •	Practice my programming constructs
# •	To implement and compare different sorting methods in different STL containers and determine which operation is the most efficient. This experience will also help me with my 
# future projects as it sheds important knowledge useful in data optimization.
# I used C++ to create the algorithm on Visual Studio 2019. The structure of the algorithm is divided in eight parts: 
# 1.	sort.h: main header functions containing all the function definitions and creates the objects for SortMetrics. These functions are used in sorting.cpp
# 2.	random.h: function declarations which are defined in random.cpp
# 3.	operators.h: contains the stream operators overloads
# 4.	main.cpp: main driver functions which calls the functions from sorting.cpp to execute the algorithm to the console output
# 5.	operators.cpp: inserts the data from the three stl containers into stream os which is used to print the data in main.cpp to show to result of sorting on the console
# 6.	random.cpp: this function is used to create a vector of ‘n’ random elements. These elements are then copied in a list and set stl containers.
# 7.	sort_metrics: creates two objects of metrics to calculate the number of time an element is accessed and the number of time a comparison between two elements takes place when the each of the sorting functions is executed and returns the variable. This is used to compare the efficiency among the four sorting methods that we employ in this project.
# 8.	sorting.cpp: main driver function which contains all the function calls in the order that they are to be executed and displayed on the console for the user. We declare the value of n in this function as well. This can be changed as needed.
