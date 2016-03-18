// George Juarez - ICSI333 Lab #2
/*
  Assignment was to take a user's input and exchange for quarters, dimes, nickles, and pennies
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
  int inputNum, quarters, dimes, nickels, pennies;
  // prompt user for input and error check
  printf("Enter an int between 0 and 99: ");
  scanf(" %d",&inputNum);
  if(inputNum < 0 || inputNum > 99) exit(0);
  // begin making change
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
