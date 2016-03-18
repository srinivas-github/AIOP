#include <cstdio>

int findMax(int arr[], nt low, int high)
{
    if (low == high)
        return arr[low];

    if ( (high == low+1) && (arr[low] >= arr[high]))
        return arr[low];

    if ( (high == low+1) && (Arr[low] < arr[high]))
        return arr[high];

    int mid = (low + high)/2;

    if (arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1])
        return arr[mid];
    if (arr[mid] > arr[mid+1] && arr[mid] < arr[mid-1])
        return findMax(arr, low, mid-1);
    else
        return findMax(arr, mid+1, high);
}

int main()
{
    int arr[] = {2,4,6,8,9,10,12,14,16,14,12,10,8,6};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int max = findMax(arr, 0, sz);
    printf("Max Element: %d\n", max);

    return 0;
}
