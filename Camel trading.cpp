#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n;
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		long long smax[100],smin[100],tmp=0;
		int idx1=0,idx2=0;
		int slen=s.length();
		char op= '+';
		for(int i=0;i<=slen;i++){
			if(s[i]>='0' && s[i]<='9'){
				tmp = tmp*10 + s[i]-'0';
			}
			else{
				if(op=='+'){
					if(idx1==0) smax[idx1++]=tmp;
					else smax[idx1-1] += tmp;
					
					smin[idx2++] = tmp;
				}
				else{
					if(idx2==0) smin[idx2++]=tmp;
					else smin[idx2-1] *= tmp;
					
					smax[idx1++] = tmp;
				}
				op = s[i];
				tmp=0;
			}
		}
		long long amax=1,amin=0;
		for(int i=0;i<idx1;i++){
			amax *= smax[i];
		}
		for(int i=0;i<idx2;i++){
			amin += smin[i];
		}
		cout << "The maximum and minimum are " << amax << " and " << amin << "." << endl;
	}
	return 0;
}

