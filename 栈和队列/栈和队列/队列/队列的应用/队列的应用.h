void YANGVI(int n){     //打印二项展开式（a+b）^i的系数 
	SeqQueue<int> q;
	int i=1,j,s,k,t,u; s=k=0;
	q.EnQueue(i); q.EnQueue(i);
	for(i=1;i<=n;i++){
		cout<<endl;
		q.EnQueue(k);
		for(j=1;j<=i+2;j++){
			q.DeQueue(t);
			u=s+t; q.EnQueue(u);
			s=t;
			if(j!=i+2) cout<<s<<' ';
		}
	}
}
//------------------------------------------
//------------------------------------------
//------------------------------------------
//------------------------------------------
const int M=7;
int grid[M+2][M+2];
struct Position{
	int row;
	int col;
};
bool FindPath(Position start,Position finish,int &PathLen,Position *&path){
	if(start.row==finish.row&&start.col==finish.col){
		PathLen=0; return true;
	}
	int NuMOfNbrs=4,i,j;
	for(i=0;i<=M+1;i++){
		grid[0][i]=grid[M+1][i]=1;
		grid[i][0]=grid[i][M+1]=1;
	}
	Position offset[4];
	offset[0].row=0;  offset[0].col=1;
	offset[1].row=1;  offset[1].col=0;
	offset[2].row=0;  offset[2].col=-1;
	offset[3].row=-1; offset[3].col=0;
	Position here,nbr;
	here.row=start.row;  here.col=start.col;
	grid[start.row][start.col]=2;
	SeqQueue<Position> Q;
	do{
		for(i=0;i<NuMOfNbrs;i++){
			nbr.row=here.row+offset[i].row;
			nbr.col=here.col+offset[i].col;
			if(grid[nbr.row][nbr.col]==0){
				grid[nbr.row][nbr.col]=grid[here.row][here.col]+1;
				if(nbr.row==finish.row&&nbr.col==finish.col) break;
				Q.EnQueue(nbr);
			}
		}
		if(nbr.row==finish.row&&nbr.col==finish.col) break;
		if(Q.IsEmpty()==true) return false;
		Q.DeQueue(here);
	}while(true);
	PathLen=grid[finish.row][finish.col]-2;
	here=finish;
	for(j=PathLen-1;j>=0;j--){
		path[j]=here;
		for(i=0;i<NuMOfNbrs;i++){
			nbr.row=here.row+offset[i].row;
			nbr.col=here.col+offset[i].col;
			if(grid[nbr.row][nbr.col]==j+2) break;
		}
		here=nbr;
	}
	return true;
} 