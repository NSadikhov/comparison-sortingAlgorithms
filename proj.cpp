#include <iostream>
#include <chrono>
#include <algorithm>
//#include <vector>
#include <cassert>
#include <random>
#include <fstream>
#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"
#include "util.h"

using namespace std;

constexpr int step = 100;
constexpr int maxlen = 10000;
constexpr int times = 100;

chrono::nanoseconds
timeit(int *original, int *arr, int len, void what(int*, int))
{
    copy(original, original + len, arr);

    auto begin = chrono::steady_clock::now();
    what(arr, len);
    auto end = chrono::steady_clock::now();

    assert(is_sorted(arr, arr + len));

    chrono::nanoseconds total(end - begin);
    return total;
}

int main()
{
    ofstream file("results.csv");

    cout << "ArrSize,MergeSort,HeapSort,QuickSort,MergeCaseSorted,HeapCaseSorted,QuickCaseSorted" << endl;
    file << "ArrSize,MergeSort,HeapSort,QuickSort,MergeCaseSorted,HeapCaseSorted,QuickCaseSorted" << endl;

    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

    for(int len = step; len < maxlen; len += step)
    {

        chrono::nanoseconds mergeS(0);
        chrono::nanoseconds heapS(0);
        chrono::nanoseconds quickS(0);

        chrono::nanoseconds mergeS_Sorted(0);
        chrono::nanoseconds heapS_Sorted(0);
        chrono::nanoseconds quickS_Sorted(0);

        int *original = new int[len];
        for (int i = 0; i < len; i++)
        {
            original[i] = i;
        }

        int *arr = new int[len];
        int *sorted = new int[len];

        for(int t = 0; t < times; ++t)
        {
            shuffle(original, original + len, gen);

            mergeS += timeit(original, arr, len, &merge_sort);
            heapS += timeit(original, arr, len, &heap_sort);
            quickS += timeit(original, arr, len, &quick_sort);

            mergeS_Sorted += timeit(arr, sorted, len, &merge_sort);
            heapS_Sorted += timeit(arr, sorted, len, &heap_sort);
            quickS_Sorted += timeit(arr, sorted, len, &quick_sort);
        }

        cout << len << "," << mergeS.count() / times << "," << heapS.count() / times << "," << quickS.count() / times << "," <<
        mergeS_Sorted.count() / times << "," << heapS_Sorted.count() / times << "," << quickS_Sorted.count() / times << endl;
        file << len << "," << mergeS.count() / times << "," << heapS.count() / times << "," << quickS.count() / times << "," <<
        mergeS_Sorted.count() / times << "," << heapS_Sorted.count() / times << "," << quickS_Sorted.count() / times << endl;

        // Print
        // printArr(original, len);
        // printArr(arr, len);

        delete [] arr;
        delete [] sorted;
        delete [] original;
    }
    file.close();
}
