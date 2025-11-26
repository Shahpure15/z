#include <iostream>
using namespace std;

// Function to get maximum value in array
int getMax(int a[], int n)
{
    int mx = a[0];
    for(int i=1; i<n; i++)
        if(a[i] > mx)
            mx = a[i];
    return mx;
}

// Counting sort used by Radix sort (sort by digit place)
void countSort(int a[], int n, int exp)
{
    int output[50];
    int count[10];

    for(int i=0; i<10; i++)
        count[i] = 0;

    // Count digit occurrence
    for(int i=0; i<n; i++)
        count[(a[i] / exp) % 10]++;

    // Convert count array to prefix sum
    for(int i=1; i<10; i++)
        count[i] += count[i-1];

    // Build output array
    for(int i=n-1; i>=0; i--)
    {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    // Copy output to original array
    for(int i=0; i<n; i++)
        a[i] = output[i];
}

// Radix Sort
void radixSort(int a[], int n)
{
    int max = getMax(a, n);

    for(int exp = 1; max/exp > 0; exp *= 10)
        countSort(a, n, exp);
}

int main()
{
    int a[50], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
        cin >> a[i];

    radixSort(a, n);

    cout << "\nSorted Array: ";
    for(int i=0; i<n; i++)
        cout << a[i] << " ";

    return 0;
}

