#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void decrypt(FILE *f)
{
  int c;
  int f;
  char ans;
  int finalf=0;
  for(char a='a'; a<='z'; a++)
    {
      f=0;
  while((c=fgets(f)) != EOF)
    {
      if(isalpha(c))
	{
	  if(c==a) f++;
	}
    }
  if(finalf<f)
    {
      finalf=f;
      ans=tolower(a);
    }
    }
  int key;
  key = ans- 'e';
  if(key<0)
    {
      key= key*(-1);
      key = 26- key;
    }
  printf("%d", key);
  
}
int main(int argc, char ** argv)
{
  if(argc !=1)
    {
      fprintf("Usage: input File name");
      return EXIT_FAILURE;
    }
  FILE *f = fopen(argv[], "r");
  if(f==NULL)
    {
      perror("could not open file");
      return EXIT FAILURE;
    }
  decrypt(f);
  if(fclose(f)!=0)
    {
      perror("Failed to close file");
      return EXIT_FAILURE;
    }
  return EXIT_SUCCESS;
}
  
                
