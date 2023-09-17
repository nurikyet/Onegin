#ifndef ONEGINSORTFILE_H_INCLUDED
#define ONEGINSORTFILE_H_INCLUDED

//=============================================================================

void Sort(char **text, int left, int right, int (*CompareRight)(const char*, const char*));
void MyQuickSort(char **text, int nrows);
void SortByQsort(char **text, int nrows);

int  Partition(char **text, int first, int last);
int  Exchange(char **text, int left, int right);
int  CompareRight(const void* x1, const void* x2);
int  RightLeft(const char* str1, const char* str2);
int  CompareLeft(const void * x1, const void * x2);
int  LeftRight(const char* str1, const char* str2);

//=============================================================================

#endif // ONEGINSORTFILE_H_INCLUDED
