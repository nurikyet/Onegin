#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "FunnyColours.h"

const int size = 13;

void Sort(int data[], int left, int right);
void PrintoutPartition(int data[], int left, int right);
int  Partition(int data[], int first, int last);
int  Exchange(int data[], int left, int right);

int main()
    {
    int data[size] = {4, 18, 9, 0, 90, 8, 15, 88, 9, 7, 18, 1, 22};
    int first = 0;
    int last = size - 1;

    PrintoutPartition(data, first, last);
    printf("\n");

    Sort(data, first, last);
    }

//-----------------------------------------------------------------------------

void Sort(int data[], int left, int right)
    {
    assert(data != NULL);
    if (left < right)
        {
        int mid = Partition(data, left, right);
        Sort(data, left, mid);
        Sort(data, mid + 1, right);
        }
    }

//-----------------------------------------------------------------------------

int Partition(int data[], int left, int right)
    {
    int mid = data[(left + right)/2];
    while(left <= right)
        {
        while (data[left] < mid)
            {
            PrintoutPartition(data, left, right);
            left++;
            PrintoutPartition(data, left, right);
            }
        while (data[right] > mid)
            {
            PrintoutPartition(data, left, right);
            right--;
            PrintoutPartition(data, left, right);
            }
        if (left < right)
            {
            Exchange(data, left, right);
            left++;
            right--;
            }
        else
            {
            PrintoutPartition(data, left, right);
            return (right);
            PrintoutPartition(data, left, right);
            }
        }
    PrintoutPartition(data, left, right);
    return right;
    }

//-----------------------------------------------------------------------------

void PrintoutPartition(int data[], int left, int right)
    {
    for (int i = 0; i < size; i++)
        {
        if (i == (left + right)/2)
            {
            printf(COLOUR_WHITE("%d "), data[i]);
            }
        else if (i < left)
            {
            printf(COLOUR_BLUE("%d "), data[i]);
            }
        else if ((i == left) or (i == right))
            {
            printf(COLOUR_RED("%d "), data[i]);
            }
        else if (i > right)
            {
            printf(COLOUR_YELLOW("%d "), data[i]);
            }
        else
            {
            printf(COLOUR_GREEN("%d "), data[i]);
            }
        }
    printf("\n");
    }

//-----------------------------------------------------------------------------

int Exchange(int data[], int left, int right)
    {
    int third = data[left];
    data[left] = data[right];
    data[right] = third;
    }

//-----------------------------------------------------------------------------
