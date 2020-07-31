#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvpair_t *split(char *line){
  char *a = strchr(line,'=');
  *a= '\0';
  a++;
  char *b = strchr(a,'\n');
  if (b!=NULL) *b='\0';

  kvpair_t *pair= malloc((size_t) sizeof(*pair));
  pair ->key= line;
  pair ->value= a;
  return pair;  
}
  

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE *f = fopen(fname, "r");
  if (f==NULL){
    perror("Could not open file");
    return NULL;
  }
  char *line = NULL;
  kvpair_t *pair = NULL;
  size_t sz=0;

  kvarray_t *array= malloc((size_t) sizeof(*array));
  (*array).arr = NULL;
  (*array).length = 0;
  
  while(getline(&line, &sz, f)>=0)
    {
      pair= split(line);
      (*array).arr= realloc((*array).arr,((*array).length+1) * sizeof((*array).arr));
      (*array).arr[(*array).length] = pair;
      line = NULL;
      (*array).length++;
     
    }
  free(line);


  if(fclose(f)!=0)
    {
      perror("Failed to close file");
      return NULL;
    }
  return array;   
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0; i<(*pairs).length; i++)
    {
      free(pairs -> arr[i] -> key);
      free ((*pairs).arr[i]);
    }
  free((*pairs).arr);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  kvpair_t *pair;
  for(int i=0; i<(*pairs).length; i++){
    pair = (*pairs).arr[i];
    printf("key = '%s' value = '%s'\n",(*pair).key, (*pair).value);
  }
}


char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  kvpair_t *pair;
  for(int i=0; i<(*pairs).length; i++){
    pair = (*pairs).arr[i];
    if (! strcmp((*pair).key,key)) return  (*pair).value;
  }
  return NULL;
}
