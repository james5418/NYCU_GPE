#include <bits/stdc++.h>
using namespace std;

int N[1000001];

int main(int argc, char** argv) {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	int n,m;
	while(cin>>n>>m){
		int left=0,right=0,mid;
		for(int i=0;i<n;i++){
			cin>>N[i];
			if(N[i]>left) left=N[i];
			right+=N[i];
		}
		
		while(left<right){
			mid=(left+right)/2;
			int sum=0; //milk
			int amount=0; //vessel
			
			for(int i=0;i<n;i++){
				sum += N[i];
				if(sum>mid){
					amount++;
					sum=N[i];
				}
				else if(sum==mid){
					amount++;
					sum=0;
				}
			}
			if(sum>0) amount++;
			
			if(amount>m) left=mid+1;
			else right=mid;
		}
		cout << left << endl;
	}
	
	return 0;
}

