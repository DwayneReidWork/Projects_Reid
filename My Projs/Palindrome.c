#include <stdio.h>
#include <string.h>

int main()
{
    char stringOriginal[100]; //can get 99 chars of input plus '/0' string literal at the end
    printf("Enter something to read backwards: ");
    scanf("%[^\n]s", stringOriginal); // ^/n basically skips over the blank lines in a scanset
    int stringLength = strlen(stringOriginal); 

    for(int i = strlen(stringOriginal);0 <= i;i--)
    {
    printf("%c", stringOriginal[i]);
    char stringReversed[] = stringOriginal;
    printf("%s", stringReversed);
    }

    printf("\n");
    return 0;
}