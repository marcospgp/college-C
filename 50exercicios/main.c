#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

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

void questao10 () {

    printf("Please enter a string to be copied:\n");

    char str[256], copied[256];

    scanf("%255s", &str);

    char currentChar = str[0];
    unsigned int i = 0;

    while (currentChar != '\0') {

        copied[i] = currentChar;

        i++;

        currentChar = str[i];
    }

    copied[i] = '\0';


    printf("\n\nThe copied string is:\n\n%s\n", copied);
}

// Skip 11

void questao12 () {

    char haystack[256], needle[256];

    printf("Please enter the string to be searched:\n");

    scanf("%255s", &haystack);

    printf("\nPlease enter the string to search for:\n");

    scanf("%255s", &needle);

    int i = 0, matches = 0, latestMatch;
    bool lastCharMatched = false;

    // Loop through haystack
    while (haystack[i] != '\0') {

        if (haystack[i] == needle[matches]) {

            // Update latest match if the previous character didn't match
            if (!lastCharMatched) {
                latestMatch = i;
            }

            lastCharMatched = true;
            matches++;

            // Check if this is the final match
            if (needle[matches + 1] == '\0') {

                printf("\n\nWe found your string at position %d, which corresponds to the pointer %p", latestMatch, haystack[latestMatch]);
                return;
            }

        } else {

            matches = 0;
            lastCharMatched = false;
        }

        i++;
    }

    printf("\n\nThe string was not found");
}

// Skip 13 & 14

void questao15 () {

    char text[1024], newText[1024];
    int maxWordLength;

    printf("Please enter your text, with words separated by one or more spaces:\n");

    scanf("%1023[0-9a-zA-Z ]", &text); // Get a string including spaces

    printf("\n\n%s\n\n", text);

    printf("\nPlease enter the number of characters to truncate each word to:\n");

    scanf("%d", &maxWordLength);

    int i = 0, charCount = 0, charsWritten = 0;

    // Loop through the text
    while (text[i] != '\0') {

        if (text[i] == ' ') {

            newText[charsWritten] = ' ';
            charCount = 0;
            charsWritten++;

        } else {

            if (charCount < maxWordLength) {

                newText[charsWritten] = text[i];
                charsWritten++;
            }

            charCount++;
        }

        i++;
    }

    newText[charsWritten] = '\0';

    printf("\n\nThe new text is:\n\n%s\n", newText);
}

void questao16 () {

    char input[256], countedChars[256]; // Input - string recebida ex.:"bieber"; countedChars - caracteres que já foram contados
    int countedCharValues[256]; // Guarda o número de caracteres presentes na input, na mesma ordem de countedChars

    // countedChars tem de ser uma string para podermos usar a função strchr nela
    countedChars[0] = '\0';

    printf("Please enter a string to get the most frequent character:\n");

    scanf("%255s", &input);

    // Contar os caracteres um a um

    int i, j, counted = 0, length = strlen(input);

    for (i = 0; i < length; i++) {

        // Se o caractere atual da input não tiver sido contado ainda
        if (strchr(countedChars, input[i]) == NULL) {

            // Adicionar o caractere à string de caracteres contados

            countedChars[counted] = input[i];

            countedChars[counted + 1] = '\0'; // Manter o final da string

            countedCharValues[counted] = 1; // Já contamos um caractere destes no total

            // Contar quantos caracteres iguais ao atual há na string

            for (j = i + 1; j < length; j++) {

                // Se este caractere for igual ao que estamos a contar
                if (input[j] == input[i]) {

                    // Aumentar a conta
                    countedCharValues[counted]++;
                }
            }

            counted++; // Anotar que mais um caractere foi contado
        }
    }

    // Descobrir qual foi o caractere contado mais vezes
    int l, biggest = 0, biggestIndex = 0;

    // Percorrer o array com o numero de vezes que cada caractere foi contado, de maneira a descobrir
    // o indice do caractere mais contado

    for (l = 0; l < counted; l++) {

        if (countedCharValues[l] > biggest) {

            biggest = countedCharValues[l];

            biggestIndex = l;
        }
    }

    char mostFrequentChar = countedChars[biggestIndex];

    printf("\n\nThe most frequent char is: %c\n", mostFrequentChar);
}

// skip 17-20

void questao45 () {
    char alphabet[52] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    int i;
    for (i = 0; i < 26; i++) {
        printf("%c - %d  %c - %d\n", alphabet[i], alphabet[i], alphabet[i + 26], alphabet[i + 26]);
    }
}

void questao46 () {

    // Get first group

    printf("First group:\n");

    int group1[10];

    int i;
    for (i = 0; i < 10; i++) {
        printf("Enter 0 or 1:\n");
        scanf("%d", &group1[i]);
    }

    // Get second group

    printf("\nSecond group:\n");

    int group2[10];

    for (i = 0; i < 10; i++) {
        printf("Enter 0 or 1:\n");
        scanf("%d", &group2[i]);
    }

    printf("\nResulting groups:\n");

    for (i = 0; i < 10; i++) {
        printf("%d ", group1[i]);
    }

    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%d ", group2[i]);
    }

    printf("\n\nUnion of the two groups:\n");

    for (i = 0; i < 10; i++) {
        if (group1[i] || group2[i]) {
            printf("1 ");
        } else {
            printf("0 ");
        }
    }

    printf("\nIntersection of the two groups:\n");

    for (i = 0; i < 10; i++) {
        if (group1[i] && group2[i]) {
            printf("1 ");
        } else {
            printf("0 ");
        }
    }
}

int main () {

    questao46();

    return 0;
}
