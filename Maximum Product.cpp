#include <bits/stdc++.h>
using namespace std;


int main(int argc, char** argv) {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	int n,cs=1;
	long long s[20],maxproduct,tmp;
	
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>s[i];
		}

		maxproduct=0;
		
		for(int i=0;i<n;i++){
			tmp=1;
			for(int j=i;j<n;j++){
				tmp *= s[j];
				if(tmp>maxproduct) maxproduct=tmp;
			}
		}
		cout << "Case #" << cs++ <<": The maximum product is " << maxproduct << "." << endl << endl;
	}
	
	return 0;
}

