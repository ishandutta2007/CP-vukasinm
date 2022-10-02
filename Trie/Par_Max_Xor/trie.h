#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

template <typename T>
class Trie{
public:
    Trie(T x);
    ~Trie();

    void t_insert(const vector<T>& v);
    int get_wordcount();
    void t_delete(const vector<T>& v);
    int t_search(const vector<T>& v);
    void ispisi();
    vector<ull> bin(T n);
    T max_xor(T n);
private:
    typedef struct Node{
    T value;
    bool kraj;
    int broj_reci;
    map<T,Node*> children;
    Node(T x)
    {
        this->value = x;
        this->kraj = false;
        this->broj_reci = 0;
    }

    }Node;

    Node* root;
    void obrisi(Node* node){
    if(!node)
        return;
    if(!(node->children.empty()))
    {
        for(auto it = node->children.begin();it!=node->children.end();++it)
        {
            obrisi((*it).second);
        }
    }
    delete node;

    }
    void ispis(Node* node)
    {
        for(auto i = node->children.begin();i!=node->children.end();i++)
    {
        cout<<(*i).first<<endl;
        ispis((*i).second);
    }
    }

};

template <typename T>
Trie<T>::Trie(T x){
    this->root = new Node(x);


}
template <typename T>
Trie<T>::~Trie(){
if(this->root)
    obrisi(this->root);


}

template <typename T>
void Trie<T>::t_insert(const vector<T>& v)
{

    Node* tek = this->root;
    for(int i=0;i<v.size();i++)
    {

        if( tek->children.empty() || tek->children.find(v[i]) == tek->children.end())
        {
            tek->children[v[i]] = new Node(v[i]);
        }

        tek = tek->children[v[i]];
    }
    if(!(tek->kraj))
    {
        Node* t1 = this->root;
        for(int i=0;i<v.size();i++)
    {
        t1->broj_reci++;
        t1 = t1->children[v[i]];
    }
    t1->broj_reci++;
    t1->kraj = true;
    }
}
template <typename T>
void Trie<T>::t_delete(const vector<T>& v){
    if(v.empty())
        return;

    Node* tek = this->root;

for(int i=0;i<v.size();i++)
{
    if(tek->children.empty() || tek->children.find(v[i]) == tek->children.end())
    {
        cout<<"Data rec ne postoji"<<endl;
        return;
    }
    tek = tek->children[v[i]];
}
if(! (tek->kraj))
{
    cout<<"Data rec ne postoji"<<endl;
        return;
}

Node* t1 = this->root;
if(t1->broj_reci == 1)
    {obrisi(t1->children[v[0]]);
    t1->broj_reci = 0;
    t1->children.clear();
    return;
    }

for(int i=0;i<v.size();i++)
{
    if((t1->children[v[i]])->broj_reci == 1)
    {obrisi(t1->children[v[i]]);
    t1->broj_reci--;
    t1->children.erase(v[i]);
    return;
    }
    t1->broj_reci--;
    t1 = t1->children[v[i]];
}
t1->broj_reci--;
t1->kraj = false;

}
template <typename T>
int Trie<T>::t_search(const vector<T>& v)
{
    if(v.empty())
        return 0;

    Node* tek = this->root;
    for(int i=0;i<v.size();i++)
    {

        if( tek->children.empty() || tek->children.find(v[i]) == tek->children.end())
        {
            return 0;
        }

        tek = tek->children[v[i]];
    }
    if(tek->kraj == true)
        return 1;
    return 0;
}

template <typename T>
void Trie<T>::ispisi()
{
    ispis(this->root);

}

template <typename T>
int Trie<T>::get_wordcount()
{
    return this->root->broj_reci;
}

template <typename T>
vector<unsigned long long> Trie<T>::bin(T n)
{
    vector<ull> v;
    for(int i=1;i<=64;i++)
    {
        v.push_back(n%2);
        n/=2;
    }
    reverse(v.begin(),v.end());
    return v;
}

template <typename T>
T Trie<T>::max_xor(T n)
{
    T m = 0;
    Node* tek = this->root;
    for(int i=0;i<bin(n).size();i++)
    {
        if(tek->children.find(1-bin(n)[i]) == tek->children.end())
            {tek = tek->children[bin(n)[i]];
            m = 2*m + bin(n)[i];
            }
        else
            {tek = tek->children[1-bin(n)[i]];
            m = 2*m + 1-bin(n)[i];
            }


    }
    return n^m;
}

#endif // TRIE_H_INCLUDED
