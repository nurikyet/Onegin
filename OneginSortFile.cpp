#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <cctype>
#include <stdlib.h>

#include "OneginSortFile.h"
#include "TextVariants.h"


//-----------------------------------------------------------------------------

int Compare(const void* x1, const void* x2)
    {
    return RightLeft(( char* ) x1, ( char* ) x2 );
    }


//-----------------------------------------------------------------------------

int Partition(struct data *info, int left, int right, int (*Comparator)(const void* x1, const void* x2))
    {
    char *mid = (info -> text)[(right - left) / 2 + left];
    while(left <= right)
        {
        while (Comparator((info -> text)[left], mid) < 0)
            {
            left++;
            }
        while (Comparator((info -> text)[right], mid) > 0)
            {
            right--;
            }
        if (left < right)
            {
            Exchange(info, left, right);
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

int Exchange(struct data *info, int left, int right)
    {
    char* third = (info -> text)[left];
    (info -> text)[left] = (info -> text)[right];
    (info -> text)[right] = third;
    return 0;
    }

//-----------------------------------------------------------------------------

void Sort(struct data *info, int left, int right, int (*Comparator)(const void* x1, const void* x2))
    {
    if (left == right)
        {
        return;
        }
    else if (right - left == 1)
        {
        if (Comparator((info -> text)[left], (info -> text)[right]) > 0)
            {
            Exchange(info, left, right);
            }
        }
    else
        {
        int mid = Partition(info, left, right, Comparator);
        Sort(info, left, mid, Comparator);
        Sort(info, mid + 1, right, Comparator);
        }
    }

//-----------------------------------------------------------------------------

void MyQuickSort(struct data *info, int (*Comparator)(const void* x1, const void* x2))
    {
    int first = 0;
    int last = (info -> nrows) - 1;

    Sort(info, first, last, Comparator);

    }

//-----------------------------------------------------------------------------

int LeftRight(const char* str1, const char* str2)
    {
    int first  = 0;
    int second = 0;
    while(true)
        {
        while ( str1[first] != '\0' && isalpha(str1[first]) == 0)
            {
            first++;
            }
        while (str2[second] != '\0'  && isalpha(str2[second]) == 0)
            {
            second++;
            }
        if (tolower(str1[first]) == tolower(str2[second]) && str1[first] != '\0')
            {
            first++;
            second++;
            continue;
            }
        break;
        }
    return (tolower(str1[first]) - tolower(str2[second]));
    }

//-----------------------------------------------------------------------------

void SortByQsort(struct data *info)
    {
    qsort((void *)(info -> text), (info -> nrows), sizeof(char*), CompareLeft);
    }

//-----------------------------------------------------------------------------

int CompareLeft(const void * x1, const void * x2)
    {
    return LeftRight( * (const char**) x1, * (const char** ) x2 );
    }

//-----------------------------------------------------------------------------
/*
int RightRight(const char* str1, const char* str2)
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

*/
//-----------------------------------------------------------------------------

int RightLeft(const char* str1, const char* str2)  /////////////////&&&&&&&&&&&&&&&&
    {
    int first  = strlen(str1) -1;
    int second = strlen(str2) -1;
    while(true)
        {
        while ( str1[first] != '\0' && isalpha(str1[first]) == 0)
            {
            first--;
            }
        while (str2[second] != '\0'  && isalpha(str2[second]) == 0)
            {
            second--;
            }
        if (tolower(str1[first]) == tolower(str2[second]) && str1[first] != '\0')
            {
            first--;
            second--;
            continue;
            }
        break;
        }
    return (tolower(str1[first]) - tolower(str2[second]));
    }

