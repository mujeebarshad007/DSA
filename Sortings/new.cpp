#include <iostream>
#include <chrono>
#include "sortings.h"
int main()
{
    int size = 5;
    int arr[size] = {5, 4, 3, 2, 1};
    auto start = std::chrono::high_resolution_clock::now();
    Insertion_Sort(arr, size);
    auto end = std::chrono::high_resolution_clock::now();
    auto t1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    start = std::chrono::high_resolution_clock::now();
    Bubble_Sort(arr, size);
    end = std::chrono::high_resolution_clock::now();
    auto t2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    start = std::chrono::high_resolution_clock::now();
    Right_Selection_Sort(arr, size);
    end = std::chrono::high_resolution_clock::now();
    auto t3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std ::cout << " The Time of Insertion Sort is : " << t1.count() << std::endl;
    std ::cout << " The Time of Bubble Sort is : " << t2.count() << std::endl;
    std ::cout << " The Time of Selction Sort is : " << t3.count() << std::endl;
    return 0;
}