#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAX=1e5+5;
vector<LL> GRAPH[MAX];
LL parent[MAX][15];
LL depth[MAX];
bool vis[MAX];

void init(int n)
{
        for(int i=1;i<=n;i++)
        {
                GRAPH[i].clear();
                vis[i]=false;
                depth[i]=-1;
                for(int j=0;j<15;j++)
                {
                        parent[i][j]=-1;
                }
        }
        
}

void DFS(LL x)
{
        vis[x]=true;
        for(int i=0;i<GRAPH[x].size();i++)
        {
                if(!vis[GRAPH[x][i]])
                {
                        depth[GRAPH[x][i]]=depth[x]+1;
                        parent[GRAPH[x][i]][0]=x;
                        DFS(GRAPH[x][i]);
                }
        }
}

void preprocess(int n)
{
       for(int j=0;j<15;j++)
       {
               for(int i=1;i<=n;i++)
               {
                       if(parent[i][j-1]!=-1)
                       {
                               parent[i][j]=parent[parent[i][j-1]][j-1];
                       }
               }
       }
}

LL LCA(LL x,LL y)
{
        if(depth[x]<depth[y])
                swap(x,y);
        LL diff=depth[x]-depth[y];
        for(int i=0;i<15;i++)
        {
                if((diff>>i)%2)
                {
                        x=parent[x][i];
                }
        }
        if(x==y) return x;
        for(int i=14;i>=0;i--)
        {
                if(parent[x][i]!=parent[y][i])
                {
                        x=parent[x][i];
                        y=parent[y][i];
                }
        }
        return parent[x][0];
}



int main()
{
        int t;
        cin>>t;
        int ctr=1;
        while(t--)
        {
                int n;
                cin>>n;
                init(n);
                cout<<"Case "<<ctr<<":"<<endl;
                ctr++;
                for(int i=1;i<=n;i++)
                {
                        int m;
                        cin>>m;
                        while(m--)
                        {
                                LL y;
                                cin>>y;
                                GRAPH[i].push_back(y);
                        }
                }
                depth[1]=0;
                DFS(1);
                preprocess(n);
                int q;
                cin>>q;
                while(q--)
                {
                        LL x,y;
                        cin>>x>>y;
                        cout<<LCA(x,y)<<endl;
                }
        }
}

