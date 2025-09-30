
#include <iostream>
void Bubble_Sort(int arr[], const int &size)
{
    int flag;
    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < size - 1 - i; j++)
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

void Wrong_Selection_Sort(int arr[], const int &size)
{
    for (int i = 0; i <= size - 2; i++)
    {
        for (int j = i + 1; j <= size - 1; j++)
        {
            if (arr[j]>arr[j+1])
        }
    }
}