#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[]){
    if (argc == 2){
        for (int k=0; k < strlen(argv[1]); k++){
            if (!((argv[1][k] >= 'a' && argv[1][k] <= 'z') || (argv[1][k] >= 'A' && argv[1][k] <= 'Z'))) {
                printf("No numbers");
                exit(1);
            }
        }
        printf("plaintext: ");
        string text = get_string();
        int letter = 0;
        if (text != NULL){
            printf("ciphertext: ");
            int j = 0;
            // read the string
            for (int i=0, n=strlen(text); i<n; i++){
                // get j to 0 at each end of k parameter lenght
                if (j>=strlen(argv[1])){
                        j = 0;
                    }
                // if it's a lowercase letter
                if (text[i] >= 'a' && text[i] <= 'z'){
                    letter = (((text[i]-97)+(tolower(argv[1][j])-97))%26)+97;
                    j++;
                }
                //else if it's an uppercase letter
                else if (text[i] >= 'A' && text[i] <= 'Z'){
                    letter = toupper((((text[i]-65)+(tolower(argv[1][j])-97))%26)+97);
                    j++;
                }
                // else it's not a letter, don't crypt it
                else letter = text[i];
                // print each letter of the string
                printf("%c", letter);
            }
            // string is over, make a new line
            printf("\n");
        }
        return 0;
    }
    // if there's more than 1 argument
    else {
        printf("Too many arguments\n");
        exit(1);
    }
}