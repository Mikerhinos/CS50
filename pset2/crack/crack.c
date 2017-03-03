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
        int crackedpwLen = 1;
        char crackpw4[5];
        char crackpw3[4];
        char crackpw1[2];
        char crackpw2[3];
        string crackedpw = "a" ;
        for (l=0; l<=51; l++){ // 4 - "odometer" construction, by adding 4 wheels of 52 values from a to Z
            for (k=0; k<=51; k++){ // 3
                for (j=0; j<=51; j++){ // 2
                    for (i=0; i<=51; i++){ // 1
                        crackpw4[0] = possibleChar[i];
                        crackpw3[0] = possibleChar[i];
                        crackpw1[0] = possibleChar[i];
                        crackpw2[0] = possibleChar[i];
                        if (crackedpwLen == 1){ // testing 1 char long
                            crackpw1[1] = '\0';
                            crackedpw = crypt(crackpw1, "50") ;
                            if (strcmp(password, crackedpw) == 0){
                                printf("%s\n", crackpw1); // password found ! Let's see what we got here...
                                exit(0);
                            }
                        }
                        else if (crackedpwLen == 2){ // testing 2 char long
                            crackedpw = crypt(crackpw2, "50") ;
                            if (strcmp(password, crackedpw) == 0){
                                printf("%s\n", crackpw2); // password found ! Let's see what we got here...
                                exit(0);
                            }
                        }
                        else if (crackedpwLen == 3){ // testing 3 or more char long
                            crackedpw = crypt(crackpw3, "50") ;
                            if (strcmp(password, crackedpw) == 0){
                                printf("%s\n", crackpw3); // password found ! Let's see what we got here...
                                exit(0);
                            }
                        }
                        else if (crackedpwLen == 4){ // testing 3 or more char long
                            crackedpw = crypt(crackpw4, "50") ;
                            if (strcmp(password, crackedpw) == 0){
                                printf("%s\n", crackpw4); // password found ! Let's see what we got here...
                                exit(0);
                            }
                        }
                    }
                    i=0;
                    crackpw4[1] = possibleChar[j]; // changing value of char2
                    crackpw3[1] = possibleChar[j];
                    crackpw2[1] = possibleChar[j];
                    crackpw2[2] = '\0';
                    if (crackedpwLen <= 2){ // if length is less than 2 chars, now it is
                        crackedpwLen = 2;
                    }
                }
                i=0; // spin back used wheels to a
                j=0;
                crackpw4[2] = possibleChar[k]; // changing value of char 3
                crackpw3[2] = possibleChar[k];
                crackpw3[3] = '\0';
                if (crackedpwLen <= 3){ // if length is less than 3 chars, now it is
                        crackedpwLen = 3;
                }
            }
            i=0; // spin back used wheels to a
            j=0;
            k=0;
            crackpw4[3] = possibleChar[l]; // changing value of char 4
            crackpw4[4] = '\0';
            if (crackedpwLen <= 4){ // if length is less than 3 chars, now it is
                        crackedpwLen = 4;
            }
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