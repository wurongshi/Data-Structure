//-------------------------KruskalÀ„∑®-------------------------

template<class T,class E>
struct MSTEdgeNode{
	int tail,head; E key;
	MSTEdgeNode():tail(-1),head(-1),key(0){ }
	bool operator <=(MSTEdgeNode<T,E> &R){ return key<=R.key; }
	bool operator >(MSTEdgeNode<T,E> &R){ return key>R.key; }
};
template<class T,class E>
class MinSpanTree{
protected:
	MSTEdgeNode<T,E> *edgevalue;
	int maxSize,n;
public:
	MinSpanTree(int sz=DefaultSize-1):maxSize(sz),n(0){
		edgevalue=new MSTEdgeNode<T,E>[sz];
	}
	~MinSpanTree(){  delete []edgevalue;  }
	bool Insert(MSTEdgeNode<T,E> &item);
	friend ostream &operator << <>(ostream &out,MinSpanTree<T,E> &MST);
};
template<class T,class E>
bool MinSpanTree<T,E>::Insert(MSTEdgeNode<T,E> &item){
	if(n<maxSize-1){
		edgevalue[n++]=item;
		return true;
	}
	return false;
}
template<class T,class E>
ostream &operator <<(ostream &out,MinSpanTree<T,E> &MST){
	for(int i=0;i<MST.n;i++){
		out<<"("<<MST.edgevalue[i].tail<<","<<MST.edgevalue[i].head<<") "<<MST.edgevalue[i].key<<endl;
	}
	return out;
}
template<class T,class E>
void Kruskal(Graphmtx<T,E> &G,MinSpanTree<T,E> &MST){
	MSTEdgeNode<T,E> ed; int u,v,count;
	int n=G.NumberOfVertices();
	int m=G.NumberOfEdges();
	MinHeap<MSTEdgeNode<T,E>> H(m);
	UFSets F(n);
	for(u=0;u<n;u++)
		for(v=u+1;v<n;v++)
			if(G.getWeight(u,v)!=G.getmaxWeight()){
				ed.tail=u;  ed.head=v;
				ed.key=G.getWeight(u,v);
				H.Insert(ed);
			}
	count=1;
	while(count<n){
		H.RemoveMin(ed);
		u=F.Find(ed.tail);
		v=F.Find(ed.head);
		if(u!=v){
			F.Union(u,v);
			MST.Insert(ed);
			count++;
		}
	}
}
//----------------------------PrimÀ„∑®----------------------------
template<class T,class E>
void Prim(Graphmtx<T,E> &G,const T u0,MinSpanTree<T,E> &MST){
	MSTEdgeNode<T,E> ed;  int i,v,count;
	int n=G.NumberOfVertices();
	int m=G.NumberOfEdges();
	int u=G.getVertexPos(u0);
	MinHeap<MSTEdgeNode<T,E>> H(m);
	bool *Vmst=new bool[n];
	for(i=0;i<n;i++) Vmst[i]=false;
	Vmst[u]=true;
	count=1;
	do{
		v=G.getFirstNeighbor(u);
		while(v!=-1){
			 if(Vmst[v]==false){
				 ed.tail=u;  ed.head=v;
				 ed.key=G.getWeight(u,v);
				 H.Insert(ed);
			 }
			 v=G.getNextNeighbor(u,v);
		}
		while(H.IsEmpty()==false&&count<n){
			H.RemoveMin(ed);
			if(Vmst[ed.head]==false){
				MST.Insert(ed);
				u=ed.head;  Vmst[u]=true;
				count++;  break;
			}
		}
	}while(count<n);
}
