/*
 * Builds a mario style pyramid of #'s out of a inputed height.
 */

#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    int height;
    
    // Make sure height is positive and no greater than 23.
    do {
        printf("Height: ");
        height = GetInt();
    } while (height > 23 || height < 0);
    
    // Loop and output
    for(int i = 0; i < height; i++){
        
        for (int y = height - i; y - 1 > 0; y--){
            printf(" ");
        }
        
        for(int x = 0; x <= i + 1; x++) {
            printf("#");
        }
        
        printf("\n");
    }
    
}