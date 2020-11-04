#include <bits/stdc++.h>
using namespace std;

int ans[1001];
int pd[3000];
int main(int argc, char** argv) {
	pd[0]=1;
	for(int i=1;i<1000;i++){
		for(int k=0;k<3000;k++) pd[k]*=i;
		for(int k=0;k<3000;k++){
			pd[k+1] += pd[k]/10;
			pd[k]%=10;
		}
		for(int k=0;k<3000;k++) ans[i] += pd[k];
	}
	int n;
	while(cin>>n){
		cout << ans[n] << endl;
	}
	return 0;
}

