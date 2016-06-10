/**
 * Given an array of integers which is initially increasing and then decreasing, find the maximum value in the array.
 * Examples:
 * Input: arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}
 * Output: 500
 * Input: arr[] = {1, 3, 50, 10, 9, 7, 6}
 * Output: 50
 * Corner case (No decreasing part)
 * Input: arr[] = {10, 20, 30, 40, 50}
 * Output: 50
 * Corner case (No increasing part)
 * Input: arr[] = {120, 100, 80, 20, 0}
 * Output: 120
 */


#include <cstdio>

int findMax(int arr[], nt low, int high)
{
    if (low == high)
        return arr[low];

    if ( (high == low+1) && (arr[low] >= arr[high]))
        return arr[low];

    if ( (high == low+1) && (arr[low] < arr[high]))
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

    int arr2[] = {120, 100, 80, 20, 0};
    int max1 = findMax(arr2, 0, sizeof(arr2)/sizeof(arr2[0]));
    printf("Max element; %d\n", max1);

    return 0;
}
