#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <cctype>
#include <assert.h>
#include <string.h>

#include "OneginSortFile.h"
#include "TextVariants.h"

const char* MyFile = "Onegin (1).txt";
const char* MyOutFile = "OneginFinal.txt";


//=============================================================================

int main()
    {
    FILE *TextFile = fopen(MyFile, "rb");
    if (TextFile == NULL)
        {
        printf("Cannot open file.\n");
        return 1;
        }

    int size = GetSizeFromFile(TextFile);
    char *buffer = OpenBuffer(TextFile, size);


    int nrows = GetNumberOfRows(buffer, size);

    char **text = (char**) calloc(nrows, sizeof(char*));
    FillingText(text, buffer, size);

    SortByQsort(text, nrows);
    FILE *OneginFinal = fopen(MyOutFile, "w");
    PrintSourceText(OneginFinal, text, nrows);

    fprintf(OneginFinal, "\n");
    fprintf(OneginFinal, "---------------------------------------------------------------------------------------");
    fprintf(OneginFinal, "\n");

    MyQuickSort(text, nrows);

    PrintSourceText(OneginFinal, text, nrows);

    fprintf(OneginFinal, "\n");
    fprintf(OneginFinal, "---------------------------------------------------------------------------------------");
    fprintf(OneginFinal, "\n");

    PrintingOriginalText(OneginFinal, buffer, size);

    fclose(TextFile);
    fclose(OneginFinal);
    free(text);
    free(buffer);
    }

//-----------------------------------------------------------------------------
/*
int GetSizeFromFile(FILE *TextFile)
    {
    struct stat buff = {};
    stat(MyFile, &buff);
    return buff.st_size;
    }

//-----------------------------------------------------------------------------

void PrintSourceText(FILE *OneginFinal, char **text, int nrows)
    {
    assert(*text != NULL);
    for (int i = 0; i < nrows; i++)
        {
        fprintf(OneginFinal, "%s\n", text[i]);
        }
    }

//-----------------------------------------------------------------------------

int GetNumberOfRows(char *buffer, int size)
    {
    assert(buffer != NULL);
    int nrows = 1;
    for (int i = 0; i < size; i++)
        {
        if (buffer[i] == '\n')
            {
            nrows++;
            }
        }
    return nrows;
    }

//-----------------------------------------------------------------------------

void FillingText(char **text, char* buffer, int size)
    {
    text[0] = buffer;
    int nline = 1;
    for (int i = 0; i < size; i++)
        {
        if (buffer[i] == '\n')
            {
            text[nline] = (buffer + i + 1);
            buffer[i] = '\0';
            nline++;
            }
        }
    }

//-----------------------------------------------------------------------------

void SortByQsort(char **text, int nrows)
    {
    qsort((void *)text, nrows, sizeof(char*), Compare);
    }

//-----------------------------------------------------------------------------

int Compare(const void * x1, const void * x2)
    {
    return LeftRight( * ( char** ) x1, * ( char** ) x2 );
    }

 //-----------------------------------------------------------------------------

void PrintingOriginalText(FILE *OneginFinal, char *buffer, int size)
    {
    for (int i = 0; i < size; i++)
        {
        if (buffer[i] == '\0')
            {
            fprintf(OneginFinal,"%c", '\n');
            }
        else
            {
            fputc(buffer[i], OneginFinal);
            }
        }
    }

//-----------------------------------------------------------------------------


int LeftRight(const char* str1, const char* str2)
    {
    int first  = 0;
    int second = 0;
    while ( str1[first] != '\0' && isalpha(str1[first]) == 0)
        {
        first++;
        }
    while (str2[second] != '\0'  && isalpha(str2[second]) == 0)
        {
        second++;
        }
    return (str1[first] - str2[second]);
    }

*/
//-----------------------------------------------------------------------------

