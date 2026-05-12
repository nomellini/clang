#include <stdio.h>
#include <string.h>
#include <assert.h>



void two_fer(char *buffer, const char *name)
{
    
    if (name == NULL) {
        return ;
    }    
    sprintf(buffer, "One for %s, one for me", name[0] ? name : "you");
}

int main() 
{

    char response[1000];    
    two_fer(response, "Alice");
    printf("%s\n", response);
 

}