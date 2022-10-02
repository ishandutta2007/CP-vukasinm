#include <bits/stdc++.h>
#include "trie.h"


using namespace std;

int main()
{
    Trie<int>* t = new Trie<int>(0);
    vector<int> v1{1,2,3};
    vector<int> v2{3,4,5};
    vector<int> v3{1,2,5};
    vector<int> v4{1,2,3};
    vector<int> v5{2,3,2};
    t->t_insert(v1);
    t->t_insert(v2);
    t->t_insert(v3);

    t->t_delete(v5);
    cout<<t->get_wordcount()<<endl<<t->t_search(v2)<<endl<<t->t_search(v1);
    t->ispisi();
    char a = 'a';
    cout<<a;

    delete t;

    return 0;
}
