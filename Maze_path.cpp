#include<iostream>
using namespace std;
bool Maze_path(char maze[5][5],int ans[10][10],int i,int j,int n,int m){
	if(i==n-1&&j==m-1){
		ans[i][j]=1;
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				cout<<ans[a][b];
			}
			cout<<endl;
		}
		cout<<endl;
		return true;//return false //if you want print all possible path.
	}
	ans[i][j]=1;
	if(maze[i][j+1]!='X'&&j+1<m){
		bool inrightway=Maze_path(maze,ans,i,j+1,n,m);
		if(inrightway==true){
			return true;
		}
	}
	if(maze[i+1][j]!='X'&&i+1<n){
		bool indownway=Maze_path(maze,ans,i+1,j,n,m);
		if(indownway==true){
			return true;
		}
	}
	ans[i][j]=0;
	return false;
}
int main(){
	char maze[5][5]={
	"0000",
	"00XX",
	"0000",
	"XX00"};
	int ans[10][10]={0};
	Maze_path(maze,ans,0,0,4,4);
	return 0;
}
