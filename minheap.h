#ifndef _MINHEAP_H_
#define _MINHEAP_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
template <class T>
class meanheap {
    private:
        T heap_size;
    public:
        T *A;//mean array
        meanheap(T N) {
            heap_size = N;
            A = new T[N];
        }

        void heapify();
        T getmin();
        void minheapify(int i);
        int left(int i);
        int right(int i);
        T extractMin();

};

template <class T>
void meanheap<T>::heapify(T x) {
    int i = 0;
    i = (heap_size - 1)/2;
    while(i >= 0) {
        minheapify(i);
        i--;
    }

}

template <class T>
void meanheap<T>::minheapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heap_size - 1 && A[l] < A[i]) {
        smallest = l;
    }
    if(r  < heap_size -1 && A[r] < A[smallest]) {
        smallest = r;
    }
    if(smallest != i) {
        swap(&A[i], &A[smallest]);
        minheapify(smallest);
    }
}

template <class T>
int meanheap<T>::left(int i) {
    return (2*i + 1);
}

template <class T>
int meanheap<T>::right(int i) {
    return (2*i + 2);
}

template <class T>
T meanheap<T>::getmin() {
    return A[0];
}

template <class T>
T meanheap<T>::extractMin() {
    T x = A[0];
    swap(&A[0], &A[heap_size-1]);
    heap_size--;
    heapify();
    return x;
}




#endif
