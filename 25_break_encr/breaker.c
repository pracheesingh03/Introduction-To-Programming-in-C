#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int decrypt(FILE *f)
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
  if(finalf==0)
    {
      fprintf(stderr, "no alphabets");
      return EXIT_FAILURE;
    }
  int key;
  /*
  key= ans - 'e';
  if(key<0)
    {
      key= key*(-1);
      key = 26- key;
    }
  */
  key = ans- 'a';
  if (key>0)
      key = (key+22)%26;
  else key = key + (((-key)+22)%26);
  return key;
}
int main(int argc, char ** argv)
{
  if(argc !=2)
    {
      fprintf(stderr, "Usage: input File name");
      return EXIT_FAILURE;
    }
  FILE *f = fopen(argv[1], "r");
  if(f==NULL)
    {
      perror("could not open file");
      return EXIT_FAILURE;
    }
  int key=  decrypt(f);
  if(key>26)
    {
      fprintf(stderr, "Invalid key");
      return EXIT_FAILURE;
    }
  printf("%d", key);
  if(fclose(f)!=0)
    {
      perror("Failed to close file");
      return EXIT_FAILURE;
    }
  return EXIT_SUCCESS;
}
  
                
