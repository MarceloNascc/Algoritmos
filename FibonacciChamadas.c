#include <stdio.h>

int chamRe = 0;

int fibonacci(int fib){
  if(fib == 1){
    return 1;
  }
  if(fib == 0){
    return 0;
  }
   
  chamRe += 2;

  return fibonacci(fib - 1) + fibonacci(fib - 2);
}

int main(void) {
  int quanTest;
  scanf(" %d", &quanTest);

  int i;
  for(i = 0; i < quanTest; i++){
    int fib;
    scanf(" %d", &fib);

    chamRe = 0;
    int valorFib = fibonacci(fib);

    printf("fib(%d) = %d calls = %d\n", fib, chamRe, valorFib);
  }

  return 0;
}