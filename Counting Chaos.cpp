#include <bits/stdc++.h>
using namespace std;

int palindromic[2400];

int main(){
	for(int i=0;i<24;i++){
		for(int j=0;j<60;j++){
			if(i==0){
				if(j<10 || j%10==j/10){
					palindromic[i*100+j] = 1;
				}
			} 
			else if(i<10){ 
				if(i==j%10){
					palindromic[i*100+j] = 1;
				}
			} 
			else{
				if(i/10==j%10 && i%10==j/10){
					palindromic[i*100+j] = 1;
				}
			}
		}
	}
	
	int n;
	string hm;
	cin>>n;
	while(n--){
		cin>>hm;
		int value=(hm[0]-'0')*1000 + (hm[1]-'0')*100 + (hm[3]-'0')*10 + (hm[4]-'0');
		
		if(value>=2332){
			printf("00:00\n");
		}
		else{
			for(int i=value+1;i<2400;i++){
				if(palindromic[i]){
					printf("%02d:%02d\n", i/100, i%100);
					break;
				}
			}
		}
	}
	return 0;
}
