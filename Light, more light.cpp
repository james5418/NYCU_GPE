#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	long long n,root;
	while(cin>>n && n){
		root=sqrt(n);
		if(root*root==n) cout << "yes\n";
		else cout << "no\n";
	} 
	
	return 0;
}

