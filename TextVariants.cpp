#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <cctype>
#include <assert.h>
#include <string.h>

#include "OneginSortFile.h"
#include "TextVariants.h"

//-----------------------------------------------------------------------------

int GetSizeFromFile(FILE *TextFile)
    {
    struct stat buff = {};
    stat("Onegin (1).txt", &buff);
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

char* OpenBuffer( FILE* TextFile, int size)
    {
    char *buffer = (char*) calloc(size+1, sizeof(char));
    size_t nread = fread(buffer, sizeof(char), size, TextFile);
    assert( nread <= size);
    return buffer;
    }

//-----------------------------------------------------------------------------
