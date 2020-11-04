#include <bits/stdc++.h>
using namespace std;

int n,sz;
char str[85];

struct Node{
	string name;
	map<string,int> vis;
}node[50005];

void insert(char *str){
	int len=strlen(str);
	str[len]='\\';
	int u=0;
	
	for(int i=0;i<=len;i++){
		string tmp="";
		while(str[i] != '\\'){
			tmp += str[i];
			i++;
		}
		
		if(!node[u].vis.count(tmp)){
			node[sz].vis.clear();
			node[sz].name = tmp;
			node[u].vis[tmp] = sz++;
		}
		
		u=node[u].vis[tmp];
	}
}

void init(){
	sz=1;
	node[0].vis.clear();
	while(n--){
		cin>>str;
		insert(str);
	}
}

void print(int u,int d){
	if(u){
		for(int i=0;i<d;i++) cout << " ";
		cout << node[u].name << endl;
	}
	for(map<string,int>::iterator it=node[u].vis.begin();it!=node[u].vis.end();it++){
		print(it->second,d+1);
	}
}

int main(int argc, char** argv) {
	while(cin>>n){
		init();
		print(0,-1);
		//cout << endl;
	}
	return 0;
}

