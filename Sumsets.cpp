#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& v){
	int len=v.size();
	for(int d=len-1;d>=0;d--){
		for(int a=0;a<len;a++){
			for(int b=a+1;b<len;b++){
				for(int c=b+1;c<len;c++){
					if(v[d]==v[a]+v[b]+v[c] && a != d && b != d && c != d){
						return v[d];
					}
				}
			}
		}
	}
	return INT_MAX;
}

int main(int argc, char** argv) {
	int n;
	while(cin>>n && n){
		vector<int> v;
		int num;
		while(n--){
			cin>>num;
			v.push_back(num);
		}
		sort(v.begin(),v.end());

		int d=find(v);
		if(d==INT_MAX) cout << "no solution\n";
		else cout << d << "\n";
	}
	return 0;
}

