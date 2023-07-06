// Adapted from Programs and Data Structures in C by Leendert Ammeraal

/* USING A SENTINEL IN LINEAR SEARCH 
   Assume that N is defined, the array has values, and x (the 
   searched value) is provided. 
*/
int a[N+1], x, i; /* initialize array with extra element */
/* ... */
a[N] = x; /* set that extra element to the searched value. */
i = 0; /* loop over the array until x is matched, with a guaranteed match
          occupying the last element. */
while (x != a[i])   /* Using a sentinel is faster than using          */
{ i++;              /*     while (i < N && a[i] != x) i++;            */ 
}                   /* because only one check occurs every loop.      */
      /* if i != N, a[i] is first occurence of x. Otherwise, there's no x. */

/* USING A SENTINEL IN COMPARISONS
   Assume (1) that a[] and b[] have values, (2) that i and j are defined as 
   the beginning indexes to compare for a and b respectively, and (3) that 
   n is provided as the length of the sequence. That is, we compare the values
   in a[i] through a[i+(n-1)] to the values in  b[j] through b[j+(n-1)].
*/
int equalseq(int *p, int *q, int n)
{ int temp, *qn; // initialize temp
  qn = q + n; 
  temp = *qn;
  *qn = *(p+n) + 1;
  while (*p++ == *q++)
  { // ;
  }
  *qn = temp /* Restore old q[n] */
  return q > qn;
}


