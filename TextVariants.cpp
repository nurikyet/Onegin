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

void PrintSourceText(FILE *OneginFinal, struct textdata *info)
    {
    for (int i = 0; i < (info -> nrows); i++)
        {
        fprintf(OneginFinal, "%s\n", (info -> keeper)[i].string);
        }
    }

//-----------------------------------------------------------------------------

int GetNumberOfRows(struct textdata *info)
    {
    assert((info -> buffer) != NULL);
    info -> nrows = 0;
    for (int i = 0; i < (info -> size); i++)
        {
        if ((info -> buffer)[i] == '\n')
            {
            (info -> nrows)++;
            }
        }

    return (info -> nrows);
    }

//-----------------------------------------------------------------------------

void FillingText(struct textdata *info)
    {
    ((info -> keeper)[0].string) = info -> buffer;
    int nline = 1;
    int counter = 0;
    for (int i = 0; (i < (info -> size)) && (nline < (info -> nrows)); i++)
        {
        if ((info -> buffer)[i] == '\n')
            {
            (info -> keeper)[nline - 1].len = counter;
            counter = 0;
            ((info -> keeper)[nline].string) = ((info -> buffer) + i + 1);
            (info -> buffer)[i] = '\0';
            nline++;
            }
        counter++;
        }
    (info -> keeper)[info -> nrows - 1].len = ((info -> buffer) + (info -> size) - 1) - (info -> keeper)[info -> nrows - 1].string;
    }


//-----------------------------------------------------------------------------

void PrintOriginalText(FILE *OneginFinal, struct textdata *info)
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

char* OpenBuffer( FILE* TextFile, struct textdata *info)
    {
    (info -> buffer) = (char*) calloc((info -> size)+1, sizeof(char));
    (info -> size) = fread((info -> buffer), sizeof(char), (info -> size), TextFile);
    if ((info -> buffer)[info -> size - 1] != '\n')
        {
        (info -> size)++;
        (info -> buffer)[info -> size - 1] = '\n';
        }

    return (info -> buffer);
    }

//-----------------------------------------------------------------------------
