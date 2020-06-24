#include<stdio.h>
#include<stdlib.h>
size_t maxSeq(int * array, size_t n){
 int t=1; int  max=1;
  if(n==0) return 0;
 
  for(int i=0; i<n; i++)
    {
      if(array[i]<array[i+1])
	t++;
 else if(array[i]>array[i+1])
	{
	max= t;
	t=1;
	}
    }
  return max;
}
     
