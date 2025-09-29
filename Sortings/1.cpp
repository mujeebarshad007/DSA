#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>   // time

int main()
{
    int n = 20;
    int arr_A[20];

    srand(time(0)); // random seed lagana zaroori

    for (int i = 0; i < n; i++)
    {
        arr_A[i] = rand() % 100 + 1; // 1 se 100 ke beech values
    }

    std::cout << "Random Array: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr_A[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
