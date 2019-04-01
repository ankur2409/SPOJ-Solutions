#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAX=1e4+5;
vector<LL> GRAPH[MAX];


int main()
{
        LL n;
        cin>>n;
        multiset<LL> s1;
        multiset<LL,greater<LL> > s2;
        int cnt=0;
        while(n--)
        {
                LL x;
                cin>>x;
                if(x==1)
                {
                        LL y;
                        cin>>y;
                        cnt++;
                        if(cnt<=2)
                        {
                                s2.insert(y);
                                continue;
                        }
                        else if(cnt%3==0)
                        {
                                LL temp=*(s2.begin());
                                if(temp<y)
                                {
                                       s1.insert(y); 
                                }
                                else
                                {
                                        s2.erase(s2.begin());
                                        s1.insert(temp);
                                        s2.insert(y);
                                }
                        }
                        else
                        {
                                LL temp=*(s1.begin());
                                if(temp<y)
                                {
                                        s1.erase(s1.begin());
                                        s2.insert(temp);
                                        s1.insert(y);
                                }
                                else
                                {
                                        s2.insert(y);
                                }
                        }
                }
                else
                {
                        //cout<<s1.size()<<" "<<s2.size()<<endl;
                        if(s1.size()==0)
                        {
                                cout<<"No reviews yet"<<endl;
                        }
                        else cout<<*(s1.begin())<<endl;
                }
        }
                
}
