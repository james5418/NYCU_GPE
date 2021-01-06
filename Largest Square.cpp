#include <bits/stdc++.h>
using namespace std;

char mp[100][100];
bool vis[100][100];
int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
int n,m,q;

bool check(int r,int c,char ch,int len){
	int cnt=0;
	for(int i=1;i<=len/2;i++){
		if(r-i<0 || r+i>=m || c-i<0 || c+i>=n) continue;
		if(mp[r-i][c-i]==mp[r][c] && mp[r+i][c-i]==mp[r][c] && mp[r-i][c+i]==mp[r][c] && mp[r+i][c+i]==mp[r][c] && 
		   mp[r][c-i]==mp[r][c] && mp[r+i][c-i]==mp[r][c] && mp[r][c+i]==mp[r][c] && mp[r-i][c]==mp[r][c]){
			cnt++;
		}
	}
	if(cnt==len/2) return true;
	else return false;
}

int bfs(int xx,int yy,char ch){
	queue< pair<int,int> > q;
	vector<int> area;
	int len=3,cnt=1;
	
	q.push(make_pair(xx,yy));
	vis[xx][yy]=true;
	
	while(!q.empty()){
		pair<int,int> cur,next;
		cur=q.front();
		q.pop();
		
		for(int i=0;i<8;i++){
			next.first = cur.first + dir[i][0];
			next.second = cur.second + dir[i][1];
			
			if(next.first<0 || next.first>=m || next.second<0 || next.second>=n) continue;
			if(vis[next.first][next.second] || mp[next.first][next.second]!=ch) continue;
			
			vis[next.first][next.second]=true;
			
			q.push(next);
			cnt++;
		}
		
		if(cnt==len*len && check(xx,yy,ch,len)) area.push_back(len);
		else if(cnt>len*len) len+=2;
	}
	
	int M=1;
	for(int i=0;i<area.size();i++){
		if(M<area[i]) M=area[i];
	}
	return M;
}

int main(int argc, char** argv) {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		cin>>m>>n>>q;
		cout << m << " " << n << " " << q << '\n';
		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>mp[i][j];
			}
		}
		
		while(q--){
			int r,c;
			memset(vis,false,sizeof(vis));
			cin>>r>>c;
			cout << bfs(r,c,mp[r][c]) << '\n';
		}
	}
	return 0;
}

