#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int decrypt(FILE *f)
{
  int c;
  int f1;
  //int ans;
  //int finalf=0;
  int arr[26];
  for (int i=0; i<26; i++)
    {
      arr[i]=0;
    }
  while((c=fgetc(f))!=EOF)
    {
      if(isalpha(c))
	{
	  c=tolower(c);
	  arr[c-'a']++;
	}
    }
  int max=0;
  for(int j=0; j<26; j++)
    {
      if(arr[j]>max)
	{
	max= arr[j];
	f1=j;
    }
    }
     int key= f1-4;//4 is the index of e
  /*
  for(char a='a'; a<='z'; a++)
    {
      f1=0;
  while((c=fgetc(f)) != EOF)
    {
      if(isalpha(c))
	{
	  c = tolower(c);
	  if(c==(int)a) f1++;
	}
    }
  
  if(finalf<f1)
    {
      finalf=f1;
      ans= a;
    }
    }
  if(finalf==0)
    {
      fprintf(stderr, "no alphabets");
      return EXIT_FAILURE;
    }
  int key;
  char e= 'e';
  int ascii= (int)e;
  key= ans - ascii;
  */
  if(key<0)
    key = key + 26;
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
  if(key>=26)
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
  
                
