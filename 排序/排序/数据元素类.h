template<class T>
class Element{
public:
	T key;
	Element<T> &operator =(Element<T> &x){
		key=x.key;    return *this;
	}
	bool operator ==(Element<T> &x){  return key==x.key;  }
	bool operator <=(Element<T> &x){  return key<=x.key;  }
	bool operator >(Element<T> &x){  return key>x.key;  }
	bool operator <(Element<T> &x){  return key<x.key;  }
};