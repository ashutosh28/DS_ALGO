#ifndef _heap_h
#define _heap_h

#include<iostream>
#include<stdio.h>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stdlib.h>

using namespace std;

#define MAX 1000

//Heap Implementation with use of array. 
template <typename T>
class heap
{
    public:
        heap();
        //heap(//);overloaded constructor.
        ~heap();
        void insert(T value);
        T peek();
        void remove(T value);
        void search(T value);
        T max_value();
        void Heapify(int index);
        int Heap_size();
    private:
        T arr[MAX];
        T size;
};

#endif
