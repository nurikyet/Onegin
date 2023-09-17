#ifndef TEXTVARIANTS_H_INCLUDED
#define TEXTVARIANTS_H_INCLUDED


static const char* MyFile = "artemonegin.txt";


void PrintingOriginalText(FILE *OneginFinal, struct data *info);
void FillingText(struct data *info);
void PrintSourceText(FILE *OneginFinal, struct data *info);

int  GetSizeFromFile(const char* MyFile);
int  GetNumberOfRows(struct data *info);

char* OpenBuffer( FILE* TextFile, struct data *info);


struct data
    {
    int size;
    int nrows;
    char **text;
    char* buffer;
    };


#endif // TEXTVARIANTS_H_INCLUDED
