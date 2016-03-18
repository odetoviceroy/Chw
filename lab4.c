// George Juarez - Lab #4

#include <time.h>
#include <stdlib.h>

int main(void){
    srand(time(NULL));
    int sum, point = 0;
    sum = ((rand() % 6) + 1) + ((rand() % 6) + 1);
    printf("You rolled: %d \n", sum );
    if(sum == 7 || sum == 11){
        printf("You win! \n");
        exit(0);
    }
    else if(sum == 2 || sum == 3 || sum == 12){
        printf("You lose... \n");
        exit(0);
    }
    else {

        printf("\nYour point is: %d \n", sum);
        while(sum != point){
            point = ((rand() % 6) + 1) + ((rand() % 6) + 1);
            if(point == 7){
                printf("You rolled: %d \n", point );
                printf("You lose...\n");
                exit(0);
            }
            else if(point == sum){
                printf("You rolled: %d \n", point );
                printf("You win! \n");
                exit(0);
            }
            else printf("You rolled: %d \n", point );

        }
    }
    return 0;
}
