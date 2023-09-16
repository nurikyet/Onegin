#include <stdio.h>
#include <sys\stat.h>
#include <stdlib.h>
#include <cctype>
#include <assert.h>


// TODO: remove
#include "TXLib.h"

// TODO: Can you read file name from command line interface?
const char* MyFile = "textfile.txt";

void PrintSourceText(char **text, int NumberOfRows);
void SortingByQsort(char **text, int NumberOfRows);
void WorkWithText(char **text, char* buffer, int size);
void Qsort(char **text, int NumberOfRows);

int  GetSizeFromFile(FILE *TextFile);
int  GetNumberOfRows(char *buffer, int size);
int  Compare(const void * x1, const void * x2);
int  LeftRight(const char* str1, const char* str2);


//=============================================================================
// TODO: This file needs a lot of separation. Make sure to introduce it,
//       when it works) 

void Sort(char **text, int left, int right);

int  Partition(char **text, int first, int last);
int  Exchange(char **text, int left, int right);
int  Compare1(const void* x1, const void* x2);
int  RightLeft(const char* str1, const char* str2);
//=============================================================================


int main()
    {
    // NOTE: keep in mind, when separating this file that your code
    //       should be equally "interesting" everywhere.
    FILE *TextFile = fopen(MyFile, "rb");
    if (TextFile == NULL)
        {
        printf("Cannot open file.\n");
        return 1;
        }

    int size = GetSizeFromFile(TextFile);

    // TODO: I would rather write this '\0' explicitly.
    char *buffer = (char*) calloc(size+1, sizeof(char));
    size_t nread = fread(buffer, sizeof(char), size, TextFile);
    //     ^~~~~ TODO: naming style?

    assert( nread <= size);
    //     ^ TODO: what is this space?

    int NumberOfRows = GetNumberOfRows(buffer, size);
    //  ^~~~~~~~~~~~ TODO: naming style?

    char **text = (char**) calloc(NumberOfRows, sizeof(char*));
    WorkWithText(text, buffer, size);
    //PrintSourceText(text, NumberOfRows);
    SortingByQsort(text, NumberOfRows);

    PrintSourceText(text, NumberOfRows);

    Qsort(text, NumberOfRows);
    PrintSourceText(text, NumberOfRows);

    fclose(TextFile);
    free(text);
    free(buffer);
    }

//-----------------------------------------------------------------------------

int GetSizeFromFile(FILE *TextFile)
    {
    struct stat buff = {};
    stat(MyFile, &buff);
    return buff.st_size;
    }

//-----------------------------------------------------------------------------

void PrintSourceText(char **text, int NumberOfRows)
    {
    //assert(**text != NULL);
    for (int i = 0; i < NumberOfRows; i++)
        {
        printf("%s\n", text[i]);
        }
    }

//-----------------------------------------------------------------------------

int GetNumberOfRows(char *buffer, int size)
    {
    assert(*buffer != NULL);
    int NumberOfRows = 1;
    for (int i = 0; i < size; i++)
        {
        if (buffer[i] == '\n')
            {
            NumberOfRows++;
            }
        }
    return NumberOfRows;
    }

//-----------------------------------------------------------------------------

void WorkWithText(char **text, char* buffer, int size) // TODO: rename
    {
    text[0] = buffer;
    int nline = 1;
    for (int i = 0; i < size; i++)
        {
        if (buffer[i] == '\n')
            {
            text[nline] = (buffer + i + 1);
            //printf("Адрес из массива указателей text[%d] = %p\n", i, text[nline]);  //"Выводит адрес из массива указателей"
            //printf("Адрес из char-массива &buffer[%d+1] = %p\n", i, &buffer[i+1]); //"Выводит адрес из char-массива"
            //printf("Само значение в char-массиве buffer[%d] = %c\n", i, buffer[i+1]);
            buffer[i] = '\0';
            nline++;
            }
        }
    }

//-----------------------------------------------------------------------------

void SortingByQsort(char **text, int NumberOfRows) // TODO: name?
    {
    qsort((void *)text, NumberOfRows, sizeof(char*), Compare);
    }

//-----------------------------------------------------------------------------

int Compare(const void * x1, const void * x2)
    {
    return LeftRight( * ( char** ) x1, * ( char** ) x2 );
    }

//-----------------------------------------------------------------------------

