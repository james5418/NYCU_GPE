#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	int m,n;
	cin>>m>>n;
	vector<int> before,now;
	for(int cs=0;cs<m;cs++){
		
		for(int i=0;i<n;i++){
			int num;
			cin>>num;
			now.push_back(num);
			
		}
		
		int ans=0;
		
		for(int i=0;i<now.size();i++){
			ans ^= now[i];
		}
		for(int i=0;i<before.size();i++){
			ans ^= before[i];
		}
		
		n--;
		before=now;
		now.clear();
		if(cs) cout << ans << endl;
	}
	return 0;
}

