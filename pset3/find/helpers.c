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
 * Recursive binary search function, returns the key the value exists at or -1 if it does not exist.
 */
int binarySearch(int key, int array[], int min, int max) {
    if(max < min) {
        printf("Max is now less than min \n");
        return -1;
    }
    else{
        int midpoint = (min + max) / 2;
        if(array[midpoint] < key) {
            return binarySearch(key, array, midpoint + 1, max);
        }
        else if (array[midpoint] > key) {
            return binarySearch(key, array, min, midpoint - 1);
        } 
        else {
            return midpoint;
        }   
    }
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Binary search for the value
    int result = binarySearch(value, values, 0, n);
    if(result != -1) {
        return true;
    } else {
        return false;
    }
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