#include<test-subseq.c>
size_t maxSeq(int * array, size_t n){
  size_t t=0;
  if(n==0) return 0;
  if(n==1) return 1;
  for(i=0; i<n; i++)
    {
      if(array[i]<array[i+1])
	t++;
 else if(array[i]>array[i+1])
	{
	size_t max= t;
	t=0;
	}
    }
  return max;
}
     
