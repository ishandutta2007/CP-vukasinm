#include <bits/stdc++.h>
#include "trie.h"

typedef unsigned long long ull;

using namespace std;







int main()
{

    Trie<ull>* t = new Trie<ull>(0);
    int n;
    ull x,m=0;
    cin>>n;
    cin>>x;
    t->t_insert(t->bin(x));
    for(int i=1;i<n;i++)
    {
        cin>>x;
        if(t->max_xor(x) > m)
        {
            m = t->max_xor(x);
        }
        t->t_insert(t->bin(x));
    }

    cout<<m;
    return 0;
}
