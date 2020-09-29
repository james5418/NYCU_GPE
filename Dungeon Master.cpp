#include <bits/stdc++.h>
using namespace std;

char dungeon[31][31][31];
int dist[31][31][31]={0};
int L,R,C;
const int direction[6][3]={{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

typedef struct point_type{
	int x;
	int y;
	int z;
}point_type;

int bfs(int i,int j,int k){
	dist[i][j][k]=0;
	queue<point_type> q;
	q.push(point_type{i,j,k});
	dungeon[i][j][k]='#';

	point_type cur,next;
	while(!q.empty()){
        cur = q.front();
        q.pop();

        for(int i=0;i<6;i++){
            next.x = cur.x + direction[i][0];
            next.y = cur.y + direction[i][1];
            next.z = cur.z + direction[i][2];

            if(next.x<0 || next.x>=L || next.y<0 || next.y>=R || next.z<0 || next.z>=C) continue;

            if(dungeon[next.x][next.y][next.z] != '#'){
                dist[next.x][next.y][next.z] = dist[cur.x][cur.y][cur.z]+1;
                if(dungeon[next.x][next.y][next.z]=='E'){
                    return dist[next.x][next.y][next.z];
                }
                dungeon[next.x][next.y][next.z]='#';
                q.push(next);
            }
        }
	}
	return -1;
}



int main(int argc, char** argv) {
    while(cin>>L>>R>>C){
        if(!L && !R && !C) break;
        int start_i,start_j,start_k;

        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
                cin>>dungeon[i][j];
                for(int k=0;k<C;k++){
                    if(dungeon[i][j][k] == 'S'){
                        start_i = i;
                        start_j = j;
                        start_k = k;
                    }
                }
            }
        }
        int minute = bfs(start_i,start_j,start_k);

        if(minute != -1) cout << "Escaped in " << minute << " minute(s)." << endl;
        else cout << "Trapped!" << endl;
    }

	return 0;
}

