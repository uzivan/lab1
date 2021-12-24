#ifndef LAB21_ALGORITHMS_H
#define LAB21_ALGORITHMS_H
#include <iostream>
#include "Sequences.h"

template <typename T>
void BubbleSort(Sequence<T>& m, int p,  int n)
{
    for(int i = n - 1; i >= 1; i--)
        for(int j = 0; j < i; j++)
        {
            if(m.Get(j) > m.Get(j+1))
            {
                T foo = m.Get(j);
                m.InsertAt(m.Get(j+1), j);
                m.InsertAt(foo, j+1);
            }
        }
}


template <typename T>
void QuickSortCall(Sequence<T>& numbers, int left, int right)
{
    int pr;
    int l_h = left;
    int r_h = right;
    pr = numbers.Get(left);
    while (left < right)
    {
        while ((numbers.Get(right) >= pr) && (left < right))
            right--;
        if (left != right)
        {
            //numbers[left] = numbers[right];
            numbers.InsertAt(numbers.Get(right), left);
            left++;
        }
        while ((numbers.Get(left) <= pr) && (left < right))
            left++;
        if (left != right)            {
            //numbers[right] = numbers[left];
            numbers.InsertAt(numbers.Get(left), right);
            right--;
        }
    }
    //numbers[left] = pr;
    numbers.InsertAt(pr, left);
    pr = left;
    left = l_h;
    right = r_h;
    if (left < pr)
        QuickSortCall(numbers, left, pr - 1);
    if (right > pr)
        QuickSortCall(numbers, pr + 1, right);
}


template <typename T>
void QuickSort(Sequence<T>& A, int first, int last){
    QuickSortCall(A, first, last - 1);
}


template <typename T>
void MergeCall(Sequence<T>& A, int first, int last) {
    int middle, start, final, j;
    int *mas = new int[A.Size()];
    middle = (first + last) / 2;
    start = first;
    final = middle + 1;
    for (j = first; j <= last; j++)
        if ((start <= middle) && ((final > last) || (A.Get(start) < A.Get(final)) /*(A[start] < A[final])*/)) {
            mas[j] = A.Get(start);
            start++;
        } else {
            mas[j] = A.Get(final);
            final++;
        }
    for (j = first; j <= last; j++)
        A.InsertAt(mas[j], j);
        //A[j] = mas[j];
    delete[] mas;
}


template <typename T>
void MergeSort(Sequence<T>& A, int first, int last) {
    if (first < last) {
        MergeSort(A, first, (first + last) / 2);
        MergeSort(A, (first + last) / 2 + 1, last);
        MergeCall(A, first, last);
    }
}


template <typename T>
void Merge(Sequence<T>& A, int first, int last){
    MergeSort(A, first, last - 1);
}


template <typename T>
void CtrlV(Sequence<T>& arr, int p, int n){
    for(int i=1;i<n;i++){
        for(int j=i; j>0 && arr.Get(j-1)>arr.Get(j);j--){
            int tmp=arr.Get(j-1);
            arr.InsertAt(arr.Get(j), j-1);
            //arr[j-1]=arr[j];
            arr.InsertAt(tmp, j);
            //arr[j]=tmp;
        }
    }
}


#endif //LAB21_ALGORITHMS_H
