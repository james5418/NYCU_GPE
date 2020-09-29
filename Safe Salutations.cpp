#include <bits/stdc++.h>
using namespace std;
int dp[20];
int main(int argc, char** argv) {
	int n,t=0;
	
	while(cin>>n){
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		dp[1]=1;
		dp[2]=2;
		for(int i=3;i<=10;i++){
			for(int j=0;j<n;j++){
				dp[i] += (dp[j]*dp[i-j-1]);
			}
		}
		if(t++) cout << endl;
		cout << dp[n] << endl;
	}
	
	return 0;
}

