#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	while(n--){
		int r,c;
		cin>>r>>c;
		int grid[r][c];
		int dp[r][c];
		memset(grid,0,sizeof(grid));
		memset(dp,0,sizeof(dp));
		
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin>>grid[i][j];
			}
		}
		dp[0][0]=grid[0][0];
		
		for(int i=1;i<r;i++){
			dp[i][0] = grid[i][0] + dp[i-1][0];
		}
		for(int j=1;j<c;j++){
			dp[0][j] = grid[0][j] + dp[0][j-1];
		}
		
		for(int i=1;i<r;i++){
			for(int j=1;j<c;j++){
				dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout << dp[r-1][c-1] << endl;
	}
	return 0;
}

