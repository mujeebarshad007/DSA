#include <iostream>
#include <chrono>
void Bubble_Sort(int arr[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

int main()
{
    int arr[1000];
    int arr1[1000];
    for (int i = 0; i < 1000; i++)
    {
        arr[i] = i;
        arr1[i] = i;
    }

    auto start = std ::chrono::steady_clock::now(); // start
    Bubble_Sort(arr, 1000);
    auto end = std::chrono::steady_clock::now(); // end;
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << " The Time Taken With Flag is " << duration.count() << "ms" << std::endl;

    return 0;
}