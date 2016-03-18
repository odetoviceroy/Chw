// George Juarez - Lab #5

#include <stdio.h>
#include <stdlib.h>

// initialize array of characters to eventually print out converted number
char baseDigits[16] = {'0','1','2','3','4','5','6','7','8','9',
                        'A','B','C','D','E','F'};
void convertViaRadix(int,int);

int main(void){
    int d, r;
    // read decimal number and base to be converted to
    printf("Enter your decimal number: ");
    scanf("%d",&d);
    printf("\nEnter your radix to be used (2-16): ");
    scanf("%d",&r);
    // error check, just to be safe
    if(r > 16 || r < 2){
        printf("\nSorry, please enter a number between 2 and 16. Try again. \n");
        exit(0);
    }
    // call void function
    convertViaRadix(d,r);
    return 0;
}

void convertViaRadix(int decimal, int radix){
    // set result to be an int array with max places to be 64
    int result[64];
    int i = 0;
    // use same algorithm when converting a dollar to coins
    while(decimal != 0){
        result[i] = decimal % radix;
        decimal = decimal / radix;
        i++;
    }
    // subtract 1 from i as to not go out of bounds
    i--;
    printf("\nYour number in base %d is: ",radix);
    // use for loop to print the number backwards, so to speak
    for( ; i >= 0; i-- ){
        printf("%c", baseDigits[result[i]]);
    }
    printf("\n");
    return;
}
