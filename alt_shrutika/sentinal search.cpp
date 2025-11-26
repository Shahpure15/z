#include <iostream>
using namespace std;

// Sentinel Search Function
int sentinelSearch(int a[], int n, int key)
{
    int last = a[n-1];   // Store last element
    a[n-1] = key;        // Replace last with key (Sentinel)
    
    int i = 0;
    while(a[i] != key)
        i++;

    a[n-1] = last;  // Restore last element

    if(i < n-1 || last == key)
        return i;  // Found
    else
        return -1; // Not found
}

int main()
{
    int a[50], n, key;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for(int i=0; i<n; i++)
        cin >> a[i];

    cout << "Enter element to search: ";
    cin >> key;

    int pos = sentinelSearch(a, n, key);

    if(pos == -1)
        cout << "\nElement NOT found.";
    else
        cout << "\nElement found at index: " << pos;

    return 0;
}

