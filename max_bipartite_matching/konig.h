#ifndef KONIG_H_INCLUDED
#define KONIG_H_INCLUDED
#define NMAX 10000

class Matching{
    public:
    Matching(int l,int d,int m, vector<int> graf[])
    ~Matching();
    int  max_match();
    int par[NMAX];

    private:
            vector<int> graf[2*NMAX+1];
            int l,d,m;
            queue<int> unpaired;
            int dfs(int v, vector<bool> visited);
            int augment();


};

Matching::Matching(int l, int d, int m, vector<int>& graf[])
{
    this->l = l;
    this->d = d;
    this->m = m;
    for(int i =1;i<=l+d)
    {
        for(int j=0;j<graf[i].size();j++)
        {
            (this->graf)[i].push_back(graf[i][j]);
        }

    }
    for(int i=1;i<=l;i++)
    {
        (this->unpaired).push(i);
    }
    for(int i=1;i<=l+d;i++)
    {
        (this->par)[i] = 0;
    }
}
Matching::~Matching{

}

int Matching::dfs(int v, vector<bool>& visited)
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
int Matching::augment(){
    vector<bool> visited;
    visited.reserve(l+1);
    for(int i=0;i<l+1;i++)
    {
        visited[i] = false;
    }
    while(!unpaired.empty())
    {
        int v = unpaired.front();
        if(visited[v] == true)
            break;

        unpaired.pop();
        if(bfs(v,visited) == 1)
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
int Matching::max_match(){
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

#endif // KONIG_H_INCLUDED
