#include <bits/stdc++.h>
#include "heap.h"

using namespace std;

int compare(int a, int b)
{
    return a-b;
}

int main()
{
    int a,n;
    Heap<int>* h = new Heap<int>(0,&compare);
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a;
        h->h_insert(a);
        h->print();

    }
    h->h_delete();
    h->print();

    return 0;
}
