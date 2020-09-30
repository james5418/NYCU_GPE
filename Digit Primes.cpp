#include <bits/stdc++.h>
using namespace std;

int com[1000000]={0};
long long dpcom[1000001]={0};

void prime_table(){
	com[0]=com[1]=1;
	for(int i=2;i<1000;i++){
		if(com[i]) continue;
		for(int j=i+i;j<1000000;j+=i){
			com[j]=1;
		}
	}
}

bool isdigitprime(long long t){
	long long digit=0;
	while(t>0){
		digit += t%10;
		t/=10;
	}
	if(!com[digit]) return true;
	else return false;
}

void digitprime_table(){
	for(int i=2;i<=1000000;i++){
		if(com[i]==0 && isdigitprime(i)){
			dpcom[i]=dpcom[i-1]+1;
		}
		else{
			dpcom[i]=dpcom[i-1];
		}
	}
}


int main(int argc, char** argv) {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	cin>>n;
	prime_table();
	digitprime_table();
	while(n--){
		long long t1,t2;
		cin>>t1>>t2;
		
		cout << dpcom[t2]-dpcom[t1-1]<< endl;
		
		
	}
	return 0;
}
