/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"


// 1st we search for the biggest number in array
int findLargest(int arr[], int n){
    int largest = arr[0];
    for (int i = 0; i < n - 1; i++){
        if (largest < arr[i]){
            largest = arr[i];
        }
    }
    return largest;
}

/**
 * Returns true if value is in array of n values, else false. search(needle, haystack, size)
 */
bool search(int value, int values[], int n){
    // TODO: implement a searching algorithm
    if (n >= 0){
        int first = 0;
        int last = n - 1;
        int middle = (first+last)/2; // split the search part in 2, look in the middle
        while (first <= last){
            if (values[middle] < value) { // if needle is > than the number in middle, look in right part
                first = middle + 1;
            }
            else if (values[middle] == value){ // if needle is found
                exit(0);
            }
            else last = middle - 1; // if needle is < than middle, look in left part
            
            middle = (first+last)/2; // split in 2 again and look
        }
        if (first > last){
            exit(1);
        }
    }
    else exit(1);
    return 1;
}

/**
 * Sorts array of n values. sort(haystack, size);
 */
void sort(int values[], int n){
    // take biggest number and find how many digits it has
    int biggest = findLargest(values, n);
    int digits = 0, pass, divisor = 1, chkdDigit, i = 0;
    int bucket[65537][10];
    int bucketQuant[10]; // create 10 buckets to store quantity of each digit, ex : bucketQuant[8]=6 means there are 6 times the digit '8'
    while (biggest > 0){
        digits++;
        biggest /= 10;
    }
    for (pass = 0; pass < digits; pass++){
        for (i=0; i<n; i++){
            chkdDigit = (values[i] / divisor) %10; // decomposing each number digit by digit to store it in a bucket, and count quantity in each bucket with bucketQuant
            bucket[chkdDigit][bucketQuant[chkdDigit]] = values[i];
            bucketQuant[chkdDigit] +=1;
        }
        i = 0;
        for (int j=0; j < 10; j++){
            for (int k=0; k < bucketQuant[j]; k++){ // sort all the numbers by putting them back in values[]
                values[i] = bucket[j][k];
                i++;
            }
        }
        divisor *=10; // checking next digit
    }
}
