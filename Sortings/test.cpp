#include <iostream>
using namespace std;
int main()
{
    int n = 6;
    int arr[8, 5, 7, 4, 3, 2];
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}