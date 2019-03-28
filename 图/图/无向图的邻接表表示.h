//#include"图的模板基类.h"
#include"stdlib.h"
template<class T,class E>
struct Edge{
	int dest;
	E cost;
	Edge<T,E> *link;
	Edge():dest(DefaultVertices),link(NULL){}
	Edge(int num):dest(num),link(NULL){}
	Edge(int num,E weight):dest(num),cost(weight),link(NULL){}
	bool operator!=(Edge<T,E> &R)const{
		return (dest!=R.dest)? true:false;
	}
};
template<class T,class E>
struct Vertex{
	T data;
	Edge<T,E> *adj;
};
template<class T,class E>
class Graphlnk:public Graph<T,E>{
public:
	friend istream &operator >> <>(istream &in,Graphlnk<T,E> &G);
	friend ostream &operator << <>(ostream &out,Graphlnk<T,E> &G);
	Graphlnk(int Sz=DefaultVertices);
	~Graphlnk();
	T getValue(int i){
		return (i>=0&&i<numVertices)? NodeTable[i].data:0;
	}
	E getWeight(int v1,int v2);
	bool insertVertex(const T &vertex);
	bool removeVertex(int v);
	bool insertEdge(int v1,int v2,E cost);
	bool removeEdge(int v1,int v2);
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v,int w);
	int getVertexPos(T vertex){
		for(int i=0;i<numVertices;i++)
			if(NodeTable[i].data==vertex) return i;
		return -1;
	}
private:
	Vertex<T,E> *NodeTable;	
};
template<class T,class E>
Graphlnk<T,E>::Graphlnk(int sz){
	maxVertices=sz; numVertices=0; numEdges=0;
	NodeTable=new Vertex<T,E>[maxVertices];
	if(NodeTable==NULL){  cout<<"存储分配错误！"<<endl; exit(1);  }
	for(int i=0;i<maxVertices;i++) NodeTable[i].adj=NULL;
};
template<class T,class E>
Graphlnk<T,E>::~Graphlnk(){
	for(int i=0;i<numVertices;i++){
		Edge<T,E> *p=NodeTable[i].adj;
		while(p!=NULL){
			NodeTable[i].adj=p->link;
			delete p; p=NodeTable[i].adj;
		}
	}
	delete []NodeTable;
}
template<class T,class E>
int Graphlnk<T,E>::getFirstNeighbor(int v){
	if(v!=-1){
		Edge<T,E> *p=NodeTable[v].adj;
		if(p!=NULL) return p->dest;
	}
	return -1;
}
template<class T,class E>
int Graphlnk<T,E>::getNextNeighbor(int v,int w){
	if(v!=-1){
		Edge<T,E> *p=NodeTable[v].adj;
		while(p!=NULL&&p->dest!=w)
			p=p->link;
		if(p!=NULL&&p->link!=NULL)
			return p->link->dest;
	}
	return -1;
}
template<class T,class E>
E Graphlnk<T,E>::getWeight(int v1,int v2){
	if(v1!=-1&&v2!=-1){
		Edge<T,E> *p=NodeTable[v1].adj;
		while(p!=NULL&&p->dest!=v2)
			p=p->link;
		if(p!=NULL) return p->cost;
	}
	return 0;
}
template<class T,class E>
bool Graphlnk<T,E>::insertVertex(const T &vertex){
	if(numVertices==maxVertices) return false;
	NodeTable[numVertices].data=vertex;
	numVertices++; return true;
}
template<class T,class E>
bool Graphlnk<T,E>::removeVertex(int v){
	if(numVertices==1||v<0||v>maxVertices) return false;
	Edge<T,E> *p,*s,*t;  int k;
	while(NodeTable[v].adj!=NULL){
		p=NodeTable[v].adj; k=p->dest;
		s=NodeTable[k].adj; t=NULL;
		while(s!=NULL&&s->dest!=v){
			t=s; s=s->link;
		}
		if(s!=NULL){
			if(t==NULL) NodeTable[k].adj=s->link;//k链后的第一个元素即为对称元素
			else t->link=s->link;
			delete s;
		}
		NodeTable[v].adj=p->link;
		delete p; numEdges--;
	}
	numVertices--;
	NodeTable[v].data=NodeTable[numVertices].data;
	p=NodeTable[v].adj=NodeTable[numVertices].adj;
	while(p!=NULL){
		s=NodeTable[p->dest].adj;
		while(s!=NULL)
			if(s->dest==numVertices){ s->dest=v;  break;  }
			else s=s->link;
		p=p->link;
	}
	return true;
}
template<class T,class E>
bool Graphlnk<T,E>::insertEdge(int v1,int v2,E weight){
	if(v1>=0&&v1<numVertices&&v2>=0&&v2<numVertices){
		Edge<T,E> *q,*p=NodeTable[v1].adj;
		while(p!=NULL&&p->dest!=v2) p=p->link;
		if(p!=NULL) return false;
		p=new Edge<T,E>; q=new Edge<T,E>;
		p->dest=v2;  p->cost=weight;
		p->link=NodeTable[v1].adj;
		NodeTable[v1].adj=p;
		q->dest=v1; q->cost=weight;
		q->link=NodeTable[v2].adj;
		NodeTable[v2].adj=q;
		numEdges++;  return true;
	}
	return false;
}
template<class T,class E>
bool Graphlnk<T,E>::removeEdge(int v1,int v2){
	if(v1!=-1&&v2!=-1){
		Edge<T,E> *p=NodeTable[v1].adj,*q=NULL,*s=p;
		while(p!=NULL&&p->dest!=v2){
			q=p;p=p->link;
		}
		if(p!=NULL){
			if(p==s) NodeTable[v1].adj=p->link;
			else q->link=p->link;
			delete p;
		}
		else return false;
		p=NodeTable[v2].adj; q=NULL,s=p;
		while(p!=NULL&&p->dest!=v1){
			q=p; p=p->link;
		}
		if(p==s) NodeTable[v2].adj=p->link;
		else q->link=p->link;
		delete p;
		return true;
	}
	return false;
}
template<class T,class E>
istream &operator >>(istream &in,Graphlnk<T,E> &G){
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
ostream &operator <<(ostream &out,Graphlnk<T,E> &G){
	int i,n,m;
	n=G.NumberOfVertices();  m=G.NumberOfEdges();
	Edge<T,E> *p;
	out<<n<<","<<m<<endl;
	for(i=0;i<n;i++){
		p=G.NodeTable[i].adj;
		while(p!=NULL){
			if(p->dest>i){
				out<<"("<<G.NodeTable[i].data<<","<<G.NodeTable[p->dest].data<<") "<<p->cost<<endl;
			}
			p=p->link;
		}
	}
	return out;
}

