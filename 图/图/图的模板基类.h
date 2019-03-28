#include <iostream>
using namespace std;
const int DefaultVertices=30;
const int maxValue=numeric_limits<int>::max();
template<class T,class E>
class Graph{
	public:
		Graph(int sz=DefaultVertices){}
		~Graph(){}
        bool GraphEmpty()const{
        	if(numEdges==0) return true;
        	else return false;
		}
		bool GraphFull()const{
			if(numVertices==maxVertices&&numEdges==maxVertices*(maxVertices-1)/2) return true;
			else return false;
		}
		int NumberOfVertices(){ return numVertices;  }
		int NumberOfEdges(){  return numEdges;  }
		virtual T getValue(int i)=0;
		virtual E getWeight(int v1,int v2)=0;
		virtual int getFirstNeighbor(int v)=0;
		virtual int getNextNeighbor(int v,int w)=0;
		virtual bool insertVertex(const T &vertex)=0;
		virtual bool insertEdge(int v1,int v2,E cost)=0;
		virtual bool removeVertex(int v)=0;
		virtual bool removeEdge(int v1,int v2)=0;
		virtual int getVertexPos(T vertex)=0;
	protected:
		E maxWeight;
		int maxVertices;
		int numEdges;
		int numVertices;	
};