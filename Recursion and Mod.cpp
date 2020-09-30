#include <bits/stdc++.h>
using namespace std;

long long cal(int a,long long n, long long b){
	if(n==1) return 3;
	else{
		long long result=cal(a,n/2,b);
		if(n%2==1) return (result*result*3)%b;
		else return (result*result)%b;
	}
}

int main(int argc, char** argv) {
	long long n;
	while(cin>>n){
		long long ans = cal(3,n,1000000009);
		cout << ans-2 << endl;
	}
	return 0;
}

