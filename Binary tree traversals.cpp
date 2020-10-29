#include <bits/stdc++.h>
using namespace std;
int len,cnt;

int search(char arr[],int x,int n){
	for(int i=0;i<n;i++){
		if(arr[i]==x) return i;
	}
	return -1;
}

void printpost(char in[],char pre[],int n){
	int root=search(in,pre[0],n);
	
	if(root!=0) printpost(in,pre+1,root);
	if(root != n-1) printpost(in+root+1,pre+root+1,n-root-1);
	cnt++;
	if(cnt!=len) cout << pre[0] << " ";
	else cout << pre[0];
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	while(n--){
		cnt=0;
		cin>>len;
		
		char pre[26],in[26];
		for(int i=0;i<len;i++){
			cin>>pre[i];
		}
		for(int i=0;i<len;i++){
			cin>>in[i];
		}
		printpost(in,pre,len);
		cout << endl;
	}
	return 0;
}

