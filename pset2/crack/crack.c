#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// While only 4 chars from a to Z seem a little, if someone choose ZZZZ the program will run more than 7.3 millions times...

int main(int argc, string argv[]){
    if (argc == 2){ // check that there is only 1 argument
        int i, j, k, l;
        string password = argv[1]; // we get the crypted password passed as the argument
        char possibleChar[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; // All possible chars - Warning : length will be 53 (0 to 51+1) not 52, because of '\0' automatically added at end of array
        char crackpw[5] ; // cracked password var, 4 chars max, so 0 to 3 + '\0'
        string crackedpw = "a" ;
        for (l=0; l<=51; l++){ // 4 - "odometer" construction, by adding 4 wheels of 52 values from a to Z
            for (k=0; k<=51; k++){ // 3
                for (j=0; j<=51; j++){ // 2
                    for (i=0; i<=51; i++){ // 1
                        crackpw[0] = possibleChar[i]; // check 1 char length, from a to Z
                        crackedpw = crypt(crackpw, "50") ;
                        if (strcmp(password, crackedpw) == 0){
                            printf("%s\n", crackpw); // password found ! Let's see what we got here...
                            exit(0);
                        }
                    }
                    i=0;
                    crackpw[1] = possibleChar[j]; // check 2 chars length, from aa to ZZ
                }
                i=0; // spin back used wheels to a
                j=0;
                crackpw[2] = possibleChar[k]; // check 3 chars length, from aaa to ZZZ
            }
            i=0; // spin back used wheels to a
            j=0;
            k=0;
            crackpw[3] = possibleChar[l]; // check 4 chars length, from aaaa to ZZZZ
        }
        i=0; // spin back used wheels to a
        j=0;
        k=0;
    printf("Sorry mate, password not found :( \n"); // well, that su***, we've gone through all possibilities but didn't found a match :/ Let's exit this while loop...
    exit(1);
    }
    else { // if there is no, or more than one argument, exit and return 1
        printf("Usage: ./crack hash\n");
        exit(1);
    }
}