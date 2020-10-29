#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	long long s,d,area;
	while(cin>>s>>d){
		for(int i=0;;i++){
			area = (s+(s+i))*(i+1)/2;
			if(area>=d){
				cout << s+i << endl;
				break;
			}
		}
	}
	return 0;
}

