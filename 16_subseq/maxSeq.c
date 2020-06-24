#include<stdio.h>
#include<stdlib.h>
size_t maxSeq(int * array, size_t n){
  size_t t=1; size_t max=1;
  if(n==0) return 0;
 
  for(int i=0; i<n; i++)
    {
      if(array[i]<array[i+1])
	t++;
 else if(array[i]>array[i+1])
	{
	max= t;
	t=0;
	}
    }
  return max;
}
     
