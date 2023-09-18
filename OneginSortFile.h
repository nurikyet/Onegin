#ifndef ONEGINSORTFILE_H_INCLUDED
#define ONEGINSORTFILE_H_INCLUDED

//=============================================================================

void Sort(struct textdata *info, int left, int right, int (*Comparator)(const char*, const char*));
void MyQuickSort(struct textdata *info, int (*Comparator)(const void* x1, const void* x2));
void SortByQsort(struct textdata *info);

int  Partition(struct textdata *info, int first, int last, int (*Comparator)(const void* x1, const void* x2));
int  Exchange(struct textdata *info, int left, int right);
int  Compare(const void* x1, const void* x2);
int  RightLeft(const void *x1, const void *x);
int  CompareLeft(const void * x1, const void * x2);
int  LeftRight1(const void* x1, const void* x2);
int  LeftRight(const void* x1, const void* x2);

//=============================================================================

#endif // ONEGINSORTFILE_H_INCLUDED
