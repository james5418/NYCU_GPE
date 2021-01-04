#include <bits/stdc++.h>
using namespace std;
int n,m;
char mp[100][100];
bool collected[100][100];

void collectoil(int i,int j){
	if(i<0 || i>=m || j<0 || j>=n) return;
	else if(mp[i][j]=='*' || collected[i][j]==true) return;
	else{
		collected[i][j]=true;
		
		collectoil(i-1,j-1);
		collectoil(i-1,j);
		collectoil(i-1,j+1);
		collectoil(i,j-1);
		collectoil(i,j+1);
		collectoil(i+1,j-1);
		collectoil(i+1,j);
		collectoil(i+1,j+1);
	}
}

int main(int argc, char** argv) {
	while(cin>>m>>n && m && n){
		int ans=0;
		for(int i=0;i<m;i++){
			cin>>mp[i];
			for(int j=0;j<n;j++){
				collected[i][j]=false;
			}
		}
		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(mp[i][j]=='@' && collected[i][j]==false){
					collectoil(i,j);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int n,m;
int ans=0;
char mp[100][100];
bool collected[100][100];
queue< pair<int,int> > q;
int direction[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void collectoil(int i,int j){
	pair<int,int> cur,next;
	q.push(make_pair(i,j));
	collected[i][j]=true;
	
	while(!q.empty()){
		cur=q.front();
		q.pop();
		
		
		for(int i=0;i<8;i++){
			next.first = cur.first + direction[i][0];
			next.second = cur.second + direction[i][1];
			
			if(next.first<0 || next.first>=m || next.second<0 || next.second>=n) continue;
			if(mp[next.first][next.second]=='*' || collected[next.first][next.second]==true) continue;
			
			collected[next.first][next.second]=true;
			q.push(next);
		}
	}
	ans++;
}

int main(int argc, char** argv) {
	
	while(cin>>m>>n && m && n){
		ans=0;
		for(int i=0;i<m;i++){
			cin>>mp[i];
			for(int j=0;j<n;j++){
				collected[i][j]=false;
			}
		}
		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(mp[i][j]=='@' && collected[i][j]==false){
					collectoil(i,j);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
*/
