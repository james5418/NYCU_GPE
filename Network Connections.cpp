#include <bits/stdc++.h>
using namespace std;

int Set[1000001];

void makeset(int n){
	for(int i=0;i<=n;i++){
		Set[i]=i;
	}
}

int findsetroot(int x){
	if(Set[x]==x) return x;
	return findsetroot(Set[x]);
}

void Union(int x,int y){
	x=findsetroot(x);
	y=findsetroot(y);
	if(x!=y) Set[y]=x;
}

int main(int argc, char** argv) {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	int cs,c;
	string line;
	cin>>cs;
	
	while(cs--){
		cin>>c;
		getline(cin,line);
		makeset(c);
		
		char type;
		int a,b;
		int numofsuccess=0,numofunsuccess=0;
		
		while(getline(cin,line) && line!=""){
			stringstream ss(line);
			ss>>type>>a>>b;
			
			if(type=='c') Union(a,b);
			else{
				if(findsetroot(a)==findsetroot(b)) ++numofsuccess;
				else ++numofunsuccess;
			}
		}
		cout << numofsuccess <<"," << numofunsuccess;
		if(cs) cout << endl;
		cout << endl;
		
	}
	
	return 0;
}

