template<class T,class E>
void TopologicalSort(GraphmtxD<T,E> &G){
	int i,j,w,v;  E weight=1;
	int top=-1;
	int n=G.NumberOfVertices();
	int *count=new int[n];
	for(i=0;i<n;i++) count[i]=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G.getWeight(i,j)>0&&G.getWeight(i,j)!=maxValue) count[j]++;
	for(i=0;i<n;i++)
		if(count[i]==0){ count[i]=top; top=i;  }
	cout<<"ÍØÆËÅÅÐò£º"<<endl;
	for(i=0;i<n;i++)
		if(top==-1){  cout<<"ÍøÂçÖÐÓÐ»ØÂ·£¡"<<endl;  return;  }
		else{
			v=top;  top=count[top];          //ÍËÕ»
			cout<<G.getValue(v)<<" ";
			w=G.getFirstNeighbor(v);
			while(w!=-1){
				if(--count[w]==0){ count[w]=top; top=w; }   //½øÕ»
				w=G.getNextNeighbor(v,w);
			}
		}
	cout<<endl;
}