#include <bits/stdc++.h>
using namespace std;

struct Team{
	bool join;
	int num;
	int score;
	int problem;
	int error[10];
};

bool compare(Team a,Team b){
	if(a.problem != b.problem) return a.problem > b.problem;
	else if(a.score != b.score) return a.score < b.score;
	return a.num < b.num;
}

int main(int argc, char** argv) {
	int testcase;
	string entry;
	Team team[105];
	int contestant,problem,time;
	char L;
	
	
	while(cin>>testcase){
		getline(cin,entry);
		getline(cin,entry);
		for(int i=0;i<testcase;i++){
			if(i) cout << endl;
			for(int j=0;j<105;j++){
				team[j].join=0;
				team[j].num=j;
				team[j].score=0;
				team[j].problem=0;
				memset(team[j].error,0,sizeof(team[j].error));
			}
		
		
			while(getline(cin,entry) && entry!=""){
				stringstream ss(entry);
				ss >> contestant >> problem >> time >> L;
								
				team[contestant].join=true;
				if(team[contestant].error[problem] == -1) continue;
				if( L == 'C' ){
          			team[contestant].score += time+team[contestant].error[problem]*20;
          			team[contestant].problem++;
          			team[contestant].error[problem] = -1;
        		}
				else if(L=='I'){
					team[contestant].error[problem]++;
				}
				
			}
			
			sort(team,team+105,compare);
			
			for(int j=0;j<105;j++){
				if(team[j].join){
					cout << team[j].num << " " << team[j].problem << " " << team[j].score << endl;
				}
			}
		}
	}
	return 0;
}

