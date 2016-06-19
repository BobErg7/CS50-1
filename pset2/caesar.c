/*
 * Encrypt inputted text using the Caesar cypher.
 */
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check we have exactly two arguments, if not error.
    if(argc != 2) {
        printf("Usage: ./caesar key \n");  
        return 1;
    } 
    
    // Set key as integer from provided string
    int k = atoi(argv[1]);
    
    // Only allow positive numbers as the key.
    if(k == 0) {
        printf("'key' should be a positive number \n");  
        return 1;
    }
    
    // Keep key within alphabetic range
    if((k % 26) > 0) {
        k = k % 26;
    }
 
    // Get the string to encrypt      
    string s = GetString();
 
    // Loop through each character and begin attempting encryption
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Only encrypt letters, output numbers and symbols as normal.
        if(isalpha(s[i])) {
            int letter = s[i];
            int encryptedLetter;
            
            // Handle upper case letter (ASCII Range: 65 -> 90 )
            if(isupper(letter)){
                encryptedLetter = letter + k;
                // If number is outside of our ASCII range reset 
                if(encryptedLetter > 90) {
                    encryptedLetter = 64 + (encryptedLetter - 90);
                }
            }
            // Handle lower case letter (ASCII Range: 97 -> 122)
            else {
                encryptedLetter = letter + k;
                
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