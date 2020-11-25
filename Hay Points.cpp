#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	int m,n;
	cin>>m>>n;
	map<string ,int> dict;
	while(m--){
		string word;
		int point;
		cin>>word>>point;
		dict[word]=point;
	}
	
	while(n--){
		string article;
		int total=0;
		while(cin>>article && article!="."){
			total += dict[article];
		}
		cout << total << endl;
	}
	
	return 0;
}

