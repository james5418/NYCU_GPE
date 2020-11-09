#include <bits/stdc++.h>
using namespace std;

int dp[52][52];
int table[52];

int main(int argc, char** argv) {
	int length,n;
	while(cin>>length && length){
		cin>>n;
		memset(dp,0,sizeof(dp));
		memset(table,0,sizeof(table));
		
		//n++;
		table[0]=0;
		table[n+1]=length;
		
		for(int i=1;i<=n;i++){
			cin>>table[i];
		}
		
		int tmp;
		//r=range(from 0 to r)
		for(int r=2;r<=n+1;r++){
			for(int b=0;b<=n;b++){
				int e = b+r;
				if(e>n+1) break;
				
				dp[b][e]=INT_MAX;
				
				for(int c=b+1;c<e;c++){
					dp[b][e] = min(dp[b][e], dp[b][c]+dp[c][e]+table[e]-table[b]);					
				}
			}
		}
		cout << "The minimum cutting is " << dp[0][n+1] << "." <<endl;
	}
	return 0;
}
//http://worldofmonmon.blogspot.com/2018/02/uva-10003-cutting-sticks-dp.html
