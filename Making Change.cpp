#include<bits/stdc++.h>
using namespace std;

int dp1[1010];
int cointype[6]={5,10,20,50,100,200};

void coin(){
	for(int i=0;i<6;i++){
		for(int j=0;j<500;j++){
			if(dp1[j]<1000000){
				dp1[j+cointype[i]] = min(dp1[j+cointype[i]],dp1[j]+1);
				//(i==0,j==0) dp1[5]=min(dp1[5],dp[0]+1) => dp1[5]=1
				//(i==0,j==5) dp1[10]=min(dp1[10],dp[5]+1) => dp1[10]=1+1=2
				//(i==1,j==0) dp1[10]=min(dp1[10],dp[0]+1) => dp1[10]=1
				//(i==1,j==5) dp1[15]=min(dp1[15],dp[5]+1) => dp1[15]=2
			}
		}
	}
}

int main(){
	double f;
	int sum,dp[1010];
	int c5,c10,c20,c50,c100,c200;
	dp1[0]=0;
	for(int i=1;i<=1000;i++){
		dp1[i]=1000000;
	}
	
	coin();
	
	while(cin>>c5>>c10>>c20>>c50>>c100>>c200>>f){
		if(c5+c10+c20+c50+c100+c200==0) break;
		
		vector<int> a;
		for(int i=0;i<c5;i++) a.push_back(5);
		for(int i=0;i<c10;i++) a.push_back(10);
		for(int i=0;i<c20;i++) a.push_back(20);
		for(int i=0;i<c50;i++) a.push_back(50);
		for(int i=0;i<c100;i++) a.push_back(100);
		for(int i=0;i<c200;i++) a.push_back(200);
		
		sum=(f+0.005)*100.0;
		
		dp[0]=0;
		for(int i=1;i<=1000;i++){
			dp[i]=100000;
		}
		for(int i=0;i<a.size();i++){
			for(int j=1000-a[i];j>=0;j--){
				if(dp[j]<100000){
					dp[j+a[i]] = min(dp[j+a[i]],dp[j]+1);
				}
			}
		}
		int ans=1000000;
		for(int i=sum,j=0;i<=1000;i++,j++){
			ans = min(ans,dp[i]+dp1[j]);
		}
		cout << setw(3) << ans << endl;
	}
	
	return 0;
}

