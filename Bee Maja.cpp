#include <bits/stdc++.h>
using namespace std;

struct point{
	int x,y;
}p[100001];

int idx;

void create(){
	p[1].x=0;
	p[1].y=0;
	idx=2;
	int nowI=0,nowJ=0,count;
	
	for(int num=1;idx<=100000;num++){
		for(int count=0;count<num && idx<=100000;count++,idx++){//down
			p[idx].x=nowI;
			p[idx].y=++nowJ;
		}
		for(int count=0;count<num-1 && idx<=100000;count++,idx++){//left down
			p[idx].x=--nowI;
			p[idx].y=++nowJ;
		}
		for(int count=0;count<num && idx<=100000;count++,idx++){//up
			p[idx].x=--nowI;
			p[idx].y=nowJ;
		}
		for(int count=0;count<num && idx<=100000;count++,idx++){//right up
			p[idx].x=nowI;
			p[idx].y=--nowJ;
		}
		for(int count=0;count<num && idx<=100000;count++,idx++){//right
			p[idx].x=++nowI;
			p[idx].y=--nowJ;
		}
		for(int count=0;count<num && idx<=100000;count++,idx++){//right down
			p[idx].x=++nowI;
			p[idx].y=nowJ;
		}
		
	}
}

int main(int argc, char** argv) {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	
	create();
	int n;
	while(cin>>n){
		cout << p[n].x << " " << p[n].y << endl;
	}
	
	return 0;
}

//https://using-c.blogspot.com/2010/06/problem-10182-bee-maja.html
