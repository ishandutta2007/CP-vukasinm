#include <bits/stdc++.h>
#define maxN 100000
using namespace std;
int father[maxN];

void initialize(int n)
{
    for(int i=0;i<n;i++)
    {
        father[i]=i;
    }
}
int findf(int n)
{
    if(father[n]==n)
        return n;
    else
    {
        father[n]=findf(father[n]);
        return father[n];
    }
}
void unite(int a, int b)
{
    int roota=findf(a);
    int rootb=findf(b);
    father[roota]=rootb;
    int d= findf(a);
}
int main()
{
    int n;
    ci
    return 0;
}
