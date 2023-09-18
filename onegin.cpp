#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <cctype>
#include <assert.h>
#include <string.h>

#include "OneginSortFile.h"
#include "TextVariants.h"

static const char* MyOutFile = "OneginFinal.txt";

int main()
    {
    struct textdata info = {};

    FILE *TextFile = fopen(MyFile, "rb");
    if (TextFile == NULL)
        {
        printf("Cannot open file - \"%s\".\n", MyFile);
        return 1;
        }
    printf("I output the file \"%s\".\n", MyFile);
    info.size = GetSizeFromFile(MyFile);
    info.buffer = OpenBuffer(TextFile, &info);

    info.nrows = GetNumberOfRows(&info);

    info.keeper = (struct lines*) calloc(info.nrows, sizeof(struct lines));
    FillingText(&info);
    SortByQsort(&info);

    FILE *OneginFinal = fopen(MyOutFile, "w");
    PrintSourceText(OneginFinal, &info);

    fprintf(OneginFinal, "---------------------------------------------------------------------------------------");

    MyQuickSort(&info, Compare);

    PrintSourceText(OneginFinal, &info);

    fprintf(OneginFinal, "---------------------------------------------------------------------------------------");

    PrintOriginalText(OneginFinal, &info);

    fclose(TextFile);
    fclose(OneginFinal);
    free(info.keeper);
    free(info.buffer);
    }
