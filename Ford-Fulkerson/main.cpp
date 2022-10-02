#include <bits/stdc++.h>
#define MAXN 100000
#define INF 1000007

using namespace std;



vector<int> graf[MAXN];//graf sa usmerenim granama
vector<int> graf_rev[MAXN]; // graf sa obrnuto usmerenim granama
map<pair<int,int>, pair<int,int>> kapacitet; //svakoj usmerenoj grani (i,j) dodelimo par(x_ij,c_ij), gde je c_ij kapacitet grane,
// a x_ij je trenutni protok koji se  menja
int max_flow = 0,id=0;//max_flow je promenljiva koju povecavamo svaki put kada nadjemo novi put od sourca do sinka koja nema popunjene ni prazne grane(takve grane zovemo potencijalne)
// id je indikator da nismo stigli do n u bfsu, tj da nemamo vise gde da povecavamo


void bfs(int n)
{
    pair<int,int> parent[MAXN]; // svakom elementu dodajemo roditelja koji moze biti u kom god smeru samo da od roditelja do deteta vodi potencijalna grana
    for(int i=1;i<n;i++)
    {
        parent[i] = make_pair(0,0);// inicijalizacija roditelja
    }
    int val[MAXN];
    int e; // najveca vrednost koju mozemo dodati promenljivoj max_flow iz jedne dobre putanje
    queue<int> q;//standardni bfs queue
    q.push(1);
    val[1] = INF;// val je memoizaciona promenljiva koja oznacava trenutni potencijalni maksimum koji mozemo dodati flowu dok jos nismo stigli do kraja
    while(!q.empty())
    {
        int v = q.front();
        if(v==n)
        {

            e = val[n];
            while(v!=1)
            {
                if(parent[v].second == 1)// druga koordinata roditelja oznacava da li je roditelj usmeren ka detetu ili dete ka roditelju
                {
                    kapacitet[make_pair(parent[v].first , v)].first = kapacitet[make_pair(parent[v].first , v)].first + e;

                }
                else if(parent[v].second == -1){
                    kapacitet[make_pair(v,parent[v].first)].first = kapacitet[make_pair(v,parent[v].first)].first - e;
                }
                cout<<v<<" "<<parent[v].first<<" ";//ispis putanje koja vodi od 1 do n
                v = parent[v].first;
            }
            cout<<endl;
            max_flow +=e;
            //return e;
            return;
        }
        for(int j: graf[v])//prolazak kroz susede tipa v -> j
        {
            if(kapacitet[make_pair(v,j)].first < kapacitet[make_pair(v,j)].second)
                {

                    if(parent[j].first ==0)
                            {parent[j] = make_pair(v,1);
                            q.push(j);

                    val[j] = min(val[v], kapacitet[make_pair(v,j)].second - kapacitet[make_pair(v,j)].first);
                    cout<<j<<" "<<v<<" dodavanje unapred "<<endl;}
                }
        }
        for(int j: graf_rev[v])// prolazak kroz susede tipa j -> v
        {
            if(kapacitet[make_pair(j,v)].first >0)
                {

                    if(parent[j].first ==0)
                    {
                        parent[j] = make_pair(v,-1);
                        q.push(j);


                    val[j] = min(val[v], kapacitet[make_pair(j,v)].first);
                    cout<<j<<" "<<v<<" dodavanje unazad "<<endl;}
                }
        }
        q.pop();
    }
    id = 1;
    //return 0;
}

int main()
{
    int n,m,x,y,c;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        graf[x].push_back(y);
        graf_rev[y].push_back(x);
        cin>>c;
        pair<int,int> p = make_pair(x,y);
        kapacitet[p] = make_pair(0,c);
    }
   /* for(int i=0;i<n;i++)
    {
        for(int j=0;j<graf[i].size();j++)
        {
            cout<<i<<" "<<graf[i][j]<<" "<<kapacitet[make_pair(i,graf[i][j])].second<<endl;
        }
    }*/
    while(id != 1)
    {
        bfs(n);
        cout<<"maks: "<<max_flow<<endl;
    }
    cout<<"Maks flow: "<<max_flow;
    return 0;
}
