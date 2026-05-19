#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(char result[], int drops)
{
    char texto[25];
    sprintf(texto, "%d", drops);

    if (drops % 3 == 0)
    {
        strcat(result, "Pling");
    }
    if (drops % 5 == 0)
    {
        strcat(result, "Plang");
    }
    if (drops % 7 == 0)
    {
        strcat(result, "Plong");
    }
    
    if ( (drops % 3 != 0) &&  (drops % 5 != 0) && (drops % 7 != 0) )
    {
        char sd[25];
        sprintf(sd, "%d", drops);
        strcat(result, sd);
    }
}

int main()
{

    char actual[100] = {0};
    convert(actual, 34);
    printf("%s\n", actual);

    return 0;
}