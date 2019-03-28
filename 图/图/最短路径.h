//--------------------------Dijkstra算法---------------------------------
template<class T,class E>
void ShortestPath(GraphmtxD<T,E> &G,T v,E dist[],int path[]){
	int n=G.NumberOfVertices();
	bool *S=new bool[n];
	int i,j,k; E w,min;
	for(i=0;i<n;i++){
		dist[i]=G.getWeight(v,i);
		S[i]=false;
		if(i!=v&&dist[i]<maxValue)  path[i]=v;
		else path[i]=-1;
	}
	S[v]=true;   dist[v]=0;
	for(i=0;i<n-1;i++){
		min=maxValue;  int u=v;
		for(j=0;j<n;j++)
			if(S[j]==false&&dist[j]<min){  u=j; min=dist[j];  }
		S[u]=true;
		for(k=0;k<n;k++){
			w=G.getWeight(u,k);
			if(S[k]==false&&w<maxValue&&dist[u]+w<dist[k]){
				dist[k]=dist[u]+w;
				path[k]=u;
			}
		}
	}
	printShortestPath(G,v,dist,path);
}
//------------------------Bellman-Ford算法---------------------------------
template<class T,class E>
void Bellman_Ford(GraphmtxD<T,E> &G,int v,E dist[],int path[]){
	int i,k,u,n=G.NumberOfVertices();   E w;
	for(i=0;i<n;i++){
		dist[i]=G.getWeight(v,i);
		if(i!=v&&dist[i]<maxValue) path[i]=v;
		else path[i]=-1;
	}
	for(k=2;k<n;k++)
		for(u=0;u<n;u++)
			if(u!=v)
				for(i=0;i<n;i++){
					w=G.getWeight(i,u);
					if(w>0&&w<maxValue&&dist[u]>dist[i]+w){
						dist[u]=dist[i]+w;
						path[u]=i;
					}
				}
	printShortestPath(G,v,dist,path);
}
template<class T,class E>
void printShortestPath(GraphmtxD <T,E> &G,int v,E dist[],int path[]){
	cout<<"从顶点"<<G.getValue(v)<<"到其它各顶点的最短路径为："<<endl;
	int i,j,k,n=G.NumberOfVertices();
	int *d=new int[n];
	for(i=0;i<n;i++){
		if(i!=v){
			j=i;  k=0;
			while(j!=v){ d[k++]=j; j=path[j];  }
			cout<<"顶点"<<G.getValue(i)<<"的最短路径为："<<G.getValue(v)<<" ";
			while(k>0){  cout<<G.getValue(d[--k])<<" ";  }
			cout<<"最短路径长度为："<<dist[i]<<endl;
		}
	}
	delete []d;
}
//------------------------Floyd算法------------------------
template<class T,class E>
void Floyd(GraphmtxD<T,E> &G){
	int i,j,k,n=G.NumberOfVertices();
	int **path; E **a;
	a=new E *[100]; path=new int *[100];
	for(i=0;i<100;i++){
		path[i]=new int[100];
		a[i]=new int[100];
	}
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			a[i][j]=50;
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			a[i][j]=G.getWeight(i,j);
			if(a[i][j]==maxValue)  a[i][j]=50;
			if(i!=j&&a[i][j]<50) path[i][j]=i;
			else path[i][j]=0;
		}
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(a[i][k]+a[k][j]<a[i][j]){
					a[i][j]=a[i][k]+a[k][j];
					path[i][j]=path[k][j];
				}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	delete []a; delete []path;
}