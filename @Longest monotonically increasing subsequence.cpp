//http://justimchung.blogspot.com/2018/06/blog-post.html
#include <bits/stdc++.h>
using namespace std;

void getMaxElementAndPos(vector<int>& lisb1,vector<int>& lislen,int tnum,int tlen,int tstart,int &num,int &pos){
	int max=0;
	int maxpos;
	for(int i=tstart;i>=0;i--){
		if(lislen[i]==tlen && lisb1[i]<tnum){
			if(lisb1[i]>max){
				max=lisb1[i];
				maxpos=i;
			}
		}
	}
	num=max;
	pos=maxpos;
}

int lis(vector<int>& lisb1){
	if(lisb1.size()==0) return 0;
	vector<int> lislen(lisb1.size(),1);
	for(int i=1;i<lisb1.size();i++){
		for(int j=0;j<i;j++){
			if(lisb1[j]<lisb1[i]){
				lislen[i] = max(lislen[i],lislen[j]+1);
			}
		}
	}
	int maxlen = *max_element(lislen.begin(),lislen.end());
	int num,pos;
	
	vector<int> buf;
	getMaxElementAndPos(lisb1,lislen,1e9,maxlen,lisb1.size()-1,num,pos);
	buf.push_back(num);
	for(int len=maxlen-1;len>=1;len--){
		int tnum=num;
		int tpos=pos;
		getMaxElementAndPos(lisb1,lislen,tnum,len,tpos-1,num,pos);
		buf.push_back(num);
	}
	
	reverse(buf.begin(),buf.end());
	cout << maxlen << endl;
	for(int k=0;k<buf.size();k++){
		cout << buf[k] << " ";
	}
	cout << endl;
	return maxlen;
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	while(n--){
		int t;
		cin>>t;
		vector<int> s;
		while(t--){
			int element;
			cin>>element;
			s.push_back(element);
		}
		lis(s);
		
		
		
		
		
	}
	return 0;
}

