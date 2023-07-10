/* This program is a good example of measuring the efficiency of equivalent
   solutions to the same problem. The computing time of equivalent factorial
   algorithms (recursive and non-recursive) is compared.
*/
#include <time.h>
#include <stdio.h>

int main()
{ long long int t0, t1;
  int n, k, i, dt;
  double f, recfac(int), itfac(int);
  printf("Enter the value of n, to compute n! :");
  scanf("%d", &n);
  printf("How many times do you want %d! to be computed? :", n);
  scanf("%d", &k);
  
  time(&t0);
  for (i = 0; i < k; i++)
  { f = recfac(n);
  }
  time(&t1);
  dt = t1 - t0;
  printf("Recursion: %d! = %1.0f    time = %d s\n", n, f, dt);
  
  time(&t0);
  for (i = 0; i < k; i++)
  { f = itfac(n);
  }
  time(&t1);
  dt = t1 - t0;
  printf("Iteration: %d! = %1.0f    time = %d s\n", n, f, dt);
}

double recfac(int n)
{ return n > 1 ? n * recfac(n-1) : 1.0;
}

double itfac(int n)
{ double product = 1.0;
  while (n > 1)
  { product *= n--;
  }
  return product;
}
  

