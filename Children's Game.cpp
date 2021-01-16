#include <bits/stdc++.h>
using namespace std;

bool cmp(string a,string b){
	return a+b > b+a;//降序排列 相同時短者排前 
}

int main(int argc, char** argv) {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n && n){
		vector<string> num;
		for(int i=0;i<n;i++){
			string tmp;
			cin>>tmp;
			num.push_back(tmp);
		}
		
		sort(num.begin(),num.end(),cmp);
		for(int i=0;i<n;i++){
			cout << num[i];
		}
		cout << "\n";
	}
	
	return 0;
}

