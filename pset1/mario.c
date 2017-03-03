#include <stdio.h>
#include <cs50.h>

void question(void);
void printMario(int);
int height = 0;


int main(void){
    question();
}


void question(void){
    printf("Height : ");
    height = get_int();
    if (height > 0 && height < 24){
        printMario(height);
    }
    else if (height == 0){
        height=0;
    }
    else question();
}

void printMario(int n){
    int i = 0;
    for (i = 1 ; i <= n ; i++){
        printf("%.*s",n-i,"                        ");
        printf("%.*s",n-(n-i),"########################");
        printf("  ");
        printf("%.*s\n",n-(n-i),"########################");
    }
}