#include <bits/stdc++.h>
using namespace std;

int mp[101][101];


int main(int argc, char** argv) {
	int t,m,n;
	while(cin>>m>>n && m && n){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>mp[i][j];
			}
		}
		
		int mx=0,tmp,length,width;
		
		for(int i=0;i<m;i++){
			int sum[100]={};
			for(int j=i;j<m;j++){
				for(int k=0;k<n;k++){
					sum[k] += !mp[j][k];
					if(k==0 || tmp != length*width){
						tmp=0;
						length=0;
					}
					length++;
					width=j-i+1;
					tmp += sum[k];
					if(tmp==length*width) mx=max(mx,tmp);
				}
			}
		}
		cout << mx << endl;
	}
	return 0;
}

