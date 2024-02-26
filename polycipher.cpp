#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to encrypt a single character using a monoalphabetic substitution cipher
char encryptChar(char key, char ch) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        // Calculate the offset based on the key
        int offset = toupper(key) - 'A';
        // Apply the offset
        return ((ch - base + offset) % 26) + base;
    } else {
        return ch; // Return the character unchanged if it's not alphabetic
    }
}

// Function to encrypt a string using a polyalphabetic substitution cipher
void encryptString(const char *key, const char *plaintext, char *ciphertext) {
    int keyLength = strlen(key);
    int i, j = 0;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            // Use the current key character for encryption
            ciphertext[i] = encryptChar(key[j % keyLength], plaintext[i]);
            j++;
        } else {
            // Non-alphabetic characters remain unchanged
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}

int main() {
    char key[100];
    char plaintext[1000];
    char ciphertext[1000];

    // Input the key
    printf("Enter the key: ");
    scanf("%s", key);

    // Input the plaintext
    printf("Enter the plaintext: ");
    scanf(" %[^\n]s", plaintext);

    // Encrypt the plaintext
    encryptString(key, plaintext, ciphertext);

    // Output the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
