#include <stdio.h>
#include <stdlib.h>

typedef struct _retire_info
{
  int months;
  double contribution;
  double rate_of_return;
} retire_info;
  
void retirement(int startAge, double initial, retire_info working, retire_info retired)
{
  int i,j;
  for( i=startAge; i<(startAge+ working.months); i++)
    {
      printf("Age %3d  month %2d you have $%.2lf\n", i/12, i%12, initial);
	     initial= (initial* working.rate_of_return) + initial + working.contribution;
	     }
	for ( j= (startAge+ working.months); j< (startAge+ working.months+ retired.months); j++)
	  {
	    printf("Age %3d month %2d you have $%.2lf\n", j/12, j%12, initial);
	    initial= (initial* retired.rate_of_return) + initial + retired.contribution;
	  }
}

void main(){
  int startAge= 327;
  double savings= 21345;
  retire_info working, retired;
  working.months= 489;
  working.contribution= 1000;
  working.rate_of_return= (0.045/12);
  retired.months= 384;
  retired.contribution= -4000;
  retired.rate_of_return= (0.01/12);
  retirement(startAge, savings, working, retired);
  
}
