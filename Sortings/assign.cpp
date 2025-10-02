#include <iostream>
#include <chrono>
#include <ctime> //Header file which gives access to time and date functions
#include <fstream>
#include "sortings.h"
int main(int argc, char *argv[])
{
    srand(time(0));
    if (argc < 3)
    {
        std::cout << "Usage: Size of Array,   Name Of CSV FILE\n";
    }
    else
    {
        int n;
        n = atoi(argv[1]);                  // Taking The size of the array from command line
        std::string CSV_FILENAME = argv[2]; // Taking The Name of the CSV from command line

        // Making Arrays ;
        // Using Array Approach
        // Implementing RANDOM Array Aprroach
        // Wrong Selection Sort for RANDOM Array
        long long int time1 = 0;
        for (int i = 0; i < 10; i++)
        {
            int *Ran1 = make_Random_Array(n);
            auto start = std::chrono::high_resolution_clock::now();
            Wrong_Selection_Sort(Ran1, n);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); // Auto Duration means let compiler Decide what type of duration is
            time1 += duration.count();
            delete[] Ran1;
        }
        auto avg1 = time1 / 10;

        // Right Selection Sort For RANDOM Array
        long long int time2 = 0;
        for (int i = 0; i < 10; i++)
        {
            int *Ran2 = make_Random_Array(n);
            auto start = std::chrono::high_resolution_clock::now();
            Right_Selection_Sort(Ran2, n);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            time2 += duration.count();
            delete[] Ran2;
        }
        auto avg2 = time2 / 10;
        // Insertion Sort For RANDOM Array

        long long int time3 = 0;
        for (int i = 0; i < 10; i++)
        {
            int *Ran3 = make_Random_Array(n);
            auto start = std::chrono::high_resolution_clock::now();
            Insertion_Sort(Ran3, n);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            time3 += duration.count();
            delete[] Ran3;
        }
        auto avg3 = time3 / 10;
        // Bubble Sort For RANDOM Array
        long long int time4 = 0;
        for (int i = 0; i < 10; i++)
        {
            int *Ran4 = make_Random_Array(n);
            auto start = std::chrono::high_resolution_clock::now();
            Bubble_Sort(Ran4, n);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            time4 += duration.count();
            delete[] Ran4;
        }
        auto avg4 = time4 / 10;
        // Implementing ASCENDING Order Array
        // Wrong Selection Sort for ASCENDING Array
        long long int time5 = 0;
        for (int i = 0; i < 10; i++)
        {
            int *Asc1 = make_Ascending_Array(n);
            auto start = std::chrono::high_resolution_clock::now();
            Wrong_Selection_Sort(Asc1, n);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            time5 += duration.count();
            delete[] Asc1;
        }
        auto avg5 = time5 / 10;
        // Right Selection Sort For ASCENDING Array
        long long int time6 = 0;
        for (int i = 0; i < 10; i++)
        {
            int *Asc2 = make_Ascending_Array(n);
            auto start = std::chrono::high_resolution_clock::now();
            Right_Selection_Sort(Asc2, n);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            time6 += duration.count();
            delete[] Asc2;
        }
        auto avg6 = time6 / 10;
        // Insertion Sort For ASCENDING Array
        long long int time7 = 0;
        for (int i = 0; i < 10; i++)
        {
            int *Asc3 = make_Ascending_Array(n);
            auto start = std::chrono::high_resolution_clock::now();
            Insertion_Sort(Asc3, n);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            time7 += duration.count();
            delete[] Asc3;
        }
        auto avg7 = time7 / 10;
        // Bubble Sort For ASCENDING Array

        long long int time8 = 0;
        for (int i = 0; i < 10; i++)
        {
            int *Asc4 = make_Ascending_Array(n);
            auto start = std::chrono::high_resolution_clock::now();
            Bubble_Sort(Asc4, n);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            time8 += duration.count();
            delete[] Asc4;
        }
        auto avg8 = time8 / 10;
        // Implementing DESCENDING Order Array
        // Wrong Selection Sort for DESCENDING Array
        long long int time9 = 0;
        for (int i = 0; i < 10; i++)
        {
            int *Des1 = make_Descending_Array(n);
            auto start = std::chrono::high_resolution_clock::now();
            Wrong_Selection_Sort(Des1, n);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            time9 += duration.count();
            delete[] Des1;
        }
        auto avg9 = time9 / 10;
        // Right Selection Sort For DESCENDING Array
        long long int time10 = 0;
        for (int i = 0; i < 10; i++)
        {
            int *Des2 = make_Descending_Array(n);
            auto start = std::chrono::high_resolution_clock::now();
            Right_Selection_Sort(Des2, n);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            time10 += duration.count();
            delete[] Des2;
        }
        auto avg10 = time10 / 10;
        // Insertion Sort For DESCENDING Array
        long long int time11 = 0;
        for (int i = 0; i < 10; i++)
        {
            int *Des3 = make_Descending_Array(n);
            auto start = std::chrono::high_resolution_clock::now();
            Insertion_Sort(Des3, n);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            time11 += duration.count();
            delete[] Des3;
        }
        auto avg11 = time11 / 10;
        // Bubble Sort For DESCENDING Array
        long long int time12 = 0;
        for (int i = 0; i < 10; i++)
        {
            int *Des4 = make_Descending_Array(n);
            auto start = std::chrono::high_resolution_clock::now();
            Bubble_Sort(Des4, n);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            time12 += duration.count();
            delete[] Des4;
        }
        auto avg12 = time12 / 10;

        // The Writing Section Starts From Here

        std::ofstream file;
        file.open(CSV_FILENAME, std::ios::app); // Appending If New Data is added
        if (!file)
        {
            std::cout << "file not opened";
        }
        else
        {

            file << "Algorithm,Size, Type,Average Time Taken (microseconds)\n";

            // Wrong Selection Sort Data
            file << "Wrong Selection Sorting," << n << ",RAND," << avg1 << "\n";
            file << "Wrong Selection Sorting," << n << ",ASC," << avg5 << "\n";
            file << "Wrong Selection Sorting," << n << ",DESC," << avg9 << "\n";

            // Right Selection Sort Data
            file << "Right Selection Sorting," << n << ",RAND," << avg2 << "\n";
            file << "Right Selection Sorting," << n << ",ASC," << avg6 << "\n";
            file << "Right Selection Sorting," << n << ",DESC," << avg10 << "\n";

            // Insertion Sort Data
            file << "Insertion Sorting," << n << ",RAND," << avg3 << "\n";
            file << "Insertion Sorting," << n << ",ASC," << avg7 << "\n";
            file << "Insertion Sorting," << n << ",DESC," << avg11 << "\n";

            // Bubble Sort Data
            file << "Bubble Sorting," << n << ",RAND," << avg4 << "\n";
            file << "Bubble Sorting," << n << ",ASC," << avg8 << "\n";
            file << "Bubble Sorting," << n << ",DESC," << avg12 << "\n";

            std::cout << "Results are successfully Written. Good Luck . " << "\n";
            file.close();
        }
        return 0;
    }
}