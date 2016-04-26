/**
 * Given two strings str1 and str2, find if str1 is a subsequence of str2.
 * A subsequence is a sequence that can be derived from another sequence by
 * deleting some elements without changing the order of the remaining elements.
 *
 * Examples:
 * Input: str1 = "AXY", str2 = "ADXCPY"
 * Output: True (str1 is a subsequence of str2)
 *
 * Input: str1 = "AXY", str2 = "YADXCP"
 * Output: False (str1 is not a subsequence of str2)
 *
 * Input: str1 = "gksrek", str2 = "geeksforgeeks"
 * Output: True (str1 is a subsequence of str2)
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>


bool isSubseq(char str1[], char str2[], int m, int n)
{
    int j = 0;
    for(int i = 0; i < n && j < m; i++)
        if (str1[j] == str2[i]
	    j++;

    return (j == m);
}

bool isSubseqRecu(char str1[], char str2[], int m, int n)
{
    if (m == 0) return true;
    if (n == 0) return false;

    if (str1[m-1] == str2[n-1])
        return isSubseqRecu(str1, str2, m-1, n-1);
    return isSubseqRecu(str1, str2, m, n-1);
}

int main()
{
    char str1[] = "chnk";
    char str2[] = "chaloniklo";

    int m = strlen(str1);
    int n = strlen(str2);

    isSubseq(str1, str2, m,n) ? printf("Subsequence\n"):printf("Not subsequnce\n");
    return 0;
}
