#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <sys\stat.h>
#include "FunnyColours.h"

const char* MyFile = "numberfile.txt";

void Sort(int *data, int left, int right, FILE *NumberFile, int massize);
void PrintoutPartition(int data[], int left, int right, FILE *NumberFile, int massize);
void ReadElements(FILE *NumberFile, int massize, int *data);

int  ReadFromFile(FILE *NumberFile, int size);
int  Partition(int *data, int first, int last, FILE *NumberFile, int massize);
int  Exchange(int *data, int left, int right);
int  GetSizeFromFile(FILE *NumberFile);

int main()
    {
    FILE *NumberFile;
    if((NumberFile=fopen(MyFile, "rb"))==NULL)
        {
        printf("Cannot open file.\n");
        return 1;
        }

    int size = GetSizeFromFile(NumberFile);
    //printf("%d\n", size);

    int massize = ReadFromFile(NumberFile, size);
    //printf("%d\n", massize);

    int *data = (int*) calloc(massize+1, sizeof(int));
    ReadElements(NumberFile, massize, data);

    int first = 0;
    int last = massize - 1;

    PrintoutPartition(data, first, last, NumberFile, massize);

    Sort(data, first, last, NumberFile, massize);
    }

//-----------------------------------------------------------------------------

void Sort(int data[], int left, int right, FILE *NumberFile, int massize)
    {
    assert(data != NULL);
    if (left < right)
        {
        int mid = Partition(data, left, right, NumberFile, massize);
        Sort(data, left, mid, NumberFile, massize);
        Sort(data, mid + 1, right, NumberFile, massize);
        }
    }

//-----------------------------------------------------------------------------

int Partition(int data[], int left, int right, FILE *NumberFile, int massize)
    {
    int mid = data[(left + right)/2];
    while(left <= right)
        {
        while (data[left] < mid)
            {
            //PrintoutPartition(data, left, right, NumberFile, massize);
            left++;
            //PrintoutPartition(data, left, right, NumberFile, massize);
            }
        while (data[right] > mid)
            {
            //PrintoutPartition(data, left, right, NumberFile, massize);
            right--;
            //PrintoutPartition(data, left, right, NumberFile, massize);
            }
        if (left < right)
            {
            Exchange(data, left, right);
            left++;
            right--;
            }
        else
            {
            //PrintoutPartition(data, left, right, NumberFile, massize);
            return (right);
            //PrintoutPartition(data, left, right, NumberFile, massize);
            }
        }
    PrintoutPartition(data, left, right, NumberFile, massize);
    return right;
    }

//-----------------------------------------------------------------------------

void PrintoutPartition(int data[], int left, int right, FILE *NumberFile, int massize)
    {
    for (int i = 0; i < massize; i++)
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

int GetSizeFromFile(FILE *NumberFile)
    {
    struct stat buff = {};
    stat(MyFile, &buff);
    return buff.st_size;
    }

//-----------------------------------------------------------------------------

int ReadFromFile(FILE *NumberFile, int size)
    {
    int len = 0;
    int abc = 0;
    fseek(NumberFile, 0, SEEK_SET);
    for (int i = 0; i < size; i++)
        {
        int check = fscanf(NumberFile, "%d", &abc);
        //printf("%d ", check);
        if (check == 1)
            {
            len++;
            }
        }
    //printf("\n");
    return len;
    }

//-----------------------------------------------------------------------------

void ReadElements(FILE *NumberFile, int massize, int *data)
    {
    fseek(NumberFile, 0, SEEK_SET);
    for (int i = 0; i < massize; i++)
        {
        fscanf(NumberFile, "%d", &data[i]);
        }
    }
