#include<stdlib.h>
#include<stdio.h>
unsigned power(unsigned x, unsigned y);

int main()
{
  unsigned x1=0;
  unsigned y1=0;
  if(power(x1,y1)!=1)
    exit(EXIT_FAILURE);

  unsigned x2=0;
  unsigned y2=4;
  if(power(x2,y2)!=0)
    exit(EXIT_FAILURE);

  unsigned x3=0;
  unsigned y3=-2;
  if(power(x3,y3)!=0)
    exit(EXIT_FAILURE);

  unsigned x4=3;
  unsigned y4=2;
  if(power(x4,y4)!=9)
    exit(EXIT_FAILURE);

  unsigned x5=-2;
  unsigned y5=2;
  if(power(x5,y5)!=4)
    exit(EXIT_FAILURE);

  unsigned x6=3;
  unsigned y6=0;
  if(power(x6,y6)!=1)
    exit(EXIT_FAILURE);

  unsigned x7=-3;
  unsigned y7=0;
  if(power(x7,y7)!=1)
    exit(EXIT_FAILURE);

  unsigned x8=2;
  unsigned y8=-2;
  if(power(x8,y8)!=0)
    exit(EXIT_FAILURE);

  unsigned x9=-2;
  unsigned y9=-2;
  if(power(x9,y9)!=0)
    exit(EXIT_FAILURE);
  unsigned ans;
  ans = power(10,5);
  if (ans !=100000)return EXIT_FAILURE;
		     
  exit(EXIT_SUCCESS);
}
