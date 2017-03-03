#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int question();


int main(void){
    question();
}


int question(){
    bool switchS = 0;
    int i = 0;
    string stringSplit = get_string();
    for (i = 0; stringSplit[i] != '\0'; i++){
        if ((stringSplit[i] != ' ') && (switchS == 0)) {
                    printf("%c",toupper(stringSplit[i]));
                    switchS = 1;
        }
        else if (stringSplit[i] == ' ') {
            switchS = 0;
        }
    }
    printf("\n");
    return 0;
}