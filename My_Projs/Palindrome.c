//just to line up

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int palindrome_check(char stringOriginal[], char stringBackwards[])
{
    int is_palindrome = 1; // 1 = true 0 = false
    int len = strlen(stringOriginal);

    for (int i = 0; i < len; i++) {
        if (toupper(stringOriginal[i]) != toupper(stringBackwards[i])) {
            is_palindrome = 0; 
            break;
        }
    }
    return is_palindrome;
}

int main()
{
    char stringOriginal[100]; //can get 99 chars of input plus '/0' string literal at the end
    printf("Enter something to read backwards: ");
    scanf("%[^\n]s", stringOriginal); // ^/n basically skips over the blank lines in a scanset
    int stringLength = strlen(stringOriginal);
    char stringBackwards[stringLength + 1];
    //following for loop creates the inverse string
    for(int i = (strlen(stringOriginal)-1), j = 0; 0 <= i ; i--, j++)
    {
        stringBackwards[j] = stringOriginal[i];
    }   

    stringBackwards[stringLength] = '\0'; // Null-terminate the reversed string

    printf("Your string backwards is: %s\n", stringBackwards);

    if (palindrome_check(stringOriginal, stringBackwards)) {
        printf("It is a palindrome.\n");
    } else {
        printf("It is not a palindrome.\n");
    }
    return 0;
}