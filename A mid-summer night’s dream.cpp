#include <bits/stdc++.h>
using namespace std;
int num[1000000];

int main(int argc, char** argv) {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	while(cin>>n){
		int ans1,ans2=0,ans3;
		for(int i=0;i<n;i++){
			cin>>num[i];
		}
		sort(num,num+n);
		
		for(int i=0;i<n;i++){
			if(n%2==1){
				ans1=num[(n-1)/2];
				ans3=1;
				if(num[(n-1)/2]==num[i]) ans2++;
			}
			else{
				ans1=num[n/2-1];
				ans3=num[n/2]-num[n/2-1]+1;
				if(num[n/2-1]==num[i] || num[n/2]==num[i]) ans2++;
				
			}
		}
		cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
	}
	
	return 0;
}

