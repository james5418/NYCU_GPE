#include <bits/stdc++.h>
using namespace std;

int min_represent(string a){
	int len=a.length();
	a+=a;
	int i=0,j=1,k=0;
	int x=i,y=j;
	
	while(i<len && j<len){
		if(a[i+k]==a[j+k]){
			k++;
			if(k==len) break;
		}
		else if(a[i+k]>a[j+k]){
			i=i+k+1;
			if(i<=j) i=j+1;
			k=0;
		}
		else{
			j=j+k+1;
			if(j<=i) j=i+1;
			k=0; 
		}
	}
	return min(i,j)+1;
	
}

int main(int argc, char** argv) {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	cin>>n;
	string a;
	while(n--){
		cin>>a;
		cout << min_represent(a) << endl;
	}
	return 0;
}

