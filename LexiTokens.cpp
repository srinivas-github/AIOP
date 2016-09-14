#include <cstdio>
#include <cstring>
int main()
{
    char buf[255];
    memset(buf, 0, 255);
    while ((fgets(buf, 255,stdin)) != NULL)
    {
       printf("%s\n", buf);
       char *pch;
        printf("Splitting the string \"%s\" into tokens:\n", buf);
        pch = strtok(buf, " ");
        while (pch != NULL)
        {
            printf("%s\n", pch);
            pch = strtok(NULL, " ");
        }
    }
    return 0;
}


/**
 * Another Sample to get individual words
 */
/* get the first word from the message, seperated by
	 * space character */
	 char* word;
	 word = strtok(message, " ");
         printf("1st word: %s\n", word);
/* get the second word from the message, NULL must be
* used to get tokens from the previous string now */
word = strtok(NULL, " ");
printf("2nd word: %s\n", word);
/* the following loop gets the rest of the words until the
 * end of the message */
while ((word = strtok(NULL, " ")) != NULL)
printf("Next: %s\n", word);
return 0;
