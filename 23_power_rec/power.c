#include<stdlib.h>
#include<stdio.h>
unsigned power(unsigned x, unsigned y)
{
  if(x==0 && y==0) return 1;
  else if(x==0 && y!=0) return 0;
  else if(x!=0 && y==0) return 1;
  else if(x!=0 && y<0) return 0;
  else {
    while(y!=0)
      return x*power(x,y-1);
  }
}