int LeftRight(const char* str1, const char* str2)
    {
    size_t len1 = strlen(str1); // TODO: Why?
    size_t len2 = strlen(str2);

    size_t i = 0;
    size_t j = 0;

    while (true) // TODO: rethink
        {
        while (i < len1)
            {
            if ('a' <= str1[i] and str1[i] <= 'z') break;
            if ('A' <= str1[i] and str1[i] <= 'Z') break;
            //printf("Пропускаем элемент в строке str1: %c\n", str1[i]);
            i++;
            }
            //printf("Сравниваем последний буквенный элемент в строке str1: %c\n", str1[i]);
        while (j < len2)
            {
	    if ('a' <= str2[j] and str2[j] <= 'z') break; // TODO: tolower?
            if ('A' <= str2[j] and str2[j] <= 'Z') break;
            //printf("Пропускаем элемент в строке str2: %c\n", str2[j]);
            j++;
            }
            //printf("Сравниваем последний буквенный элемент в строке str2: %c\n", str2[j]);

        if (str1[i] > str2[j])
            {
            return 1;
            }
        else if (str1[i] < str2[j])
            {
            return -1;
            }
        else
            {
            i++;
            j++;
            }

        if (i >= len1 or j >= len2)
            {
            break;
            }
        }

    if (i < len1 && j < len2)
        {
        return str1[i] <= str2[j];
        }
    else if (i >= len1)
        {
        return -1;
        }
    else
        {
        return 1;
        }
    }

 //-----------------------------------------------------------------------------

// TODO: docs
void Qsort(char **text, int NumberOfRows /* TODO: can you pass comparator function? */ ) // TODO: rename
    {
    int first = 0;
    int last = NumberOfRows - 1;

    Sort(text, first, last);

    }


//-----------------------------------------------------------------------------


void Sort(char **text, int left, int right)
    {
    printf("%d %d\n", left, right);
    if (left < right)
        {
        int mid = Partition(text, left, right);
        Sort(text, left, mid);
        Sort(text, mid + 1, right);
        }
    }

//-----------------------------------------------------------------------------

int Partition(char **text, int left, int right)
    {
    char *mid = text[(left + right)/2]; // TODO: you can avoid overflows with: (right - left) / 2 + left
    while(left <= right)
        {
        while (Compare1(&text[left], &mid) && (right > left)) //(text[left] < mid)
	    { //                               ^~ TODO: it's better to write explicitly what you compare to "> 0"
            assert(right>left);
            left++;
            }
	while (Compare1(&text[right], &mid) && (right > left)) //(text[right] > mid) TODO: (later) is right > left necessary?
            {
	    assert(right > left); // TODO: Whyyyyyyyyyyyyyy
            right--;
            }
        if (left < right)
            {
            Exchange(text, left, right);
            left++;
            right--;
            }
        else
            {
            return right;
            }
        }

    return right;
    }

//-----------------------------------------------------------------------------

int Exchange(char **text, int left, int right) // TODO: can you make exchange universal?
    {
    char* third = text[left]; // TODO: can you generalize? And efficiently? NOTE: Duff's Device
    text[left] = text[right];
    text[right] = third;
    }

//-----------------------------------------------------------------------------

int Compare1(const void* x1, const void* x2)
    {
    return RightLeft( * ( char** ) x1, * ( char** ) x2 );
    }

//-----------------------------------------------------------------------------

int RightLeft(const char* str1, const char* str2) // TODO: start over with this one...
    {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    size_t i = len1;
    size_t j = len2;

    while (true)
        {
        while (i > 0)
            {
            if ('a' <= str1[i] and str1[i] <= 'z') break;
            if ('A' <= str1[i] and str1[i] <= 'Z') break;
            //printf("Пропускаем элемент в строке str1: %c\n", str1[i]);
            i--;
            }
            //printf("Сравниваем последний буквенный элемент в строке str1: %c\n", str1[i]);
        while (j > 0)
            {
            if ('a' <= str2[j] and str2[j] <= 'z') break;
            if ('A' <= str2[j] and str2[j] <= 'Z') break;
            //printf("Пропускаем элемент в строке str2: %c\n", str2[j]);
            j--;
            }
            //printf("Сравниваем последний буквенный элемент в строке str2: %c\n", str2[j]);

        if (str1[i] > str2[j])
            {
            return 1;
            }
        else if (str1[i] < str2[j])
            {
            return -1;
            }
        else
            {
            i--;
            j--;
            }

        if (i <= 0 and j <= 0)
            {
            break;
            }
        }

    if (i >= len1 && j >= len2)
        {
        return str1[i] > str2[j];
        }
    else if (i <= len1)
        {
        return -1;
        }
    else
        {
        return 1;
        }
    }

//-----------------------------------------------------------------------------
