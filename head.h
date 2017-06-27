///\file head.h
///\brief librarie pentru toate functiile utilizate in program.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <time.h>
//SIZE_MAX/5
int stringlength(char *);
void stringconcatenate(char *,char *);
void stringcopy(char *,char *);
void filegetstring(char *,char []);
int mem_aloc(char *);
int stringcompare(char *,char *);
char* stringcharsearch(char *,char );
char* stringstringsearch(char *,char *);
void genereaza();
FILE *file,*file1;
