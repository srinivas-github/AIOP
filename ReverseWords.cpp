/**
 * Input:  I like this program very much
 * Output: much very program this like I
 * @Algorithm:
 * 1. Reverse the words :
 *    I like this program very much ->
 *    I ekil siht margorp yrev hcum
 * 2. Reverse the reverse the whole string
 *    I ekil siht margorp yrev hcum ->
 *    much very program this like I
 */

#include <cstdio>

void reverse(char* begin, char* end)
{
    char temp;
    while ( begin < end)
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

void reverseWords(char* s)
{
    char* word_begin = s;
    char* temp  = s;

    while ( *temp)
    {
        temp++;
        if (*temp == '\0')
        {
            reverse(word_begin, temp-1);
        }
        else if (*temp == ' ')
        {
            reverse(word_begin, temp-1);
            word_begin = temp+1;
        }
    }

    reverse(s, temp-1);
}

int main()
{
    char s[] = "I like this program very much";
    reverseWords(s);
    printf("%s \n", s);
    return 0;
}

