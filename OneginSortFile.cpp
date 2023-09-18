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
    return RightLeft(x1, x2);
    }

//-----------------------------------------------------------------------------

int Partition(struct textdata *info, int left, int right, int (*Comparator)(const void* x1, const void* x2))
    {
    char *mid = ((info -> keeper)[(right - left) / 2 + left]).string;
    while(left <= right)
        {
        while (Comparator((info -> keeper)[left].string, mid) < 0)
            {
            left++;
            }
        while (Comparator((info -> keeper)[right].string, mid) > 0)
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

int Exchange(struct textdata *info, int left, int right)
    {
    char* third = (info -> keeper)[left].string;
    (info -> keeper)[left].string = (info -> keeper)[right].string;
    (info -> keeper)[right].string = third;
    return 0;
    }

//-----------------------------------------------------------------------------

void Sort(struct textdata *info, int left, int right, int (*Comparator)(const void* x1, const void* x2))
    {
    if (left == right)
        {
        return;
        }
    else if (right - left == 1)
        {
        if (Comparator((info -> keeper)[left].string, (info -> keeper)[right].string) > 0)
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

void MyQuickSort(struct textdata *info, int (*Comparator)(const void* x1, const void* x2))
    {
    int first = 0;
    int last = (info -> nrows) - 1;
    Sort(info, first, last, Comparator);
    }

//-----------------------------------------------------------------------------

int LeftRight1(const void *x1, const void *x2)
    {
    const struct lines *str1 = (const struct lines *)x1;
    const struct lines *str2 = (const struct lines *)x2;

    int first  = 0;
    int second = 0;

    while(true)
        {
        while ((str1 -> string)[first] != '\0' && isalpha((str1 -> string)[first]) == 0)
            {
            first++;
            }
        while ((str2 -> string)[second] != '\0'  && isalpha((str2 -> string)[second]) == 0)
            {
            second++;
            }
        if (tolower((str1 -> string)[first]) == tolower((str2 -> string)[second]) && (str1 -> string)[first] != '\0')
            {
            first++;
            second++;
            continue;
            }
        break;
        }
    return (tolower((str1 -> string)[first]) - tolower((str2 -> string)[second]));
    }

//-----------------------------------------------------------------------------

void SortByQsort(struct textdata *info)
    {
    qsort((void *)(info -> keeper), (info -> nrows), sizeof(struct lines), CompareLeft);
    }

//-----------------------------------------------------------------------------

int CompareLeft(const void* x1, const void* x2)
    {
    return LeftRight( x1, x2);
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

int RightLeft(const void *x1, const void *x2)//const struct lines *str1, const struct lines *str2)
    {
    const struct lines *str1 = (const struct lines *)x1;
    const struct lines *str2 = (const struct lines *)x2;

    int first  = (str1 -> len) -1;
    int second = (str2 -> len) -1;
    while(true)
        {
        while ((first >= 0) && isalpha((str1 -> string)[first]) == 0)
            {
            first--;
            }
        while ((second >= 0) && isalpha((str2 -> string)[second]) == 0)
            {
            second--;
            }
        if (tolower((str1 -> string)[first]) == tolower((str2 -> string)[second]) && (first >= 0))
            {
            first--;
            second--;
            continue;
            }
        break;
        }
    return (tolower((str1 -> string)[first]) - tolower((str2 -> string)[second]));
    }

//-----------------------------------------------------------------------------

int LeftRight(const void *x1, const void *x2)
    {
    const struct lines *str1 = (const struct lines *)x1;
    const struct lines *str2 = (const struct lines *)x2;

    int first  = -1;
    int second = -1;

    do
        {
        first++;
        second++;
        while ((str1 -> string)[first] != '\0' && isalpha((str1 -> string)[first]) == 0)
            {
            first++;
            }
        while ((str2 -> string)[second] != '\0'  && isalpha((str2 -> string)[second]) == 0)
            {
            second++;
            }
        }
    while(tolower((str1 -> string)[first]) == tolower((str2 -> string)[second]) && (str1 -> string)[first] != '\0');

    return (tolower((str1 -> string)[first]) - tolower((str2 -> string)[second]));
    }


//-----------------------------------------------------------------------------


