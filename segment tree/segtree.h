#ifndef SEGTREE_H_INCLUDED
#define SEGTREE_H_INCLUDED
#define MAXN 10000000

using namespace std;

template <typename T>
class Seg_tree{
public:
    Seg_tree(const T a[], int n,T (*f)(T ,T));
    ~Seg_tree();

    int size;
    void alter(int i, T x);
    T seg(int l, int d);
    void ispisi(int v, int tl, int tr);

private:
    T tree[4*MAXN+1];
    T (*f)(T,T);
    void build(const T a[], int v, int tl, int tr);
    void alter_build(T x, int i, int v, int tl, int tr);
    T seg_build(int v,int tl, int tr, int l, int d);

};

template <typename T>
void Seg_tree<T>::build(const T a[], int v, int tl, int tr)
{
    if(tl == tr)
        {this->tree[v] = a[tl];
    return;}

    int ts = (tl+tr)/2;
    build(a,2*v,tl,ts);
    build(a,2*v+1,ts+1,tr);
    this->tree[v] =(*(this->f)) (this->tree[2*v], this->tree[2*v+1]);
}

template <typename T>
Seg_tree<T>::Seg_tree(const T a[], int n,T (*f)(T ,T))
{
    this->size = n;
    this->f = f;
    build(a, 1,0,n-1);

}

template <typename T>
Seg_tree<T>::~Seg_tree(){


}

template <typename T>
void Seg_tree<T>::alter(int i, T x){
    alter_build(x,i-1,1,0,this->size-1);


}


template <typename T>
void Seg_tree<T>::alter_build(T x, int i, int v, int tl, int tr){

    if(tl == tr)
        {this->tree[v] = x;
        return;}

    int ts = (tl+tr)/2;
    if(i<=ts)
    alter_build(x,i,2*v,tl,ts);
    else
    alter_build(x,i,2*v+1,ts+1,tr);
    this->tree[v] =(*(this->f)) (this->tree[2*v], this->tree[2*v+1]);

}
template <typename T>
T Seg_tree<T>::seg(int l, int d){
    seg_build(1,0,this->size-1,l-1,d-1);

}
template <typename T>
T Seg_tree<T>::seg_build(int v,int tl, int tr, int l, int r){
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    if(tm<l)
     return  seg_build(v*2+1, tm+1, tr, l, r);
    else if(tm>=r)
        return seg_build(v*2, tl, tm, l, r);
    else
         return (*(this->f))(seg_build(v*2, tl, tm, l, min(r,tm)), seg_build(v*2+1, tm+1, tr, max(l,tm+1), r));

}
template <typename T>
void Seg_tree<T>::ispisi(int v, int tl, int tr){
    if(tl == tr)
    {
        cout<<tree[v]<<" ";
        return;
    }


    int tm = (tl+tr)/2;
    cout<<this->tree[v]<<" ";
    ispisi(2*v,tl, tm);
    ispisi(2*v+1,tm+1,tr);

}

#endif // SEGTREE_H_INCLUDED
