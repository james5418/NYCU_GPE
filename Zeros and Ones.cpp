#include <bits/stdc++.h>
using namespace std;
int sum[1000001];
int main(int argc, char** argv) {
	string s;
	int cas=1;
	
	while(cin>>s){
		cout << "Case " << cas <<":"<<endl;
		cas++;
		sum[0]=0;
		int len=s.length();
		for(int i=1;i<len;i++){
			sum[i]=sum[i-1];
			if(s[i]!=s[i-1]){
				sum[i]++;
			}
		}
		
		int c;
		cin>>c;
		while(c--){
			int i,j;
			cin>>i>>j;
			int m=min(i,j);
			int M=max(i,j);
			if(sum[m]==sum[M]) cout<<"Yes"<<endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}

