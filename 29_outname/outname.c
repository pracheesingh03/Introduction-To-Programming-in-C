#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME

  char * outputname= malloc((strlen(inputName)+7)* sizeof(*outputname));
  strcpy(outputname, inputName);
  strcat(outputname, ".counts");
  return outputname; 
}
