/*
 * Calculates the amount of bottles of water your X minute shower uses. 
 * (Based on the assumption of 12 bottles of water per 1 minute of showering)
 */

#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    printf("minutes: ");
    int minutes = GetInt();
    int bottles = minutes * 12;
    printf("bottles: %i \n", bottles);
}