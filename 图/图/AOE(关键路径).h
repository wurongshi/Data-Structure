template<class T,class E>
void CriticalPath(GraphmtxD<T,E> &G){
	int i,j,k;    E Ae,Al,w;
	int n=G.NumberOfVertices();
	E *Ve=new E[n];
	E *Vl=new E[n];
	for(i=0;i<n;i++){ Ve[i]=0; Vl[i]=maxValue; }
	for(i=0;i<n;i++){
		j=G.getFirstNeighbor(i);
		while(j!=-1){
			w=G.getWeight(i,j);
			if(Ve[i]+w>Ve[j]) Ve[j]=Ve[i]+w;
			j=G.getNextNeighbor(i,j);
		}
	}
	Vl[n-1]=Ve[n-1];
	for(j=n-2;j>0;j--){
		k=G.getFirstNeighbor(j);
		while(k!=-1){
			w=G.getWeight(j,k);
			if(Vl[k]-w<Vl[j]) Vl[j]=Vl[k]-w;
			k=G.getNextNeighbor(j,k);
		}
	}
	for(i=0;i<n;i++){
		j=G.getFirstNeighbor(i);
		while(j!=-1){
			Ae=Ve[i];  Al=Vl[j]-G.getWeight(i,j);
			if(Ae==Al) cout<<"<"<<G.getValue(i)<<","<<G.getValue(j)<<">"<<"是关键活动!"<<endl;
			j=G.getNextNeighbor(i,j);
		}
	}
	delete []Ve; delete []Vl;
}