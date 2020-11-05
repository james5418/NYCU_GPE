#include <bits/stdc++.h>
using namespace std;

int dp[10005];

int main(int argc, char** argv) {
	int n,x;
	while(cin>>n && n){
		int seq[10005];
		for(int i=1;i<=n;i++){
			cin>>seq[i];
		}
		
		int ans=0;
		dp[0]=0;
		
		for(int i=1;i<=n;i++){
			dp[i] = max(seq[i],dp[i-1]+seq[i]);
			ans=max(ans,dp[i]);
		}
		
		if(ans>0) cout << "The maximum winning streak is " << ans << ".\n";
		else cout << "Losing streak.\n";
	}
	return 0;
}

