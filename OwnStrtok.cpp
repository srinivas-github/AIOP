#include <cstdio>
#include <cstring>

char* StrToke(char* str, const char* delim)
{
    static char* sp;
    int i = 0;
    int len = strlen(delim);
    if (len == 0)
        printf("No delimters..\n");

    if (!str && !sp)
        return NULL;
    if (str && !sp)
        sp = str;

    char* startPtr = sp;
    while (1)
    {
        for (i = 0; i < len; i++)
	{
	    if (*startPtr == delim[i])
	    {
	        startPtr++;
		break;
	    }
	}
	if (i == len)
	{
	    sp = startPtr;
	    break;
	}
    }

    if (*sp == '\0')
    {
        sp = NULL;
	return sp;
    }

    while (*sp != '\0')
    {
        for (i = 0 ; i < len; i++)
	{
	    if (*sp == delim[i])
	    {
	        *sp = '\0';
	        break;
	    }
	}
	sp++;
	if ( i < len)
	    break;
    }
    return startPtr;
}

int main()
{
    char str[] = "- This, is a simple string.";
    char* pCh;
    printf("Splitting the \"%s\" into tokens\n", str);
    pCh = StrToke(str, " -.,");
    while (pCh != NULL)
    {
        printf("%s\n", pCh);
	pCh = StrToke(NULL,  " -.,");
    }
    return 0;

}
