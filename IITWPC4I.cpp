//DSU+MST



#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAX=1e5+5;
vector<LL> GRAPH[MAX];
vector<pair<LL,pair<LL,LL> > > v;
vector<pair<LL,pair<LL,LL> > > edges;
int status[MAX];
int milk[MAX];
LL parent[MAX];
bool vis[MAX];
int flg1=0;

LL findRoot(LL i)
{
        while(parent[i]!=i)
        {
                i=parent[parent[i]];
        }
        return i;
}

void union1(LL x,LL y)
{
        milk[y]=milk[x] || milk[y];
        parent[x]=y;
}

LL kruskal()
{
        LL cost=0;
        for(int i=0;i<v.size();i++)
        {
                LL x=v[i].second.first;
                LL y=v[i].second.second;
                LL z=v[i].first;
                LL r1=findRoot(x);
                LL r2=findRoot(y);
                if(r1==r2) continue;
                if(milk[r1]==1 && milk[r2]==1) continue;
                edges.push_back(make_pair(z,make_pair(x,y)));
                cost+=z;
                union1(r1,r2);
        }
        return cost;
}

int main()
{
        int t;
        cin>>t;
        while(t--)
        {
                LL n,m;
                cin>>n>>m;
                for(int i=1;i<=n;i++)
                {
                        milk[i]=0;
                        parent[i]=i;
                }
                v.clear();
                edges.clear();
                for(int i=1;i<=n;i++)
                {
                        cin>>status[i];
                        milk[i]=status[i];
                }
                while(m--)
                {
                        LL x,y,cost;
                        cin>>x>>y>>cost;
                        v.push_back(make_pair(cost,make_pair(x,y)));
                        GRAPH[x].push_back(y);
                        GRAPH[y].push_back(x);
                }
                sort(v.begin(),v.end());
                LL cost=kruskal();
                int flg=0;
                for(int i=1;i<=n;i++)
                {
                        LL x=findRoot(i);
                        if(milk[x]==0) flg=1;
                }
                if(flg==1)
                {
                        cout<<"impossible"<<endl;
                }
                else cout<<cost<<endl;
        }
}
      

