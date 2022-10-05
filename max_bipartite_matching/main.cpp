#include <bits/stdc++.h>
#define NMAX 10000

using namespace std;

 vector<int> graf[2*NMAX+1];
int par[NMAX];
int l,d,m;
queue<int> unpaired;




int dfs(int v, vector<bool>& visited)
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

               if(dfs(par[graf[v][i]],visited) == 1)
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
int augment(){
    vector<bool> visited;
    visited.reserve(l+1);
    for(int i=0;i<l+1;i++)
    {
        visited[i] = 0;
    }
    while(!unpaired.empty())
    {
        int v = unpaired.front();
        if(visited[v] == true)
            break;

        unpaired.pop();
        if(dfs(v,visited) == 1)
        {
            printf("visited: ");
            for(int i=0;i<l;i++)
        {
            printf("%d ", visited[i+1]);
            cout<<endl;
        }
            return 1;
        }
        else
            unpaired.push(v);


    }
    printf("visited: ");
            for(int i=0;i<l;i++)
        {
            printf("%d ", visited[i+1]);
            cout<<endl;
        }
    return 0;


}
void max_match()
{
    while(augment()!=0)
    {
        printf("par: ");
        for(int i=0;i<l;i++)
        {
            printf("%d ", par[i+1]);
            cout<<endl;
        }
        printf("pari: ");
            for(int i=l;i<d+l;i++)
        {
            printf("%d ", par[i+1]);
            cout<<endl;
        }
    }
}

int main()
{
   /*vector<int> v;
   v.push_back(2);
   v.push_back(4);
   v.push_back(5);
   v.erase(v.begin()+1);
   printf("%d %d", v[0], v[1]);*/
   int x,y;
   cin>>l>>d>>m;
   for(int i=0;i<m;i++)
   {
       cin>>x>>y;
       graf[x].push_back(y);
       graf[y].push_back(x);
   }
   for(int i=0;i<l;i++)
   {
       unpaired.push(i+1);
       par[i+1] = 0;
   }
   for(int i =l;i<d+l;i++)
   {
       par[i+1] = 0;
   }
   max_match();

    return 0;
}
