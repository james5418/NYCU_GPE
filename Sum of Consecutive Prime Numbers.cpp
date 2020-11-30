#include <bits/stdc++.h>
using namespace std;

int dp[10005];
int P[10005];

void prime_table(){
	P[0]=P[1]=1;
	for(int i=2;i<=100;i++){
		if(P[i]) continue;
		for(int j=i*2;j<=10000;j+=i){
			P[j]=1; 
		}
	}
}

int main(int argc, char** argv) {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	vector<int> pt;
	prime_table();
	
	for(int i=2;i<=10000;i++){
		if(!P[i]){
			pt.push_back(i);
			dp[i]++;
		}
	}
	
	for(int e=1;e<pt.size();e++){
		for(int i=0;i<pt.size();i++){
			int j=i+e;
			if(j>pt.size()-1) break;
			
			long long sum=0;
			for(int k=i;k<=j;k++){
				sum+=pt[k];
			}
			if(sum<=10000) dp[sum]++;
		}
	}
	
	while(cin>>n && n){
		cout << dp[n] << endl;
	}
	
	return 0;
}

