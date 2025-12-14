#pragma
void Bubble_Sort(int arr[], const int &n)
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

void Wrong_Selection_Sort(int arr[], const int &n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (arr[i] > arr[j])
                std::swap(arr[i], arr[j]);
        }
    }
}
void Right_Selection_Sort(int arr[], const int &n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min_i = i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (arr[min_i] > arr[j])
            {
                min_i = j;
            }
        }
        if (i != min_i)
        {

            std::swap(arr[i], arr[min_i]);
        }
    }
}
void Insertion_Sort(int arr[], const int &n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int x = arr[i];
        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

int *make_Random_Array(int n)
{
    int *R_arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        R_arr[i] = rand() % 100000 + 1;
    }
    return R_arr;
}
int *make_Ascending_Array(int n)
{
    int *array = new int[n];

    for (int i = 0; i < n; i++)
    {
        array[i] = i + 1;
    }
    return array;
}
int *make_Descending_Array(int n)
{
    int *array = new int[n];

    for (int i = 0; i < n; i++)
    {
        array[i] = n - i;
    }
    return array;
}
