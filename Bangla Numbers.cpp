#include <bits/stdc++.h>
using namespace std;

void print_number(long long n){
	if(n==0) return;
	
	if(n/10000000){
		print_number(n/10000000);
		cout << " kuti";
		n%=10000000;
	}
	
	if(n/100000){
		print_number(n/100000);
		cout << " lakh";
		n%=100000;
	}
	
	if(n/1000){
		print_number(n/1000);
		cout << " hajar";
		n%=1000;
	}
	
	if(n/100){
		print_number(n/100);
		cout << " shata";
		n%=100;
	}
	
	if(n) cout << " " << n;
}

int main(int argc, char** argv) {
	long long n;
	int num=1;
	while(cin>>n){
		cout << num << ".";
		if(n) print_number(n);
		else cout << " 0";
		cout << endl;
		num++;
	}
	return 0;
}

