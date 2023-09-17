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
    struct data info = {};

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

    info.text = (char**) calloc(info.nrows, sizeof(char*));
    FillingText(&info);

    SortByQsort(&info);
    FILE *OneginFinal = fopen(MyOutFile, "w");
    //assert(OneginFinal);
    PrintSourceText(OneginFinal, &info);

    //assert(fprintf(OneginFinal, "\n"));
    fprintf(OneginFinal, "---------------------------------------------------------------------------------------");
    fprintf(OneginFinal, "\n");

    MyQuickSort(&info, Compare);

    PrintSourceText(OneginFinal, &info);

    fprintf(OneginFinal, "\n");
    fprintf(OneginFinal, "---------------------------------------------------------------------------------------");
    fprintf(OneginFinal, "\n");

    PrintingOriginalText(OneginFinal, &info);

    fclose(TextFile);
    fclose(OneginFinal);
    free(info.text);
    free(info.buffer);
    }
