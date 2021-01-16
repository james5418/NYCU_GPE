#include <bits/stdc++.h>
using namespace std;

int dp[1000005],val[20];
int main(int argc, char** argv) {
	int n,m;
	
	while(cin>>n){
		cin>>m;
		memset(dp,0,sizeof(dp));
		memset(val,0,sizeof(val));
		
		for(int i=0;i<m;i++){
			cin >> val[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<m;j++){
				if(i-val[j]>=0 && !dp[i-val[j]]){
					dp[i]=1;
					//break;
				}
			}
		}
		
		if(dp[n]) cout << "Stan wins" << endl;
		else cout << "Ollie wins" << endl;
	}
	return 0;
}

