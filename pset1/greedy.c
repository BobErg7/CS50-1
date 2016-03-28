/*
 * Greedy algorithm for giving change (US coins)
 */
#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void) 
{
    float input;
    
    printf("O hai! ");
    
    do {
        printf("How much change is owed? \n");
        input = GetFloat();
    } while(input < 0);
    
    // Fix input to integer so we don't have to deal with weird float math
    float toCents = round(input * 100);
    int cents = toCents;
    
    // Break change into least amount of coins possible
    int c = 0;
    do {
        if(cents % 25 < cents) {
            c = c + round(cents/25);
            cents = cents % 25;
        } 
        else if(cents % 10 < cents) {
            c = c + round(cents/10);
            cents = cents % 10;
        }
        else if(cents % 5 < cents) {
            c = c + round(cents/5);
            cents = cents % 5;
        }
        else{
            c = c + round(cents/1);
            cents = cents % 1;
        }
    } while(cents > 0);
    
    printf("%i\n", c);
}