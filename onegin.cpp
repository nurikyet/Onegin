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
