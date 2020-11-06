#include <bits/stdc++.h>
using namespace std;

char mp[21][21];
bool visit[21][21];

void dfs(int i,int j){
	visit[i][j]=true;
	if(mp[i+1][j]==mp[i][j] && !visit[i+1][j]) dfs(i+1,j);
	if(mp[i-1][j]==mp[i][j] && !visit[i-1][j]) dfs(i-1,j);
	if(mp[i][j+1]==mp[i][j] && !visit[i][j+1]) dfs(i,j+1);
	if(mp[i][j-1]==mp[i][j] && !visit[i][j-1]) dfs(i,j-1);
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	for(int c=1;c<=n;c++){
		
		int i,j;
		cin>> i >> j;
		memset(visit,0,sizeof(visit));
		
		for(int a=0;a<i;a++){
			for(int b=0;b<j;b++){
				cin>>mp[a][b];
			}
		}
		
		int maxarea=0;
		int letter[30]={0};
		
		for(int a=0;a<i;a++){
			for(int b=0;b<j;b++){
				if(!visit[a][b]){
					maxarea = max(++letter[mp[a][b]-'a'],maxarea);
					dfs(a,b);
				}
			}
		}
		
		cout << "World #" << c << endl;
		for(int k=maxarea;k>0;k--){
			for(int u=0;u<26;u++){
				if(letter[u]==k) printf( "%c: %d\n", 'a'+u, k );
			}
		}
	}
	return 0;
}

