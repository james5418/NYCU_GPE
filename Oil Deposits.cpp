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

