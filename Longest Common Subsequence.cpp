#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int main(int argc, char** argv) {
	string s1,s2;
	
	
	while(getline(cin,s1)){
		getline(cin,s2);
		memset(dp,0,sizeof(dp));
		int len1=s1.length();
		int len2=s2.length();
		
		for(int i=0;i<len1;i++){
			for(int j=0;j<len2;j++){
				if(s1[i]==s2[j]) dp[i+1][j+1] = dp[i][j]+1;
				else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
			}
		}
		cout << dp[len1][len2] << endl;
		
	}
	return 0;
}

