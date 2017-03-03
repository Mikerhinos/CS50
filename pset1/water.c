#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int minutes = 0;
    printf("Minutes : ");
    minutes = get_int();
    int bottles = minutes*12 ;
    printf("Bottles : %i\n", bottles);
}