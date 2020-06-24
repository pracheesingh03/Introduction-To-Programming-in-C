#include<stdio.h>
#include<stdlib.h>
size_t maxSeq(int * array, size_t n){
 int t=1; int  max=1;
  if(n==0) return 0;
  if (n==1) return 1;
  for(int i=0; i<n; i++)
    {
      if(array[i]<array[i+1])
	t++;
      else
	t=1;
      if (t> max)
	max=t;
	
    }
  return max;
}
     
