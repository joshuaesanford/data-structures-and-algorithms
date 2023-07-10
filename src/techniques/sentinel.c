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
{ int temp, *qn; 
  qn = q + n; /* since we count the initial position, q + n is one place beyond the last
                 element being compared. */
  temp = *qn; /* we change qn in order to guarantee a non-equivalence. thus, we must save
                 a temp value in order to set qn back to the original value. */
  *qn = *(p+n) + 1; /* q[n] and p[n] are now guaranteed to differ. */
  while (*p++ == *q++)
  { /* this compact while loop first tests to see if the value at p and q are equivalent.
       it then increments the address values of both p and q. if p and q were equivalent, 
       then this process continues until they are not equivalent (which is guaranteed after n
       iterations). p and q are still incremented before control flow moves beyond the scope
       of the loop. thus, when p[n] != q[n], which is guaranteed, q is incremented to q[n+1].
       q[n+1] equals (qn + 1) and will have a value greater than qn. Thus, when q > qn,
       the tested sequence is equivalent and the function returns true. If an earlier 
       condition fails, then q is less than qn and the function returns false.*/ 
  }
  *qn = temp /* Restore old q[n] */
  return q > qn;
}
