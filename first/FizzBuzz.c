#include <stdio.h>
#define Fizz -1
#define Buzz -2
#define FizzBuzz -3
int func(int num){
   if(num %15 ==0)
      return FizzBuzz;
   else
    if(num %3 ==0)
      return Fizz;
    else
    if(num %5 ==0 )
        return Buzz;
    else
    return num;
}
int main( ){
    for(int i=1;i<=100;i++){
        int res=func(i);
        if(res==Fizz)
            printf("Fizz\n");
        else if(res==Buzz)
            printf("Buzz\n");
        else if(res==FizzBuzz)
            printf("FizzBuzz\n");
        else
            printf("%d\n",res);
    }
}