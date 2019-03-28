template<class T>                                   //括号匹配问题 
 void PrintMatchedPairs(char *expression){          //括号匹配问题 
 	SeqStack<int> s(maxLength);
 	int j,length=strlen(expression);
 	for(int i=1;i<=length;i++){
 		if(expression[i-1]=='(') s.Push(i);
 		else if(expression[i-1]==')') {
 			if(s.Pop(j)==true) cout<<j<<"与"<<i<<"匹配！"<<endl;
			else cout<<"没有与第"<<i<<"个有括号匹配的左括号！"<<endl; 
		 }
	 }
	while(s.IsEmpty()==false){
		s.Pop(j);
		cout<<"没有与第"<<j<<"个左括号匹配的右括号！"<<endl;
	}
 }