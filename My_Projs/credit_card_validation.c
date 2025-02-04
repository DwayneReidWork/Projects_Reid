#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>

// Function to find the card brand using regex
void find_card_brand(const char* str)
{
    regex_t regex;
    int result;

    // Define patterns for Visa, MasterCard, and American Express
    const char* patterns[] = {
        "^4[0-9]{12}[0-9]{3}?$",  // Visa
        "^5[1-5][0-9]{14}$",          // MasterCard
        "^3[47][0-9]{13}$"            // American Express
    };

    const char* card_brands[] = {
        "Visa",
        "MasterCard",
        "American Express"
    };

    // Iterate over the patterns
    for (int i = 0; i < 3; i++) {
        // Compile the current regex pattern
        result = regcomp(&regex, patterns[i], REG_EXTENDED);
        if (result != 0) {
            printf("Failed to compile regex for pattern %d.\n", i);
            return;
        }

        // Execute the regex match
        result = regexec(&regex, str, 0, NULL, 0);
        
        if (result == 0) {
            // If pattern matches, print the corresponding brand
            printf("Valid credit card number. Brand: %s\n", card_brands[i]);
            regfree(&regex);  // Free the regex memory
            return;
        }

        // Free the regex memory for the next iteration
        regfree(&regex);
    }

    // If no pattern matches
    printf("Invalid credit card number\n");
}

// Function to check if the credit card length is valid
void validate_card_length(const char* str)
{
    int length = 0;

    // Calculate the length of the string (credit card number)
    while (str[length] != '\0') {
        length++;
    }

    // Check the length of the credit card number
    if (length != 13 && length != 15 && length != 16) {
        printf("Invalid credit card # length\n");
    } else {
        // Once length is valid, find the brand
        find_card_brand(str);
    }
}

int main()
{
    char ccnumber[21]; // 20 digits max + null terminator
    printf("Enter your credit card # (13/15/16 digits): ");
    scanf("%20s", ccnumber);  // Read up to 20 characters

    // Ensure null termination by explicitly adding '\0' if needed
    ccnumber[20] = '\0';

    validate_card_length(ccnumber);

    return 0;
}


/*
1. Visa:
Pattern: ^4[0-9]{12}[0-9]{3}?$
Starts with 4, followed by 12 digits, and optionally 3 more digits (i.e., 13 or 16 digits in total).

Valid Input Examples:
4111111111111111 (16 digits)
4234567890123 (13 digits)
453201234567890 (16 digits)


2. MasterCard:
Pattern: ^5[1-5][0-9]{14}$
Starts with 5, followed by a digit between 1 and 5, and then 14 digits (total length of 16 digits).

Valid Input Examples:
5112345678901234 (16 digits)
5234567890123456 (16 digits)
5312345678901234 (16 digits)

3. American Express:
Pattern: ^3[47][0-9]{13}$
Starts with 3, followed by either 4 or 7, and then 13 digits (total length of 15 digits).

Valid Input Examples:
371234567890123 (15 digits)
341234567890123 (15 digits)
347654321098765 (15 digits)
*/