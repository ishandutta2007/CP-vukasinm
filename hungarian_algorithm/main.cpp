#include <bits/stdc++.h>
#define VMAX 10000
#define INF 1000000
#include "konig.h"

using namespace std;

int c[VMAX][VMAX];
int m[VMAX];
int n;
vector<int> graf[2*VMAX+1];
int par[2*VMAX+1];

int upareno;

void calibrate()
{

    for(int i=1;i<=n;i++)
    {
        int mi  = c[i][1] - m[1];

        for(int j = 1; j<=n;j++)
        {
            if(c[i][j] - m[j] < mi)
                mi = c[i][j] - m[j];
        }
        for(int j = 1; j<=n;j++)
        {
            if(c[i][j] - m[j] == mi)
            {
                graf[j].push_back(n+i);
                graf[n+i].push_back(j);
            }
        }


    }
}

int reach(int v, vector<bool>& visited)
{
    visited[v] = true;
    for(int i=0;i<graf[v].size();i++)
    {
        if(graf[v][i] != par[v])
        {
            if(par[graf[v][i]] == 0)
            {
                par[v] = graf[v][i];
                par[graf[v][i]] = v;

                return 1;
            }

            else if(visited[par[graf[v][i]]] ==false)
            {

               if(reach(par[graf[v][i]],visited) == 1)
               {
                    par[v] = graf[v][i];
                    par[graf[v][i]] = v;

                    return 1;
               }

            }
        }
    }
    return 0;
}
void increment()
{
    int v, inc = INF;
    for(int i=1;i<=n;i++)
    {
        if(par[i] == 0)
        {
            v = i;
            break;
        }
    }

    vector<bool> visited;
    visited.reserve(n+1);
    for(int i=0;i<=n;i++)
    {
        visited[i] = false;
    }
    int l = reach(v,visited);

    for(int i=1;i<=n;i++)
    {
        for(int j=n+1;j<=2*n;j++)
        {
            if(visited[i] == true && (par[j]==0 || visited[par[j]] == false))
            {
                int k = graf[j][0];
                if(inc > (c[j-n][i]-m[i] - c[j-n][k]+m[k]))
                    inc = c[j-n][i]-m[i] - c[j-n][k]+m[k];
            }
        }
    }

    for(int i=1; i<=n;i++)
    {
        if(visited[i] == true)
            m[i]+=inc;


    }

}

void hung_alg()
{
    while(upareno !=n)
    {
        calibrate();
        /*for(int i=1;i<=n;i++)
        {
            for(int j=0;j<graf[i].size();j++)
            {
                cout<<i<<" "<<graf[i][j]<<" ";
            }
            cout<<endl;
        }*/

        Matching* m = new Matching(n,n,graf);
        upareno = m->max_match();

        for(int i=1;i<=2*n;i++)
        {
            par[i] = (m->par)[i];
        }

        if(upareno == n)
            break;

        increment();

    }
    for(int i = 1;i<=n;i++)
    {
        cout<<m[i]<<" ";

    }
    cout<<endl;
    for(int i = n+1;i<=2*n;i++)
    {
        cout<<c[i-n][par[i]]- m[par[i]]<<" ";

    }

}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>c[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        m[i] = 0;

    }
    hung_alg();

    return 0;
}
