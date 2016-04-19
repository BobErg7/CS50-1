/*
 * Print out a name's intials.
 */
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void) 
{
    string name = GetString();
    char * words;
    
    words = strtok(name," ");
    
    while (words != NULL)
    {
        printf("%c", toupper(words[0]));   
        words = strtok(NULL, " ");
    }
    
    printf("\n");

}