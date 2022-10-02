#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;


template<typename T>
class Heap{
    public: Heap(T a,int (*f)(T,T));
    ~Heap();
    T top();
    void h_insert(T a);
    void h_delete();
    void print();
    private:
        vector<T> heap;
        void percdown(int index);
        void percup(int index);
        int (*f) (T , T);
};

template<typename T>
Heap<T>::Heap(T a, int (*f)(T,T)){

    heap.push_back(a);
    this->f = f;
}

template<typename T>
Heap<T>::~Heap(){

}

template<typename T>
T Heap<T>::top(){
    return heap[1];

}
template<typename T>
void Heap<T>::h_insert(T a)
{
    int n = heap.size();
    heap.push_back(a);
    percup(n);
}
template<typename T>
void Heap<T>::h_delete(){
    int n = heap.size()-1;
    int d = heap[1];
    heap[1] = heap[n];
    heap.erase(heap.end()-1);
    percdown(1);

}
template<typename T>
void Heap<T>::percdown(int index)
{
    T d;
    while(2*index<heap.size())
    {
       int child=2*index;
        if((child+1<heap.size())&&((*f)(heap[child],heap[child+1])<0))
        {
            child++;

        }
        if ((*f)(heap[index],heap[child])<0)
        {
            d=heap[index];
            heap[index]=heap[child];
            heap[child]=d;
            index=child;
        }
        else{break;}
    }
}
template<typename T>
void Heap<T>::percup(int index){
    T d;
    int parent;
    while((index/2)>0)
    {
        parent=index/2;
        if((*f)(heap[parent],heap[index])<0)
        {
            d=heap[index];
            heap[index]=heap[parent];
            heap[parent]=d;
            index = parent;
        }
        else{break;}
    }

}
template<typename T>
void Heap<T>::print(){
    for(int i=1;i<heap.size();i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

#endif // HEAP_H_INCLUDED
