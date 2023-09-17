#ifndef ONEGINSORTFILE_H_INCLUDED
#define ONEGINSORTFILE_H_INCLUDED

//=============================================================================

void Sort(struct data *info, int left, int right, int (*CompareRight)(const char*, const char*));
void MyQuickSort(struct data *info, int (*Comparator)(const void* x1, const void* x2));
void SortByQsort(struct data *info);

int  Partition(struct data *info, int first, int last, int (*Comparator)(const void* x1, const void* x2));
int  Exchange(struct data *info, int left, int right);
int  Compare(const void* x1, const void* x2);
int  RightLeft(const char* str1, const char* str2);
int  CompareLeft(const void * x1, const void * x2);
int  LeftRight(const char* str1, const char* str2);

//=============================================================================

#endif // ONEGINSORTFILE_H_INCLUDED
