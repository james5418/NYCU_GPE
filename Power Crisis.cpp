#include <bits/stdc++.h>
using namespace std;

bool find(int n,int m){
	queue<int> crisis;
	for(int i=1;i<=n;i++){
		crisis.push(i);
	}
	int cnt=0;
	while(crisis.size()!=1){
		int target=crisis.front();
		crisis.pop();
		if(cnt%m!=0) crisis.push(target);
		++cnt;
	}
	return crisis.front()==13;
}

int main(int argc, char** argv) {
	int n;
	while(cin>>n && n){
		for(int m=1;;m++){
			if(find(n,m)){
				cout << m << endl;
				break;
			}
		}
	}
	return 0;
}


