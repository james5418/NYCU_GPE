#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(0);
	int m;
	string line;
	cin>>m;
	getline(cin,line);
	while(m--){
		getline(cin,line);
		stringstream ss(line);
		int n=0,sum=0;
		int a[30];
		int dp[201]={};
		
		while(ss>>a[n]){
			sum+=a[n];
			n++;
		}
		dp[0]=1;
		if(sum%2==0){
			sum/=2;
			for(int i=0;i<n;i++){
				for(int j=sum;j>=a[i];j--){
					if(dp[j-a[i]]) dp[j]=1;
				}
			}
		}
		else{
			cout << "NO" << endl;
			continue;
		}
		
		if(dp[sum]==1) cout << "YES" << endl;
		else cout << "NO" << endl;
		
	}
	
	return 0;
}


