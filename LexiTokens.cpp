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

