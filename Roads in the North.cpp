#include <bits/stdc++.h>
using namespace std;

const int maxn=10001;
int ans=0;
vector<pair<int,int> > vp[maxn];
int dfs(int to,int from)
{
    int Aroad=0,tem;
    
    for(int i=0;i<vp[to].size();i++)
    {
    	
        int go=vp[to][i].first;
        if(go!=from)
        {
            tem=dfs(go,to)+vp[to][i].second;
            ans=max(ans,tem+Aroad);
            Aroad=max(tem,Aroad);
        }
    }
    return Aroad;
}
int main()
{
    ios::sync_with_stdio(false);
    int a,b,c;
    string s;
    while(getline(cin,s))
    {
        for(int i=0;i<maxn;i++)
        vp[i].clear();
        ans=0;
        
        while(s.length()>0)//&& !cin.eof()
        {
            stringstream ss;
            ss<<s;
            ss>>a>>b>>c;
            vp[a].push_back(make_pair(b,c));
            vp[b].push_back(make_pair(a,c));
            getline(cin,s);
        }
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
