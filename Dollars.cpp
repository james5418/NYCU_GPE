#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	long long dp[30005]={1};
	int money[]={10000,5000,2000,1000,500,200,100,50,20,10,5};
	int part1,part2;
	char dot;
	for(int i=10;i>=0;i--){
		for(int j=money[i];j<=30000;j++){
			dp[j] += dp[j-money[i]];
		}
	}
	double n;
	while(cin>>n && n){
		long long x=(n+0.005)*100.0;
		cout << fixed << setprecision(2) << setw(6) << n << setw(17) << dp[x] << endl;
	}
	return 0;
}

