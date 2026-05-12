
#include <stdio.h>

int main ()
{
    int iVal = 10;
    // int *iPtr = &iVal;

    int iVar = 77;
    int *iPtr = &iVar;

    printf("%zu\n", sizeof(void *));

    printf("The size in bytes of an int: %lu\n", sizeof(int));
    printf("The size in bytes of a pointer to an int: %lu\n", sizeof(int*));
    
    printf("Value of iVal: %d\n", iVal);
    printf("Address of iVal: %p\n", &iVal);    
    printf("Value of iPtr: %p\n", iPtr);
    
    printf("Value pointed to by iPtr: %d\n", *iPtr);

 
    char *p = "Hello World!";
    printf("Value of p: %p\n", p);
    
    printf("Value of p: %d\n", *p);    
    printf("%c\n", *p);       // H
    printf("%c\n", *(p+1));   // e
    printf("%c\n", *(p+2));   // l    

    printf("Value pointed to by p: %s\n", p);

    return 0;
}
