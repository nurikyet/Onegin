#include <stdio.h>
#include <assert.h>
#include "FunnyColours.h"

const int size = 13;

int  Exchange(int data[], int left, int right); // предназначена для обмена left и right
void Sort(int data[], int left, int right);
int  Partition(int data[], int first, int last);
void PrintoutPartition(int data[], int left, int right); //предназначена для цветного вывода в случае ошибки


int main()
    {
    int data[size] = {4, 18, 9, 0, 90, 8, 15, 88, 9, 7, 18, 1, 22};
    int first = 0;
    int last = size - 1;
    for (int i = 0; i < size; i++)
        {
        printf("%d ", data[i]);
        }
    printf("\n");
    Sort(data, first, last);
    }

//-----------------------------------------------------------------------------


void Sort(int data[], int first, int last)
    {
    if (first < last)
        {
        int mid = Partition(data, first, last);
        Sort(data, first, mid);
        Sort(data, mid + 1, last);
        }
    }

//-----------------------------------------------------------------------------

int Partition(int data[], int first, int last)
    {
    int left = first;
    int right = last;
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
        if (left >= right)
            {
            PrintoutPartition(data, left, right);
            return (right);
            PrintoutPartition(data, left, right);
            }
        Exchange(data, left, right);
        left++;
        right--;
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

int Exchange(int data[], int left, int right) //предназначено для обмена left и right через третий элемент
    {
    int third = data[left];
    data[left] = data[right];
    data[right] = third;
    }
