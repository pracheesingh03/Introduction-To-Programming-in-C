#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void decrypt(FILE *f)
{
  int c;
  int f1;
  int ans;
  int finalf=0;
  for(char a='a'; a<='z'; a++)
    {
      f1=0;
  while((c=fgetc(f)) != EOF)
    {
      if(isalpha(c))
	{
	  if(c==a) f1++;
	}
    }
  if(finalf<f1)
    {
      finalf=f1;
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
  FILE *f = fopen(argv[0], "r");
  if(f==NULL)
    {
      perror("could not open file");
      return EXIT_FAILURE;
    }
  decrypt(f);
  if(fclose(f)!=0)
    {
      perror("Failed to close file");
      return EXIT_FAILURE;
    }
  return EXIT_SUCCESS;
}
  
                
