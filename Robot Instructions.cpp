#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){

        int n,x=0;
        cin>>n;
        string instr;
        int I[105]={0};
        getline(cin,instr);
        for(int i=0;i<n;i++){
            getline(cin,instr);
            if(instr[0]=='L'){
                I[i]=-1;
            }
            else if(instr[0]=='R'){
                I[i]=1;
            }
            else if(instr[0]=='S'){
                string tmp = instr.substr(8);
                stringstream ss(tmp);
                int num;
                ss>>num;
                I[i]=I[num-1];

            }
            x+=I[i];
        }
        cout << x << endl;
    }
    return 0;
}
