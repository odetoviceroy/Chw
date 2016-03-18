// George Juarez - Lab 6

#include <stdio.h>
#include <stdlib.h>

int main(void){
  float a, b, c, d, e, f;
  int det;
  printf("Enter your numbers: ");
  scanf("%f %f %f %f %f %f",&a,&b,&c,&d,&e,&f);
  float coefArr[2][2]  = {
                          {a,b},
                          {d,e} };
  float constArr[2] = {c,f};
  float TEMPconstArr[2] = {c,f};
  det = (coefArr[0][0] * coefArr[1][1]) - (coefArr[0][1] * coefArr[1][0]);
  if(det == 0){
    printf("\nToo complicated. Try again. \n");
    exit(0);
  }
  else{
    constArr[0] = (( (coefArr[1][1] * TEMPconstArr[0]) - (TEMPconstArr[1]* coefArr[0][1]) ) / det);
    constArr[1] = (( (coefArr[0][0] * TEMPconstArr[1]) - (TEMPconstArr[0]* coefArr[1][0]) ) / det);
    printf("\nX = %f", constArr[0]);
    printf("\nY = %f\n", constArr[1]);
  }
  return 0;
}
