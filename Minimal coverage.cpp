#include <bits/stdc++.h>
using namespace std;
int M;

struct Segment{
	int start,end;
};


bool cmp(Segment a,Segment b){
	if(a.start<b.start) return true;
	return false;
}

int main(int argc, char** argv) {
	int testcase;
	int tmp,left,right;
	Segment input;
	vector<Segment> line,ans;
	
	while(cin>>testcase){
		for(int i=0;i<testcase;i++){
			if(i) cout << endl;
			cin>>M;
			line.clear();
			while(cin>>input.start>>input.end && (input.start!=0 || input.end!=0)){
				line.push_back(input);
			}
			
			sort(line.begin(),line.end(),cmp);
			
			ans.clear();
			left=0;
			right=0;
			int j=0;
			
			while(j<line.size()){
				tmp=-1;
				for(;j<line.size() && line[j].start<=left;j++){
					if(line[j].end>right){
						right= line[j].end;
						tmp=j;
					}
				}
				
				if(tmp==-1) break;
				ans.push_back(line[tmp]);
				if(right>=M) break;
				left=right;
			
			}
			
			if(right<M){
				cout << "0" << endl;
				continue;
			}
			
			cout << ans.size() << endl;;
			for(int i=0;i<ans.size();i++){
				cout << ans[i].start << " " << ans[i].end << endl;
			}
		}
	}
	return 0;
}

