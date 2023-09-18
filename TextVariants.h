#ifndef TEXTVARIANTS_H_INCLUDED
#define TEXTVARIANTS_H_INCLUDED

static const char* MyFile = "artemonegin.txt";

void PrintOriginalText(FILE *OneginFinal, struct textdata *info);
void FillingText(struct textdata *info);
void PrintSourceText(FILE *OneginFinal, struct textdata *info);

int  GetSizeFromFile(const char* MyFile);
int  GetNumberOfRows(struct textdata *info);

char* OpenBuffer( FILE* TextFile, struct textdata *info);

struct textdata
    {
    int size;
    int nrows;
    char* buffer;
    //char **text;
    struct lines* keeper;
    };

struct lines
    {
    char* string;
    int len;
    };



#endif // TEXTVARIANTS_H_INCLUDED
