#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	int n,height;
	string s;
	char c,mine[110][110],ans[110][110];
	
	cin>>n;
	for(int cs=0;cs<n;cs++){
		if(cs) cout << endl;
		bool dead=false;
		memset(mine,0,sizeof(mine));
		memset(ans,'.',sizeof(ans));
		cin>>height;
		
		for(int i=1;i<=height;i++){
			for(int j=1;j<=height;j++){
				cin>>c;
				mine[i][j]=c;
			}
		}
		
		for(int i=1;i<=height;i++){
			for(int j=1;j<=height;j++){
				cin>>c;
				if(c=='x'){
					int cnt=0;
					if(mine[i][j]=='*') continue;
					
					if(mine[i-1][j-1]=='*') cnt++;
					if(mine[i-1][j]=='*') cnt++;
					if(mine[i-1][j+1]=='*') cnt++;
					if(mine[i][j-1]=='*') cnt++;
					if(mine[i][j+1]=='*') cnt++;
					if(mine[i+1][j-1]=='*') cnt++;
					if(mine[i+1][j]=='*') cnt++;
					if(mine[i+1][j+1]=='*') cnt++;
					
					ans[i][j]=cnt+'0';
				}
			}
		}
		
		for(int i=1;i<=height;i++){
				for(int j=1;j<=height;j++){
					cout << ans[i][j];
				}
				cout << endl;
			}
	}
	
	return 0;
}

