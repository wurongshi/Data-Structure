//------------------深度优先遍历---------------------
template<class T,class E>
void DFS(Graphmtx<T,E> &G,const T &v){
	int i,loc,n=G.NumberOfVertices();
	bool *visited=new bool[n];
	for(i=0;i<n;i++) visited[i]=false;
	loc=G.getVertexPos(v);
	DFS(G,loc,visited);  cout<<endl;
	delete []visited;
}
template<class T,class E>
void DFS(Graphmtx<T,E> &G,int v,bool visited[]){
	cout<<G.getValue(v)<<" ";
	visited[v]=true;
	int w=G.getFirstNeighbor(v);
	while(w!=-1){
		if(visited[w]==false) DFS(G,w,visited);
		w=G.getNextNeighbor(v,w);
	}
}
//------------广度优先遍历------------------------
template<class T,class E>
void BFS(Graphmtx<T,E> &G,const T &v){
	int i,w,n=G.NumberOfVertices();
	bool *visited=new bool[n];
	for(i=0;i<n;i++) visited[i]=false;
	int loc=G.getVertexPos(v);
	cout<<G.getValue(loc)<<" ";
	visited[loc]=true;
	SeqQueue<int> Q; Q.EnQueue(loc);
	while(!Q.IsEmpty()){
		Q.DeQueue(loc);
		w=G.getFirstNeighbor(loc);
		while(w!=-1){
			if(visited[w]==false){
				cout<<G.getValue(w)<<" ";
				visited[w]=true;
				Q.EnQueue(w);
			}
			w=G.getNextNeighbor(loc,w);
		}
	}
	delete []visited;
	cout<<endl;
}
//---------------连通分量---------------------------
template<class T,class E>
void Components(Graphmtx<T,E> &G){
	int i,n=G.NumberOfVertices();
	bool *visited=new bool[n];
	for(i=0;i<n;i++) visited[i]=false;
	for(i=0;i<n;i++)
		if(visited[i]==false){
			DFS(G,i,visited);
			cout<<endl;
		}
}
