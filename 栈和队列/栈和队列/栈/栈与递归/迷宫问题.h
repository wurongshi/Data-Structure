struct offsets{
	int a;
	int b;
	string dir;
}; 
offsets Move[8]={{-1,0,"N"},{-1,1,"NE"},{0,1,"E"},{1,1,"SE"},{1,0,"S"},{1,-1,"SW"},{0,-1,"W"},{-1,-1,"NW"}};
const int m=3,p=3;
int Maze[m+2][p+2];
int mark[m+2][p+2];
int SeekPath(int x,int y){
	int i,g,h; string d;
	if(x==m&&y==p) return 1;
	for(i=0;i<8;i++){
		g=x+Move[i].a; h=y+Move[i].b; d=Move[i].dir;
		if(Maze[g][h]==0&&mark[g][h]==0){
			mark[g][h]=1;
			if(SeekPath(g,h)){
				cout<<"("<<g<<","<<h<<");  "<<"Direction:  "<<d<<endl;
				return 1;
			}
			mark[g][h]=0;
		}
	}
	if(x==1&&y==1) cout<<"no path in Maze!"<<endl;
	return 0;
}
