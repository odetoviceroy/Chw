// George Juarez - ICSI333 HW #2
// My code works for 2016, which is a leap year.

#include <stdio.h>
#include <stdlib.h>

//define functions and the number of days in each month of the year

int calendar[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
void checkDate(int, int);
int findMonthDiff(int);
void findDayDiff(int, int, int, int);

int main(void){
// prompt user to enter two dates, and then error check
  int month1, day1, month2, day2;
  printf("Enter the number of the first month following by the day number (mm dd): ");
  scanf("%d %d", &month1, &day1);
  checkDate(month1, day1);
  printf("\nEnter the number of the second month following the day number (mm dd): ");
  scanf("%d %d", &month2, &day2);
  checkDate(month2, day2);
// find difference between two dates in 2016
  findDayDiff(month1, month2, day1, day2);
  return 0;
}

void checkDate(int month, int day){
  // check if month is valid
  if(month > 12 || month < 1) {
    printf(" \n Not a valid date. \n");
    exit(0);
  };
  // check if these months do not exceed 31 days
  if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
    if(day > 31) {
      printf(" \nNot a valid date. \n");
      exit(0);
    }
    else return;
  }
  // check if these months do not exceed 30 days
  if(month == 4 || month == 6 || month == 9 || month == 11){
    if(day > 30){
      printf(" \nNot a valid date. \n");
      exit(0);
    }
    else return;
  }
  // check if February does not exceed 29 days
  if(month == 2){
    if(day > 29){
      printf(" \nNot a valid date. \n");
      exit(0);
    }
    else return;
  }
  return;
}

int findMonthDiff(int month){
  int temp = 0;
  int i;
  // pull out difference in months from array in line 9
  for(i = 0; i < month -1 ; i++){
    if(i == 1){ temp += 29;}
    else temp += calendar[i];
  }
  return temp;
}

void findDayDiff(int m1, int m2, int d1, int d2){
  int count = 0;
  // find difference between first and second month
  count = count - findMonthDiff(m1);
  count = count - d1;
  count = count + findMonthDiff(m2);
  count += d2;
  // I could have used absolute value as well for this
  if(count < 0) count = count * -1;
  // print out result
  printf(" \nThe no. of days between the 2 dates is %d days.",count);
  return;
}
