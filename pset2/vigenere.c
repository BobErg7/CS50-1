/*
 * Encrypt inputted text using the Vigenere cipher.
 */
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check we have exactly two arguments, if not error.
    if(argc != 2) {
        printf("Usage: ./vigenere key \n");  
        return 1;
    }
    
    string keyString = argv[1];
    int keyLength = strlen(keyString);
    
    int key[keyLength];
    
    
    for (int i = 0; i < keyLength; i++)
    {
        // Test the key is only consisting of alphanumeric characters
        if(!isalpha(keyString[i])) {
            printf("'key' should be alphanumeric \n");  
            return 1;
        } 
        // Send key number to array for use later
        else {
            if(isupper(keyString[i])) {
                key[i] = keyString[i] - 65; 
            } else {
                key[i] = keyString[i] - 97; 
            }
        }
    }
    
    string s = GetString();
    
    for(int i =0; i < strlen(s); i++) {
        // Set key:
        int k = i % keyLength;
        // Only encrypt letters, output numbers and symbols as normal.
        if(isalpha(s[i])) {
            int letter = s[i];
            int encryptedLetter;
            
            // Handle upper case letter (ASCII Range: 65 -> 90 )
            if(isupper(letter)){
                encryptedLetter = letter + key[k];
                // If number is outside of our ASCII range reset 
                if(encryptedLetter > 90) {
                    encryptedLetter = 64 + (encryptedLetter - 90);
                }
            }
            // Handle lower case letter (ASCII Range: 97 -> 122)
            else {
                encryptedLetter = letter + key[k];
                // If number is outside of our ASCII range reset
                if(encryptedLetter > 122) {
                    encryptedLetter = 96 + (encryptedLetter - 122);
                }
                
            }
            printf("%c", encryptedLetter);
        } else {
            printf("%c", s[i]);
        }
    }
    
    printf("\n");
}