#include <bits/stdc++.h>
using namespace std;

long long fib[51];

int main(int argc, char** argv) {
	fib[0]=1;
	fib[1]=1;
	for(int i=2;i<=50;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	int num;
	while(cin>>num && num){
		cout << fib[num] << endl;
	}
	return 0;
}

