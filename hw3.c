//George Juarez - HW #3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  /*
  printf("\nYour expression is %s \n", exp);
  expPtr = strtok (exp," ,.-");
  while(expPtr != NULL){
      printf("%s\n",expPtr);
      expPtr = strtok (NULL, " ,.-");
  }

  */
    char expr[255];
    char * exprPtr;
    int sum = 0, op = -1;
  //  char * exprPtr;
    // int j = 0 ; sum = 0; op = -1;
    // int count = 0;
    printf("Enter your expression: ");
    scanf ("%[^\n]s", expr);
    // printf("Your expression is: %s", expr);
    exprPtr = expr;
    printf("\n");
    while(*exprPtr != '\0'){
        printf("%c",*exprPtr);
        exprPtr++;
        if(*exprPtr != ' '){
            switch(op){
                case -1: (int) *exprPtr; break;
                case 0: sum += (int) *exprPtr; break;
                case 1: sum -= (int) *exprPtr; break;
                case 2: {if((int) *exprPtr == 0) {printf("Division by zero attempted.\n");
                            exit(0);}
                          else {sum /= (int) *exprPtr; break;}}
                case 3: sum *= (int) *exprPtr; break;
            }
            switch(*exprPtr){
             case '+': op=0;
                        break;
             case '-': op=1;
                        break;
             case '/': op=2;
                        break;
             case '*': op=3;
                        break;
              default: op = -1;  break;//printf("Input error - operator expected %cfound\n",* exprPtr);
                       // exit(0);
            }
        }
    }
  //  exprPtr = expr;
    // exprPtr = strtok (expr, " ");
  //  while( *exprPtr != '\0'){
  //    printf("%s\n",*exprPtr);
  //    ++exprPtr;
      /*
     printf("%s\n",exprPtr);
     if(j == 0){
       j = 1 -j;
       if((int) exprPtr < 0 || (int) exprPtr > 9){
         printf("Input error.\n");
         exit(0);
       }
     }
      exprPtr = strtok (NULL, " ");
      */
    /*
    while(expr != '\n'){
      if(expr != ' '){
        if(j == 0){
          j = 1 - j;
          expr -= 48;
          if(expr < 0 || expr > 9){
            printf("Input error - number expected %c found.\n", expr + 48);
            exit(0);
          }
          switch(op){
            case -1: sum = (int) expr; break;
            case 0: sum += (int) expr; break;
            case 1: sum -= (int) expr; break;
            case 2: if((int) expr == 0){
              printf("Division by zero attempted.\n");
              exit(0);
            }
            case 3: sum *= (int) expr; break;
          }
        }
        else{
          j = 1 - j;
          switch(expr){
            case '+': op = 0; break;
            case '-': op = 1; break;
            case '/': op = 2; break;
            case '*': op = 3; break;
            default: printf("Input error - operator expected %c found. \n",expr);
                    exit(0);
          }
        }
      }
      scanf("%c", &expr);
    }
    if(j == 0)
      printf("Input error - number expected end ofline found.\n");
    else
      printf("Value equals = %d",sum);
  exit(0);
  */
  sum -= 47;
  printf("\n%d",sum);
  return 0;
}
