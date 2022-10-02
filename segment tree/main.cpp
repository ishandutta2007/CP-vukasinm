#include <bits/stdc++.h>
#include "segtree.h"

using namespace std;

int saberi(int a, int b)
{
    return a+b;
}

int main()
{
    int a[] = {1,2,3};
    Seg_tree<int>* t = new Seg_tree<int>(a,3, &saberi);
    t->ispisi(1,0,2);
    t->alter(1,4);
    t->ispisi(1,0,2);
    cout<<endl<<t->seg(1,2);

    delete t;
    return 0;
}
