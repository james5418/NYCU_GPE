#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n;
	while(cin>>n && n){
		map<set<int>,int> count;
		int m=0,mc=0;
		while(n--){
			set<int> suit;
			for(int i=0;i<5;i++){
				int course;
				cin>>course;
				suit.insert(course);
			}
			count[suit]++;
			int h=count[suit];
			if(h==m) mc++;
			if(h>m) m=h,mc=1;
		}
		cout << m*mc << endl;
	}
	return 0;
}

