#include <stdio.h>
#include <stdlib.h>

void questao1 () {

    int num;
    int result = 0;

    printf("Insert numbers to be added. Enter 0 to get the result:\n");

    while (num != 0) {

        scanf("%d", &num);

        if (num != 0) {
            result += num;
        }
    }

    printf("The result is: %d\n", result);

}

void questao2 () {

    int num;

    int biggest = 0;

    printf("Enter as many numbers as you want. Entering 0 will return the biggest:\n");

    do {

        scanf("%d", &num);

        if (num > biggest) {

            biggest = num;
        }

    } while (num != 0);

    printf("The biggest number is: %d", biggest);

}

void questao3 () {

    int num;

    int sum = 0;

    int count = 1;

    printf("Enter as many numbers as you want. Entering 0 will return the average:\n");

    do {

        scanf("%d", &num);

        sum += num;

        count++;

    } while (num != 0);

    double average = sum / count;

    printf("The average is: %f", average);

}

void questao4 () {

    int num, biggest = 0, secondBiggest = 0;

    printf("Enter as many numbers as you want. Entering 0 will return the second biggest number:\n");

    do {

        scanf("%d", &num);

        if (num > biggest) {

            secondBiggest = biggest;

            biggest = num;

        } else if (num > secondBiggest) {

            secondBiggest = num;
        }

    } while (num != 0);

    printf("The second biggest number is: %d", secondBiggest);

}

// Auxiliary function for questions below
void decimalToBinary (unsigned int num, char *destination) {

    unsigned int quotient, remainder, counter = 63, i;

    // String size is 64 + 1 for the null character
    char binaryString[65];

    // Fill string with x's
    for (i = 0; i < (sizeof(binaryString) - 1); i++) {

        binaryString[i] = 'x';
    }

    // Make last character \0
    binaryString[64] = '\0';

    do {

        quotient = num / 2;

        remainder = num % 2;

        num = quotient;

        binaryString[counter] = (remainder == 0) ? '0' : '1';

        counter--;

        printf("\nNum: %u quotient: %u remainder: %u\n", num, quotient, remainder);

    } while (quotient >= 2);

    // Add the last 1 in accordance with the decimal to binary algorithm
    binaryString[counter] = '1';

    // Extract all numbers from the string

    char finalBinary[65], currentChar;

    int j, bitsExtracted = 0;

    for (j = 0; j < 64; j++) {

        if (binaryString[j] != 'x') {

            finalBinary[bitsExtracted] = binaryString[j];

            bitsExtracted++;
        }
    }

    // Add final string character
    finalBinary[bitsExtracted] = '\0';

    // Copy finalBinary onto binaryString
    strcpy(destination, finalBinary);

    /* Convert string to int so it can be returned
    unsigned int finalInt;
    sscanf(finalBinary, "%d", &finalInt);

    return finalInt;*/
}

void questao5 () {

    unsigned int num;

    printf("Please insert a number to get the number of 1's in its binary representation:\n");

    scanf("%u", &num);

    char result[65];

    decimalToBinary(num, result);

    printf("\nResulting binary number: %s\n", result);

    // Count the number of 1's in the binary representation of the number

    // Loop through the binary string

    char currentChar, i = 0;
    unsigned int numberOf1s = 0;

    do {

        currentChar = result[i];

        if (currentChar == '1') {
            numberOf1s++;
        }

        i++;

    } while (currentChar != '\0');

    printf("\nNumber of 1's: %u\n", numberOf1s);
}

void questao6 () {

    unsigned int num;

    printf("Please insert a number to get the number of trailing zeros in its binary representation:\n");

    scanf("%u", &num);

    char binaryString[65];

    decimalToBinary(num, binaryString);

    printf("Binary representation of the number: %s\n", binaryString);

    // Loop through the string and count the 0's until '\0' is reached, returning the count to 0 whenever a '1' is found

    char currentChar;

    unsigned int trailingZeros = 0, counter = 0;

    do {

        currentChar = binaryString[counter];

        if (currentChar == '0') {

            trailingZeros++;

        } else if (currentChar == '1') {

            trailingZeros = 0;
        }

        counter++;

    } while (currentChar != '\0');

    printf("\nThe number of trailing zeros is: %u\n", trailingZeros);
}

void questao7 () {

    printf("Please enter a number to get the length of it:\n");

    unsigned int num;

    scanf("%u", &num);

    char numberString[100];

    sprintf(numberString, "%u", num);

    // Loop through the string and count its length

    int i = 0;

    char currentChar;

    do {

        currentChar = numberString[i];

        i++;

    } while (currentChar != '\0');

    printf("\nThe length of the number is: %d\n", (i - 1)); // (i - 1) because i was incremented when we looped through '\0'
}

void questao8 () {

    printf("Please enter a string to get its length:\n");

    char string[256];

    fgets(string, 256, stdin);

    int i = 0, count = 0, newlinesIgnored = 0;
    char currentChar;

    do {

        currentChar = string[i];

        if (currentChar == '\n') {

            newlinesIgnored++;

        } else if (currentChar != '\0') {

            count++;
        }

        i++;

    } while (currentChar != '\0');

    printf("\nThe string length is: %d (newlines ignored: %d)\n", count, newlinesIgnored);
}

void questao9 () {

    printf("Please enter two strings to be concatenated:\n");

    char string1[256], string2[256], result[511]; // Each string ends with '\0', so result only needs (size of string1 - 1) + (size of string2 - 1) + 1 of length

    fgets(string1, 256, stdin);

    fgets(string2, 256, stdin);

    // Get the length of the strings
    unsigned int string1Length = getStringLength(string1);
    unsigned int string2Length = getStringLength(string2);

    // Copy the first string into result so we can then insert the second string at the end of the first
    strcpy(result, string1);

    int i, insertPos;

    for (i = 0; i < string2Length; i++) {

        insertPos = string1Length + i;

        result[insertPos] = string2[i];
    }

    // Add null character to end of result string
    result[string1Length + string2Length] = '\0';

    printf("\nConcatenated strings:\n\n%s\n", result);
}

// Auxiliar function for above question
int getStringLength (char *string) {

    int i = 0, count = 0;
    char currentChar;

    do {

        currentChar = string[i];

        if (currentChar != '\n' && currentChar != '\0') {

            count++;
        }

        i++;

    } while (currentChar != '\0');

    return count;
}

int main () {

    questao9();

    return 0;
}
