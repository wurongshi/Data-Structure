template<class T>                                   //����ƥ������ 
 void PrintMatchedPairs(char *expression){          //����ƥ������ 
 	SeqStack<int> s(maxLength);
 	int j,length=strlen(expression);
 	for(int i=1;i<=length;i++){
 		if(expression[i-1]=='(') s.Push(i);
 		else if(expression[i-1]==')') {
 			if(s.Pop(j)==true) cout<<j<<"��"<<i<<"ƥ�䣡"<<endl;
			else cout<<"û�����"<<i<<"��������ƥ��������ţ�"<<endl; 
		 }
	 }
	while(s.IsEmpty()==false){
		s.Pop(j);
		cout<<"û�����"<<j<<"��������ƥ��������ţ�"<<endl;
	}
 }