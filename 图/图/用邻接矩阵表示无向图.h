//#include "图的模板基类.h"
template<class T,class E>
class Graphmtx:public Graph<T,E>{
	public:
		friend istream &operator >> <>(istream &in,Graphmtx<T,E> &G);
	    friend ostream &operator << <>(ostream &out,Graphmtx<T,E> &G);
		Graphmtx(int sz=DefaultVertices);
		~Graphmtx(){
			delete []VerticesList;
			delete []Edge;
		}
		T getValue(int i){
			return i>=0&&i<=numVertices? VerticesList[i]:0;
		}
		E getWeight(int v1,int v2){
			return v1!=-1&&v2!=-1? Edge[v1][v2]:0;
		}
		int getFirstNeighbor(int v);
		int getNextNeighbor(int v,int w);
		bool insertVertex(const T &vertex);
		bool insertEdge(int v1,int v2,E cost);
		bool removeVertex(int v);
		bool removeEdge(int v1,int v2);
		int getVertexPos(T vertex){
			for(int i=0;i<numVertices;i++){
				if(VerticesList[i]==vertex)  return i;
			}
			return -1;
		}
		E getmaxWeight(){  return maxWeight;  }
	private:	
		T *VerticesList;
		E **Edge;	
};
template<class T,class E>
Graphmtx<T,E>::Graphmtx(int sz){
	maxWeight=maxValue;
	maxVertices=sz; numVertices=0; numEdges=0;
	int i,j;
	VerticesList=new T[maxVertices];
	Edge=(E**)new E *[maxVertices];
	for(i=0;i<maxVertices;i++)
	    Edge[i]=new E[maxVertices];
	for(i=0;i<maxVertices;i++)
	   for(j=0;j<maxVertices;j++)
	      Edge[i][j]=(i==j)? 0:maxWeight;
}
template<class T,class E>
int Graphmtx<T,E>::getFirstNeighbor(int v){
	if(v!=-1){
		for(int col=0;col<numVertices;col++)
			if(Edge[v][col]>0&&Edge[v][col]<maxWeight) return col;
	}
	return -1;
}
template<class T,class E>
int Graphmtx<T,E>::getNextNeighbor(int v,int w){
	if(v!=-1&&w!=-1){
		for(int col=w+1;col<maxVertices;col++)
			if(Edge[v][col]>0&&Edge[v][col]<maxWeight) return col;
	}
    return -1;
}
template<class T,class E>
bool Graphmtx<T,E>::insertVertex(const T &vertex){
	if(numVertices==maxVertices) return false;
	VerticesList[numVertices++]=vertex;
	return true;
}
template<class T,class E>
bool  Graphmtx<T,E>::removeVertex(int v){
	if(v<0||v>=numVertices) return false;
	if(numVertices==1) return false;
	int i,j;
	VerticesList[v]=VerticesList[numVertices-1];
	for(i=0;i<numVertices;i++){
		if(Edge[i][v]>0&&Edge[i][v]<maxWeight)
			numEdges--;
	}
	for(i=0;i<numVertices;i++)
		Edge[i][v]=Edge[i][numVertices-1];
	numVertices--;
	for(j=0;j<numVertices;j++)
		Edge[v][j]=Edge[numVertices][j];
	return true;
}
template<class T,class E>
bool Graphmtx<T,E>::insertEdge(int v1,int v2,E cost){
	if(v1>-1&&v1<numVertices&&v2>-1&&v2<numVertices&&Edge[v1][v2]==maxWeight){
		Edge[v1][v2]=Edge[v2][v1]=cost;
		numEdges++;
		return true;
	}
	else return false;
}
template<class T,class E>
bool Graphmtx<T,E>::removeEdge(int v1,int v2){
	if(v1>-1&&v1<numVertices&&v2>-1&&v2<numVertices&&Edge[v1][v2]>0&&Edge[v1][v2]<maxWeight){
		Edge[v1][v2]=Edge[v2][v1]=maxWeight;
		numEdges--;
		return true;
	}
	else return false;
}
template<class T,class E>
istream &operator >>(istream &in,Graphmtx<T,E> &G){
	int i,j,k,n,m; T e1,e2; E weight;
	cout<<"建立一个图，输入图的顶点数和边数：";
	in>>n>>m;
	cout<<"输入顶点:"<<endl;
	for(i=0;i<n;i++){
		in>>e1;  G.insertVertex(e1);
	}
	i=0;
	cout<<"输入顶点和边的对应关系"<<endl;
	while(i<m){
		in>>e1>>e2; in>>weight;
		j=G.getVertexPos(e1); k=G.getVertexPos(e2);
		if(j==-1||k==-1)
			cout<<"边两端点信息有误，重新输入！"<<endl;
		else{
			G.insertEdge(j,k,weight); i++;
		}
	}
	return in;
}
template<class T,class E>
ostream &operator <<(ostream &out,Graphmtx<T,E> &G){
	int i,j,n,m; T e1,e2;  E w;
	n=G.NumberOfVertices();  m=G.NumberOfEdges();
	out<<n<<","<<m<<endl;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			w=G.getWeight(i,j);
			if(w>0&&w<maxValue){
				e1=G.getValue(i);  e2=G.getValue(j);
				out<<"("<<e1<<","<<e2<<")"<<" "<<w<<endl;
			}
		}
	return out;
}
