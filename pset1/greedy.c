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
    
    int c = 0;
    
    float toCents = round(input * 100);
    
    int cents = toCents;
    
    do {
        
        if(cents - 25 >= 0) {
            cents = cents - 25;
            c++;
        } 
        else if(cents - 10 >= 0) {
            cents = cents - 10;
            c++;    
        } 
        else if (cents - 5 >= 0) {
            cents = cents - 5;
            c++;
        }
        else if(cents - 1 >= 0) {
            cents = cents - 1;
            c++;
        }
    } while(cents > 0);
    
    printf("%i\n", c);
}