#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int input[n+1];
        for(int i=1; i<n+1; i++)
        {
            cin>>input[i];
        }
        int answer[n+1];
        for(int i=0;i<n+1;i++)
        {
            answer[i]=1;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=i+1;j<n+1;j++)
            {
                if(input[j]>input[i])
                {
                    answer[j]=((answer[i]+1)>answer[j])?(answer[i]+1):(answer[j]);
                }
            }
        }
        int max=1;
        for(int i=1;i<n+1;i++)
        {
            if(answer[i]>max)max=answer[i];
        }
        cout<<max<<endl;
    }
    return 0;
}
