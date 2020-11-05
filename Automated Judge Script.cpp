#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int m,n;
	int runcase=0;
	string ans,output,input;
	bool ac,pe;
	
	while(cin>>n && n){
		getline(cin,input);
		ans="";
		output="";
		for(int i=0;i<n;i++){
			getline(cin,input);
			if(i){
			 	ans += '\n';
			 	ans += input;
			}
			else ans += input;
		}
		
		cin>>m;
		getline(cin,input);
		for(int i=0;i<m;i++){
			getline(cin,input);
			if(i){
			 	output += '\n';
			 	output += input;
			}
			else output += input;
		}
		
		ac=true;
		if(ans!=output) ac=false;
		if(ac){
			cout << "Run #"<< ++runcase << ": Accepted" << endl;
			continue;
		}
		
		
		pe=true;
		for(int i=0;i<ans.length();i++){
			if(!isdigit(ans[i])){
				ans.erase(i,1);
				i--;
			}
		}
		for(int i=0;i<output.length();i++){
			if(!isdigit(output[i])){
				output.erase(i,1);
				i--;
			} 
		}
		
		if(ans!=output) pe=false;
		if(pe){
			cout << "Run #"<< ++runcase << ": Presentation Error" << endl;
			continue;
		}
		
		
		cout << "Run #"<< ++runcase << ": Wrong Answer" << endl;
	}
	return 0;
}

