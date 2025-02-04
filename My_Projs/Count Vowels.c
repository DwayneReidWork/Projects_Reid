/* 
count vowels learn how chars are represented in C
chars are ascii values
*/

#include <stdio.h>
#include <string.h>

int isVowel(char c) {
    char vowels[] = "AEIOUaeiou";
    int i = 0;
    int vowel_count = 0;
    int fBool = 0;
    while(vowels[i] != '\0'){
        // printf("%c\n", vowels[i]);
        if (c == vowels[i]) {
            fBool = 1;
        }
        i++;
    }
    return fBool;
}

int main() {
    //printf("How many vowels are in the following phrase/sentence?: ");

    char userInput[99];
    printf("Vowel counter. Please input phrase: ");
    fgets(userInput, sizeof(userInput), stdin);
    int StringLength = strlen(userInput);
    int count = 0;
    printf("The length of the string input is %d\n", StringLength);

    for(int i = 0;i <= StringLength; i++){
        // printf("%d = %c\n", i, userInput[i]);
        count += isVowel(userInput[i]);
    }

    // printf("This is the return value for 'a' %d\n", (isVowel('a')));
    // printf("This is the return value for 'b' %d\n", (isVowel('b')));


    printf("Final vowel count: %d\n", count);
    return 0;
}