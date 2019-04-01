#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
typedef long long LL;
vector<LL> GRAPH[MAX];
LL mod=1e9+7;
stack<LL> stk;
LL paths[MAX];
bool vis[MAX];

void DFS(LL x)
{
        vis[x]=true;
        for(auto i:GRAPH[x])
        {
                if(!vis[i])
                {
                        DFS(i);
                }
        }
        stk.push(x);
}



int main()
{
        int t;
        cin>>t;
        while(t--)
        {
                LL n,m,s,t;
                cin>>n>>m>>s>>t;
                if(s==t)
                {
                        cout<<1<<endl;
                        continue;
                }
                for(int i=1;i<=n;i++)
                {
                        GRAPH[i].clear();
                        vis[i]=false;
                        paths[i]=0;
                }
                while(m--)
                {
                        LL x,y;
                        cin>>x>>y;
                        GRAPH[x].push_back(y);
                }
                DFS(s);
                paths[s]=1;
                while(stk.size()>0)
                {
                        int x=stk.top();
                        stk.pop();
                        //cout<<x<<" ";
                        for(int i=0;i<GRAPH[x].size();i++)
                        {
                                paths[GRAPH[x][i]]=(paths[GRAPH[x][i]]%mod+paths[x]%mod)%mod;
                        }
                }
                cout<<paths[t]%mod<<endl;
        }
}

