Producer/Consumer Pattern to sort input 

Prerequisites:
-> Ubuntu(Linux)
-> C++

Manifest:
-> main.cpp
-> CMakeLists.txt
-> README.txt

Steps to run:
-> mkdir build
-> cd build
->cmake ..  //(It configures cmake)
-> make   //(compiles)
->./Producerconsumer input output typeofsort(quicksort/mergesort)
ex: ./Producerconsumer input output quicksort (or) ./Producerconsumer input output mergesort

Explaination:
In this project the code was developed firstly to read the data from input file to a vector of vector string. Here four arguements are passed and those are executable, input, outpu and alorithm.
Threads are used in this project to make the program more efficient. so maximum of 4 threads are used which work concurrently and rotate count is used to reuse the threads. for example if there are 4 therads and 12 data items to be processed, 4 threads for on four data items and next these four threads go for another four data items to process whcihc make the total rotate count of 3 for four threads and 12 data items.
Two algorithms are chosen for this program to sort out the data items. User has an option to chose any of the two algorithms by which he wishes to sort the data items. Reasons for chosing these algorithms are discussed in below.

Chosen algorithms (Divide and Conquer):
1)QuickSort
2)MergeSort

Reasons to choose Quicksort:
-> It is based on Divide and Conquer method
-> It is usually faster for less data
-> It has less overhead
-> Easy to combine with cache and internal memory mechanism
-> Easy to implement
-> Efficient average case for space and time

Reasons to choose Merge sort:
-> O(nlogn) worst case asymptotic complexity
-> Great for parallel computing (multi-threading)
-> More stable and and uses less comparisons which may cost high
-> It is useful when we don't have the idea of input data.
->It is based on Divide and Conquer Method



