#include<iostream>

using namespace std;

bool isAa_(char c){
	return (c>='a'&&c<='z')||(c>='a'&&c<='z')||(c=='_');
}

bool isAa_1(char c){
	return (c>='a'&&c<='z')||(c>='a'&&c<='z')||(c=='_')||(c>='0'&&c<='9');
}

static string skip_other(const char *s0) {
	string s;
	int i = 0;

	if(isAa_(s0[i])){
		s.push_back(s0[i]);
		i++;
	}
	while(isAa_1(s0[i])){
		s.push_back(s0[i]);
		i++;
	}
	if(s0[i]==' '){
		s.push_back(s0[i]);
		i++;
	}	
	while (s0[i] != '\0') {
		if (s0[i] != ' ' && s0[i] != '\t') {
			s.push_back(s0[i]);
		}
		i++;
	}
	return s;
}

bool parse_declaration(string s){
	unsigned int i=0;
	
	//解析定义类型 
	while(i<s.size()&&s[i]!=' '){
		i++;
	}
	//s[i]==' '
	string type=s.substr(0,i);
	
	//解析变量名 
	while(i<s.size()&&(!isAa_(s[i]))){
		i++;
	}
	//s[i]==字母
	
	int len=0;
	while(i+len<s.size()&&(isAa_1(s[i+len]))){
		len++;
	} 
	//s[i+len]!=字母数字下划线
	string v=s.substr(i,len);
	
	
	
	if(s[i+len]==' '){
		len++;
	}
	unsigned int r=i+len;
	unsigned int l=i-1;
	bool single=true; 
	
	string ans[100];
	int a=0;
	while(l>=type.size()||r<s.size()){
		while(r<s.size()&&s[r]!=';'&&s[r]!=')'){
			switch (s[r]) {
				case '(':
					r++;
					if(s[r]!=')'){
						return false;
					}else{
						r++;
						if(single){
							ans[a]="a function that returns ";
						}else{
							ans[a]="functions that returns ";
							single=true;
						}
						a++;
					}
					break;
				case '[':
					r++;
					len=0;
					if(s[r+len]<='9'&&s[r+len]>='0'){
						len++;
					}
					//s[r+len]!=数字 
					if(s[r+len]!=']'){
						return false;
					}else{
						if(len){
							if(single){
								ans[a]="an array of "+s.substr(r,len)+" ";
							}else{
								ans[a]="arrays of "+s.substr(r,len)+" ";
							}
							a++;
						}else{
							if(single){
								ans[a]="an array of ";
							}else{
								ans[a]="arrays of ";
							}
							a++;
						}
						single=false;
						r=r+len+1;
					} 
					break;
				default :
					return false;
			}
		}
		if(s[r]==')'){
			r++;
		}
		if(s[r]==';'){
			r++; 
		}
		while(l>=type.size()&&s[l]!='('){
			switch (s[l]) {
				case '*':
					if(single){
						ans[a]="a point to ";
					}else{
						ans[a]="points to ";
						single=true;
					}
					a++; 
					l--;
					break;
				default:
					l--;
					break;
			}
		}
		if(s[l]=='('){
			l--;
		}
	}
	
	cout<<"Variable "<<v<<" is ";
	for(int i=0;i<a;i++){
		cout<<ans[i];
	}
	
	if(single){
		cout<<"a "<<type;
	}else{
		cout<<type;
		single=true;
	}
	cout<<'.'; 
	return true;
}



int main()
{
	char s[200];
	
	cin.getline(s,200);
	
	
	parse_declaration(skip_other(s));



    return 0;
} 
