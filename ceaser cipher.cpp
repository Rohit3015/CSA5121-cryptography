#include <stdio.h>
#include <ctype.h>

// Function to encrypt a single character using the affine Caesar cipher
char encryptChar(int a, int b, char ch) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        return ((a * (ch - base) + b) % 26) + base;
    } else {
        return ch; // Return the character unchanged if it's not alphabetic
    }
}

// Function to encrypt a string using the affine Caesar cipher
void encryptString(int a, int b, char *str) {
    while (*str != '\0') {
        *str = encryptChar(a, b, *str);
        str++;
    }
}

int main() {
    char plaintext[1000];
    int a, b;

    // Input the values of a and b
    printf("Enter the value of a (must be coprime to 26): ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);

    // Check if 'a' is coprime to 26
    // Allowed values of 'a' are 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25
    if (a % 2 == 0 || a % 13 == 0) {
        printf("Invalid value of 'a'. It must be coprime to 26.\n");
        return 1;
    }

    // Input the plaintext
    printf("Enter the plaintext: ");
    scanf(" %[^\n]s", plaintext);

    // Encrypt the plaintext
    encryptString(a, b, plaintext);

    // Output the ciphertext
    printf("Ciphertext: %s\n", plaintext);

    return 0;
}
