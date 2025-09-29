int *arr1 = new int[n];
for (int i = 0; i < n; i++)
{
    arr1[i] = rand(); // random value
}
// yahan arr1 ko sort karo (algo 1)
delete[] arr1;

int *arr2 = new int[n];
for (int i = 0; i < n; i++)
{
    arr2[i] = rand();
}
// yahan arr2 ko sort karo (algo 2)
delete[] arr2;

// same for bubble, insertion
