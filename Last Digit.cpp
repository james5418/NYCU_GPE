#include <bits/stdc++.h>
using namespace std;

int table[200];

int NpowerN(int n){
	long long nn=1;
	for(int i=1;i<=n;i++){
		nn *= n;
		nn %= 10;
	}
	return nn;
}

int sum(int n){
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum += NpowerN(i);
		sum %= 10;
	}
	return sum;
}

// every 100 numbers is a cycle
int main(){
	for(int i=1;i<=100;i++){
		table[i%100] = sum(i);
	}
	
	string str;
	while ( cin >> str ) {
		int len = str.length();
		if ( len == 1 && str[0] == '0' ) break;
		
		int value = str[len-1]-'0';
		if ( len > 1 ) value += (str[len-2]-'0')*10;
		
		cout <<table[value] << endl;
	}
	return 0;
}
