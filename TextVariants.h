#ifndef TEXTVARIANTS_H_INCLUDED
#define TEXTVARIANTS_H_INCLUDED

void PrintingOriginalText(FILE *OneginFinal, char *buffer, int size);
void FillingText(char **text, char* buffer, int size);
void PrintSourceText(FILE *OneginFinal, char **text, int nrows);

int  GetSizeFromFile(FILE *TextFile);
int  GetNumberOfRows(char *buffer, int size);

char* OpenBuffer( FILE* TextFile, int size);

#endif // TEXTVARIANTS_H_INCLUDED
