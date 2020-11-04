#include <bits/stdc++.h>
using namespace std;

int a[10004];
int f[10004][104];

int main(int argc, char** argv) {
	int t,n,k;
	while(cin>>t){
		while(t--){
			cin>>n>>k;
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			for(int i=0;i<n;i++){
				a[i]=abs(a[i])%k;
			}
			
			memset(f,0,sizeof(f));
			f[0][0]=1;
			
			for(int i=0;i<n;i++){
				for(int j=0;j<k;j++){
					if(f[i][j]){
						f[i+1][(j+a[i]+k)%k] = 1;
						f[i+1][(j-a[i]+k)%k] = 1;
					}
				}
			}
			if(f[n][0]) cout << "Divisible\n";
			else cout << "Not divisible\n";
			
		}
	}
	return 0;
}

