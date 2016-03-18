// George Juarez - ICSI333 Lab #2
#include <stdio.h>
#include <stdlib.h>

int main(void){
  int inputNum, quarters, dimes, nickels, pennies;
  printf("Enter an int between 0 and 99: ");
  scanf(" %d",&inputNum);
  if(inputNum < 0 || inputNum > 99) exit(0);
  quarters = inputNum / 25;
  inputNum = inputNum % 25;
  dimes = inputNum / 10;
  inputNum = inputNum % 10;
  nickels = inputNum / 5;
  inputNum = inputNum % 5;
  pennies = inputNum / 1;
  printf("This contains %d quarters, %d dimes, %d nickels, and %d pennies.",quarters,dimes,nickels,pennies);
  return 0;
}
