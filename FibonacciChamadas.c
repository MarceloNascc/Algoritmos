//URI 1029
#include <stdio.h>

int fibs[40];
int chamRe[40];

int quantGuar = 2;

int fibonacci(int fib){
  if(fib == 1){
    return fibs[1];
  }
  if(fib == 0){
    return fibs[0];
  }
    
  if(fib < quantGuar){
    return fibs[fib];
  }

  fibs[fib] = fibonacci(fib - 2) + fibonacci(fib - 1);
  quantGuar++;

  chamRe[fib] = 2 + chamRe[fib - 1] + chamRe[fib - 2];
    
  return fibs[fib];
}

int main(void) {
  fibs[0] = 0;
  fibs[1] = 1;

  chamRe[0] = 0;
  chamRe[1] = 0;
    
  int quanTest;
  scanf(" %d", &quanTest);

  int i;
  for(i = 0; i < quanTest; i++){
    int fib;
    scanf(" %d", &fib);

    int valorFib = fibonacci(fib);

    printf("fib(%d) = %d calls = %d\n", fib, chamRe[fib], valorFib);
  }

  return 0;
}