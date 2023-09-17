#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <cctype>
#include <assert.h>
#include <string.h>

#include "OneginSortFile.h"
#include "TextVariants.h"

//-----------------------------------------------------------------------------

int GetSizeFromFile(const char* MyFile)
    {
    struct stat buff = {};
    stat(MyFile, &buff);
    return buff.st_size;
    }

//-----------------------------------------------------------------------------

void PrintSourceText(FILE *OneginFinal, struct data *info)
    {
    assert(*(info -> text) != NULL);
    for (int i = 0; i < (info -> nrows); i++)
        {
        fprintf(OneginFinal, "%s\n", (info -> text)[i]);
        }
    }

//-----------------------------------------------------------------------------

int GetNumberOfRows(struct data *info)
    {
    assert((info -> buffer) != NULL);
    info -> nrows = 1;
    for (int i = 0; i < (info -> size); i++)
        {
        if ((info -> buffer)[i] == '\n')
            {
            (info -> nrows)++;
            }
        }
    if ((info -> buffer)[(info -> size) - 1] == '\n')
        {
        (info -> nrows)--;
        }
    return (info -> nrows);
    }

//-----------------------------------------------------------------------------

void FillingText(struct data *info)
    {
    (info -> text)[0] = info -> buffer;
    int nline = 1;
    for (int i = 0; i < (info -> size); i++)
        {
        if ((info -> buffer)[i] == '\n')
            {
            (info -> text)[nline] = ((info -> buffer) + i + 1);
            (info -> buffer)[i] = '\0';
            nline++;
            }
        }
    }

//-----------------------------------------------------------------------------

void PrintingOriginalText(FILE *OneginFinal, struct data *info)
    {
    for (int i = 0; i < (info -> size); i++)
        {
        if ((info -> buffer)[i] == '\0')
            {
            fputc('\n', OneginFinal);
            }
        else
            {
            fputc((info -> buffer)[i], OneginFinal);
            }
        }
    }

//-----------------------------------------------------------------------------

char* OpenBuffer( FILE* TextFile, struct data *info)
    {
    (info -> buffer) = (char*) calloc((info -> size)+1, sizeof(char));
    size_t nread = fread((info -> buffer), sizeof(char), (info -> size), TextFile);
    assert((info -> buffer) != NULL);
    return (info -> buffer);
    }

//-----------------------------------------------------------------------------
