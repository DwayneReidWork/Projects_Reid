//for reverse string slicing doesnt exist in c

#include <stdio.h>
#include <string.h>

int main()
{
    char stringToBeReversed[100]; //can get 99 chars of input plus '/0' string literal at the end
    printf("Enter something to read backwards: ");
    scanf("%[^\n]s", stringToBeReversed); // ^/n basically skips over the blank lines in a scanset
    int stringLength = strlen(stringToBeReversed); 

    for(int i = strlen(stringToBeReversed);0 <= i;i--)
    {
    printf("%c", stringToBeReversed[i]);
    }
    printf("\n");
    return 0;
}