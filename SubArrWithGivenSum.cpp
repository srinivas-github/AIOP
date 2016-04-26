/**
 * Given an unsorted array of nonnegative integers, find a continous subarray which adds to a given number.
 * Examples:
 * Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
 * Ouptut: Sum found between indexes 2 and 4
 *
 * Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
 * Ouptut: Sum found between indexes 1 and 4
 *
 * Input: arr[] = {1, 4}, sum = 0
 * Output: No subarray found
 */
#include <cstdio>
#include <cstdlib>

int findSubArr(int arr[], int n, int sum)
{
    int curr_sum, i, j;
    for (i = 0; i < n; i++)
    {
        curr_sum = arr[i];
	for (j = i+1; j <= n; j++)
	{
	    if (curr_sum == sum)
            {
                printf("Found at indexex from %d to %d\n", i, j-1);
		return 0;
            }
            if (curr_sum > sum || j == n)
                break;
            curr_sum = curr_sum+arr[j];
        }
    }
    printf("No Subarray Found\n\n");
    return 1;
}

int findSubArrEff(int arr[], int n , int sum)
{
    int curr_sum = arr[0], start=0, i;
    for (i = 1; i <=n; i++)
    {
        while (curr_sum > sum && start < i-1)
	{
	    curr_sum = curr_sum - arr[start];
	    start++;
	}
	if (curr_sum == sum)
	{
	    printf("Subarray found at from index %d to %d\n", start, i-1);
	    return 1;
	}
	if ( i<n)
	    curr_sum = curr_sum + arr[i];

    }
    printf("No Subarray found\n");
    return 0;

}

int main()
{
    int arr[] = {1,4,20,3,10,5};
    int sum = 33;
    int n = sizeof(arr)/sizeof(arr[0]);
    findSubArr(arr, n, sum);
    findSubArrEff(arr, n, sum);
    return 0;
}
