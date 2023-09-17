#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <cctype>
#include <stdlib.h>

#include "OneginSortFile.h"
#include "TextVariants.h"


//-----------------------------------------------------------------------------

int CompareRight(const void* x1, const void* x2)
    {
    return RightLeft(( char* ) x1, ( char* ) x2 );
    }


//-----------------------------------------------------------------------------

int Partition(char **text, int left, int right)
    {
    char *mid = text[(right - left) / 2 + left];
    while(left <= right)
        {
        while (CompareRight(text[left], mid) < 0)
            {
            left++;
            }
        while (CompareRight(text[right], mid) > 0)
            {
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

int Exchange(char **text, int left, int right)
    {
    char* third = text[left];
    text[left] = text[right];
    text[right] = third;
    return 0;
    }

//-----------------------------------------------------------------------------

void Sort(char **text, int left, int right, int (*CompareRight)(const void* x1, const void* x2))
    {
    if (left == right)
        {
        return;
        }
    else if (right - left == 1)
        {
        if (CompareRight(text[left], text[right]) > 0)
            {
            Exchange(text, left, right);
            }
        }
    else
        {
        int mid = Partition(text, left, right);
        Sort(text, left, mid, CompareRight);
        Sort(text, mid + 1, right, CompareRight);
        }
    }

//-----------------------------------------------------------------------------

void MyQuickSort(char **text, int nrows)
    {
    int first = 0;
    int last = nrows - 1;

    Sort(text, first, last, CompareRight);

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



//-----------------------------------------------------------------------------

void SortByQsort(char **text, int nrows)
    {
    qsort((void *)text, nrows, sizeof(char*), CompareLeft);
    }

//-----------------------------------------------------------------------------

int CompareLeft(const void * x1, const void * x2)
    {
    return LeftRight( * ( char** ) x1, * ( char** ) x2 );
    }

//-----------------------------------------------------------------------------

int RightLeft(const char* str1, const char* str2)
    {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int i = len1-1;
    int j = len2-1;

    while (true)
        {
        while (i > 0)
            {
            if (isalpha(str1[i])) break;
            i--;
            }
        if (isalpha(str1[i]) == 0)
            {
            i--;
            }

        while (j > 0)
            {
            if (isalpha(str2[j])) break;
            j--;
            }
        if (isalpha(str2[j]) == 0)
            {
            j--;
            }

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

        if ((i < 0) || (j < 0))
            {
            break;
            }
        }

    if ((i < 0) && (j >= 0))
        {
        return -1;
        }
    else if ((i >= 0) && (j < 0))
        {
    return 1;
        }
    else
        {
        return 0;
        }

    }
