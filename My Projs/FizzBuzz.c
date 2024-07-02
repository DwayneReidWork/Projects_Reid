#include <stdio.h>
#include <math.h>

int main()
{
    
    char f[] = "fizz";
    char b[] = "buzz";
    char fb[] = "FizzBuzz";
    //int number = 0;

    for(int number = 0;number <= 100; number++)
   {
        if (number % 3 == 0 && number % 5 == 0)
        {
            printf("%d is %s\n", number, fb);
        }
        else if (number % 3 == 0)
        {
            printf("%d is %s\n", number, f);
        }
        else if (number % 5 == 0)
        {
            printf("%d is %s\n", number, b);
        }
        else
        {
            printf("%d\n", number);
        }
    }
    return 0;
}