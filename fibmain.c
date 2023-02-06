#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_INPUT_VAL 1000

//three methods
int iter(int n);
int recur(int n);
int recur_cache(int n);

int main(int argc, char *argv[]) {

  long num = strtol(argv[1], NULL, 10);
  int fibN, results, new_num = num;
  char method;
  FILE *fname;

  method = argv[2][0];
  fname = fopen(argv[3], "r");

  if (fname == NULL) {
    printf("File %s cannot be opened\n", argv[3]);
    exit(1);
  }
  
  while (!feof(fname)) {
    int cy;
    fscanf(fname, "%d", &cy);
    printf("(%d) is retrieved.\n", cy);

    fibN = (num+cy);
  }
  fclose(fname);

  printf("Fib(%d) will now be calculated using %c method.\n", fibN, method);

  switch(method) {
    case 'i':
      results = iter(fibN);
      break;
    case 'r':
      results = recur(fibN);
      break;
    case 'c':
      results = recur_cache(fibN);
      break;
    default:
      printf("Argument is not valid.\n");
  }
  printf("The result = %d\n", results);

  return 0;
}

//using the iteration method
int iter(int n) {
  int first = 1, second = 1, output = 0, i;

    if(n <= 2) 
      return 1;
    for(int i = 1; i < n; ++i) {
      output = first + second;
      first = second;
      second = output;
      }
  return first;
}

//using the recursive method
int recur(int n) {
  if(n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return (recur(n-1) + recur(n-2));
  }
}

//using the recursive cache method
int cache_result[MAX_INPUT_VAL];
int recur_cache(int n) {
  
  if (n <= 0 || n <= 1)
   return n;
  if (cache_result[n] != 0) {
    return cache_result[n];
  }
  
  int output2 = recur_cache(n-1) + recur_cache(n-2);
  cache_result[n] = output2;

  printf("The results of fib(%d) = %d\n", n, cache_result[n]);

  return output2;
}
