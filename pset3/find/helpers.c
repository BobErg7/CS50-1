/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Linearly search for the value
    for(int i = 0; i < n; i++){
        if(values[i] == value) {
            return true;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Sort the array using insertion sort..
    for(int i = 1; i < n; i++) {
        int current = values[i];
        int newKey = i;
        while(newKey > 0 && values[newKey - 1] > current) {
            values[newKey] = values[newKey - 1];
            newKey = newKey - 1;
        }
        values[newKey] = current;
    }
    
    return;
}











