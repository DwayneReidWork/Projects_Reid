#include <stdio.h>
#include <math.h>

int main()
{
    double pi = acosl(-1);
    
    int userInput;
    printf("Enter number of digits to round PI to: ");
   
    int ret =  scanf("%d", &userInput);

    if (ret == 0){
        printf("Please input a number to round PI to.");
    }
    else if (userInput < 0 ||userInput > 99){
        printf("Please input a number between 0 and 99.");    
    }
    else{
        printf("%.*f", userInput, pi);
    }

    return 0;
}