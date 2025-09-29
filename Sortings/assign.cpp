#include <chrono>
#include <ctime>
#include <fstream>
#include "sortings.h"
int main(int argc, char *argv[])
{
    srand(time(0));
    if (argc < 3)
    {
        std::cout << "Usage: Size of Array, Name Of CSV FILE\n";
    }
    else
    {
        int n;
        n = atoi(argv[1]);              // Taking The size of the array from command line
        std::string filename = argv[2]; // Taking The Name of the CSV from command line

        // Making Arrays ;

        // Implementing RANDOM Array Aprroach
        // Wrong Selection Sort for RANDOM Array
        int *Ran1 = make_Random_Array(n);
        int *arr1 = copy_Array(Ran1, n);
        auto start = std::chrono::high_resolution_clock::now();
        Wrong_Selection_Sort(arr1, n);
        auto end = std::chrono::high_resolution_clock::now();
        auto t1_random = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete[] arr1;
        delete[] Ran1;
        // Right Selection Sort For RANDOM Array
        int *Ran2 = make_Random_Array(n);
        int *arr2 = copy_Array(Ran2, n);
        start = std::chrono::high_resolution_clock::now();
        Right_Selection_Sort(arr2, n);
        end = std::chrono::high_resolution_clock::now();
        auto t2_random = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete[] arr2;
        delete[] Ran2;

        // Insertion Sort For RANDOM Array
        int *Ran3 = make_Random_Array(n);
        int *arr3 = copy_Array(Ran3, n);
        start = std::chrono::high_resolution_clock::now();
        Insertion_Sort(arr3, n);
        end = std::chrono::high_resolution_clock::now();
        auto t3_random = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete[] arr3;
        delete[] Ran3;

        // Bubble Sort For RANDsOM Array
        int *Ran4 = make_Random_Array(n);
        int *arr4 = copy_Array(Ran4, n);
        start = std::chrono::high_resolution_clock::now();
        Bubble_Sort(arr4, n);
        end = std::chrono::high_resolution_clock::now();
        auto t4_random = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete[] arr4;
        delete[] Ran4;

        // Implementing ASCENDING Order Array
        // Wrong Selection Sort for ASCENDING Array
        int *Asc1 = make_Ascending_Array(n);
        int *arr_1 = copy_Array(Asc1, n);
        start = std::chrono::high_resolution_clock::now();
        Wrong_Selection_Sort(arr_1, n);
        end = std::chrono::high_resolution_clock::now();
        auto t1_asc = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete[] arr_1;
        delete[] Asc1;

        // Right Selection Sort For ASCENDING Array
        int *Asc2 = make_Ascending_Array(n);
        int *arr_2 = copy_Array(Asc2, n);
        start = std::chrono::high_resolution_clock::now();
        Right_Selection_Sort(arr_2, n);
        end = std::chrono::high_resolution_clock::now();
        auto t2_asc = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete[] arr_2;
        delete[] Asc2;

        // Insertion Sort For ASCENDING Array
        int *Asc3 = make_Ascending_Array(n);
        int *arr_3 = copy_Array(Asc3, n);
        start = std::chrono::high_resolution_clock::now();
        Insertion_Sort(arr_3, n);
        end = std::chrono::high_resolution_clock::now();
        auto t3_asc = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete[] arr_3;
        delete[] Asc3;

        // Bubble Sort For ASCENDING Array
        int *Asc4 = make_Ascending_Array(n);
        int *arr_4 = copy_Array(Asc4, n);
        start = std::chrono::high_resolution_clock::now();
        Bubble_Sort(arr_4, n);
        end = std::chrono::high_resolution_clock::now();
        auto t4_asc = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete[] arr_4;
        delete[] Asc4;

        // Implementing DESCENDING Order Array
        // Wrong Selection Sort for DESCENDING Array
        int *Des1 = make_Descending_Array(n);
        int *arr_5 = copy_Array(Des1, n);
        start = std::chrono::high_resolution_clock::now();
        Wrong_Selection_Sort(arr_5, n);
        end = std::chrono::high_resolution_clock::now();
        auto t1_des = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete[] arr_5;
        delete[] Des1;

        // Right Selection Sort For DESCENDING Array
        int *Des2 = make_Descending_Array(n);
        int *arr_6 = copy_Array(Des2, n);
        start = std::chrono::high_resolution_clock::now();
        Right_Selection_Sort(arr_6, n);
        end = std::chrono::high_resolution_clock::now();
        auto t2_des = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete[] arr_6;
        delete[] Des2;

        // Insertion Sort For DESCENDING Array
        int *Des3 = make_Descending_Array(n);
        int *arr_7 = copy_Array(Des3, n);
        start = std::chrono::high_resolution_clock::now();
        Insertion_Sort(arr_7, n);
        end = std::chrono::high_resolution_clock::now();
        auto t3_des = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete[] arr_7;
        delete[] Des3;

        // Bubble Sort For DESCENDING Array
        int *Des4 = make_Descending_Array(n);
        int *arr_8 = copy_Array(Des4, n);
        start = std::chrono::high_resolution_clock::now();
        Bubble_Sort(arr_8, n);
        end = std::chrono::high_resolution_clock::now();
        auto t4_des = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete[] Des4;

        // delete[] Ran;
        // delete[] Asc;
        // delete[] Des;

        std::ofstream file;
        file.open(filename, std::ios::app);
        if (!file)
        {
            std::cout << "file not opened";
        }
        else
        {

            file << "Algorithm,Array Size,Array Type,Average Time Taken (microseconds)\n";
            // Wrong Selection Sort
            file << "Wrong Selection Sorting," << n << ",RAND," << t1_random.count() << "\n";
            file << "Wrong Selection Sorting," << n << ",ASC," << t1_asc.count() << "\n";
            file << "Wrong Selection Sorting," << n << ",DESC," << t1_des.count() << "\n";

            // Right Selection Sort
            file << "Right Selection Sorting," << n << ",RAND," << t2_random.count() << "\n";
            file << "Right Selection Sorting," << n << ",ASC," << t2_asc.count() << "\n";
            file << "Right Selection Sorting," << n << ",DESC," << t2_des.count() << "\n";

            // Insertion Sort
            file << "Insertion Sorting," << n << ",RAND," << t3_random.count() << "\n";
            file << "Insertion Sorting," << n << ",ASC," << t3_asc.count() << "\n";
            file << "Insertion Sorting," << n << ",DESC," << t3_des.count() << "\n";

            // Bubble Sort
            file << "Bubble Sorting," << n << ",RAND," << t4_random.count() << "\n";
            file << "Bubble Sorting," << n << ",ASC," << t4_asc.count() << "\n";
            file << "Bubble Sorting," << n << ",DESC," << t4_des.count() << "\n";

            std::cout << "Results are successfully Written. Good Luck . " << filename << "\n";
            file.close();
        }
        return 0;
    }
}