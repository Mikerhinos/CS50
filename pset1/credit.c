#include <stdio.h>
#include <cs50.h>

long long number = 0;

void question(void);
bool isValid(long long n,int l);


int main(void){
    question();
    return 0;
}


void question(void){
    printf("Number : ");
    number = get_long_long();
    if ((number > 339999999999999 && number < 350000000000000) || (number > 369999999999999 && number < 380000000000000)){
        if (isValid(number,15)==1) printf("AMEX\n");
        else printf("INVALID\n");
    }
    else if (number > 5099999999999999 && number < 5600000000000000){
        if (isValid(number,16)==1) printf("MASTERCARD\n");
        else printf("INVALID\n");
    }
    else if (number > 3999999999999 && number < 5000000000000){
        if (isValid(number,13)==1) printf("VISA\n");
        else printf("INVALID\n");
    }
    else if (number > 3999999999999999 && number < 5000000000000000){
        if (isValid(number,16)==1) printf("VISA\n");
        else printf("INVALID\n");
    }
    else printf("INVALID\n");
}

bool isValid(long long n, int l){
    int i = 0;
    int digit[l];
    int product = 0;
    int sum = 0;
    // Filling array with each digits of number
    for (i = l-1; i >=0 ; i--){
        digit[i] = n %10;
        n = n / 10;
    }
    // Selection of each other digit, then adding its products to sum
    for (i = l-1; i >= 0; i-=2){
        sum += digit[i];
    }
    for (i = l-2; i >= 0; i-=2){
        product = digit[i]*2;
        if (product > 9){
            product = product-9;
        }
        sum += product;
    }
    if (sum %10 == 0){
        return 1;
    }
    else {
        return 0;
    }
}