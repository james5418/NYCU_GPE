#include <bits/stdc++.h>
using namespace std;

int F[10001];
int main(int argc, char** argv) {
	int m,n,t,e;
	while(cin>>m>>n>>t){
		for(int i=1;i<=t;i++){
			F[i]=-1;
		}
		F[0]=0;
		for(int i=m;i<=t;i++){
			//if(F[i]<F[i-m]+1) F[i]=F[i-m]+1;
			if(F[i-m] != -1) F[i] = max(F[i],F[i-m]+1);
		}
		for(int i=n;i<=t;i++){
			//if(F[i]<F[i-n]+1) F[i]=F[i-n]+1;
			if(F[i-n] != -1) F[i] = max(F[i],F[i-n]+1);
		}
		int e=t;
		while(F[e]<0) --e;
		cout << F[e];
		if(e==t) cout << endl;
		else cout << " " << t-e << endl;
	}
	return 0;
}

