#include <iostream>
using namespace std;

#define MAX 100

int strlen1(char s[]){
	int i = 0;
	while(s[i] !='\0')i++;
	return i;
}

void strcpy1(char a[], char b[]){
	int i= 0;
	while(b[i] != '\0'){
		a[i] = b[i];
		i++;
	}
	a[i]='\0';
}

int strcmp1(const char a[], const char b[]){
	int i = 0;

	while(a[i] !='\0' && b[i] !='\0'){
		if(a[i] !=b[i]) return a[i]-b[i];
		i++;
	}
	return a[i] - b[i];
}

bool digit(char c){ return c >='0' && c <='9'; }

double atof1(char s[]){
	double num = 0;
	int i = 0;
	bool neg = false;
	if(s[0] =='-'){
		neg = true;
		i++;
	}

	while(digit(s[i])){
		num=num*10+(s[i]-'0');
		i++;
	}

	if(s[i]=='.'){
		i++;
		double p = 0.1;

		while(digit(s[i])){
			num = num+(s[i]-'0')*p;
			p = p/10;
			i++;
		}
	}

	if(neg) num =- num;
	return num;
}

double power(double a, double b){
	double ans =1;
	int n = (int)b;

	if(n < 0){
		n=-n;
		for(int i = 0;i < n; i++) ans =ans*a;
		return 1/ans;
	}
	for(int i = 0;i < n; i++) ans =ans*a;
	return ans;
}

char opStack[MAX][10];
int top = -1;

void push(char op[]){
	top++;
	strcpy1(opStack[top], op);
}

char* pop(){
	return opStack[top--];
}

char* peek(){
	return opStack[top];
}

int priority(char op[]){
	if(strcmp1(op,"^") == 0 ) return 3;
	if(strcmp1(op,"*") == 0 || strcmp1(op,"/") == 0) return 2;
	if(strcmp1(op,"+") == 0 || strcmp1(op,"-") == 0) return 1;
	return 0;
}

bool isOperator(char s[]){
	if(strcmp1(s,"+") == 0 || strcmp1(s,"-") == 0 || strcmp1(s,"*") == 0 || strcmp1(s,"/") == 0 || strcmp1(s,"^") == 0)return true;
	return false;
}

int makeTokens(char expr[], char tokens[][20]){
	int i = 0;
	int count = 0;

	while(expr[i] !='\0'){
		if(expr[i] ==' '){
			i++;
			continue;
		}
		if(digit(expr[i]) || expr[i]=='.'){
			int j= 0;
			while(digit(expr[i]) || expr[i] =='.'){
				tokens[count][j] = expr[i];
				i++;
				j++;
			}
			tokens[count][j] ='\0';
			count++;
		}
		else{
			tokens[count][0] = expr[i];
			tokens[count][1] = '\0';
			count++;
			i++;
		}
	}
	return count;
}

void postfix(char tokens[][20],int n,char result[][20],int &count){

	top=-1;
	count=0;
	for(int i=0;i<n;i++){
		if(strcmp1(tokens[i],"(") == 0){ push(tokens[i]);}
		else if(strcmp1(tokens[i],")") == 0){

			while(top!= -1 && strcmp1(peek(),"(") !=0){
				strcpy1(result[count], pop());
				count++;
			}
			if(top!=-1)pop();
			}
		else if(isOperator(tokens[i])){
			while(top!=-1 && strcmp1(peek(),"(")!=0 && priority(peek()) >= priority(tokens[i])){
				strcpy1(result[count],pop());
				count++;
			}
			push(tokens[i]);
		}
		else{
			strcpy1(result[count], tokens[i]);
			count++;
		}
	}
	while(top!=-1){
		strcpy1(result[count], pop());
		count++;
	}
}
double values[MAX];
int vtop=-1;

void pushValue(double x){
	vtop++;
	values[vtop]=x;
}
double popValue(){return values[vtop--];}

double calculate(char post[][20],int n,double x){
	vtop=-1;

	for(int i = 0;i <n; i++){
		if(isOperator(post[i])){
			double b = popValue();
			double a = popValue();
			double ans;

			if(strcmp1(post[i],"+") == 0) ans = a+b;
			else if(strcmp1(post[i],"-") == 0) ans = a-b;
			else if(strcmp1(post[i],"*") == 0) ans=a*b;
			else if(strcmp1(post[i],"/") == 0) ans=a/b;
			else ans=power(a,b);
			pushValue(ans);
		}
		else if(strcmp1(post[i],"x") == 0 || strcmp1(post[i],"X") ==0){pushValue(x);}
		else{ pushValue(atof1(post[i]));}
	}
	return popValue();
}

bool condition(char s[], double x){

	int i = 0;

	while(s[i] ==' ') i++;
	if(s[i]!='x' && s[i]!='X')return false;
	i++;
	
	while(s[i]==' ') i++;
	char op[3];

	if((s[i]=='>' || s[i]=='<' || s[i]=='=' || s[i]=='!') && s[i+1]=='='){
		op[0]=s[i];
		op[1]='=';
		op[2]='\0';
		i=i+2;
	}
	else{
		op[0]=s[i];
		op[1]='\0';
		i++;
	}
	while(s[i] ==' ') i++;

	double num =atof1(s+i);

	if(strcmp1(op,">") == 0) return x > num;
	if(strcmp1(op,"<") == 0) return x < num;
	if(strcmp1(op,">=") == 0) return x >= num;
	if(strcmp1(op,"<=") == 0) return x <= num;
	if(strcmp1(op,"==") == 0) return x == num;
	if(strcmp1(op,"!=") == 0) return x != num;
	return false;
}

int main(){

	char expr1[100],expr2[100];
	char cond1[50],cond2[50];

	double x;

	cout<<"Enter Expression 1: ";
	cin.getline(expr1,100);

	cout<<"Enter Condition 1: ";
	cin.getline(cond1,50);

	cout<<"Enter Expression 2: ";
	cin.getline(expr2,100);

	cout<<"Enter Condition 2: ";
	cin.getline(cond2,50);

	cout<<"Enter x: ";
	cin>>x;

	char expr[100];
	char cond[50];

	if(condition(cond1, x)){
		strcpy1(expr, expr1);
		strcpy1(cond, cond1);
	}
	else if(condition(cond2, x)){
		strcpy1(expr, expr2);
		strcpy1(cond, cond2);
	}
	else{
		cout<<"No condition satisfied"<<endl;
		return 0;
	}

	char tokens[MAX][20];
	char post[MAX][20];

	int n = makeTokens(expr, tokens);
	int p = 0;

	postfix(tokens, n, post, p);

	double answer = calculate(post, p, x);

	cout << endl;
	cout <<"Condition: "<< cond <<endl;
	cout <<"Expression: "<< expr <<endl;

	cout<<"Postfix: ";

	for(int i=0;i<p;i++) cout<<post[i]<<" ";

	cout<<endl;
	cout<<"f("<<x<<") = "<<answer<<endl;

}
