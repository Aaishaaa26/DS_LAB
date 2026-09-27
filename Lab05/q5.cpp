#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX][10];
int top = -1;

void push(char op[]){
	top++;
	strcpy(stack[top], op);
}
char* pop(){return stack[top--];}
char* peek(){return stack[top];}

int precedence(char op[]){
	if(strcmp(op,"^") == 0) return 3;
	if(strcmp(op,"*") == 0 || strcmp(op,"/") == 0)return 2;
	if(strcmp(op,"+") == 0 || strcmp(op,"-") == 0)return 1;
	return 0;
}

int isOperator(char op[]){
	if(strcmp(op,"+") ==0 || strcmp(op,"-") == 0 || strcmp(op,"*") == 0 || strcmp(op,"/") == 0 ||strcmp(op,"^") == 0) return 1;
	return 0;
}

void infixToPostfix(char tokens[][20], int n, char postfix[][20], int *count){
	top= -1;
	*count = 0;

	for(int i = 0; i< n; i++){
		if(isOperator(tokens[i])){
			while(top!=-1 && precedence(peek()) >= precedence(tokens[i])){
				strcpy(postfix[*count], pop());
				(*count)++;
			}
			push(tokens[i]);
		}
		else{
			strcpy(postfix[*count], tokens[i]);
			(*count)++;
		}
	}

	while(top!= -1){
		strcpy(postfix[*count],pop());
		(*count)++;
	}
}

void infixToPrefix(char tokens[][20], int n, char prefix[][20], int *count){

	char reverse[MAX][20];
	char temp[MAX][20];

	for(int i = 0; i < n; i++){
		strcpy(reverse[i], tokens[n-1-i]);
	}
	top =-1;
	int t = 0;

	for(int i = 0; i< n; i++){
		if(isOperator(reverse[i])){
			while(top!=-1 && precedence(peek()) >precedence(reverse[i])){
				strcpy(temp[t], pop());
				t++;
			}
			push(reverse[i]);
		}
		else{
			strcpy(temp[t],reverse[i]);
			t++;
		}
	}
	while(top!=-1){
		strcpy(temp[t],pop());
		t++;
	}
	*count=t;
	for(int i = 0; i< t; i++){ strcpy(prefix[i], temp[t-1-i]);}
}

void display(char arr[][20],int n){
	for(int i = 0; i < n; i++){
		printf("%s", arr[i]);
		if(i!=n-1) printf(" ");
	}
	printf("\n");
}

int main(){

	int n;

	printf("Enter number of terms n: ");
	scanf("%d",&n);

	if(n <= 0){
		printf("Invalid number\n");
		return 0;
	}
	int terms[MAX];
	for(int i = 0; i < n; i++){
		terms[i] = 3*(i+1)-2;
	}

	char tokens[MAX][20];
	int tokenCount = 0;

	for(int i = 0; i < n; i++){
		sprintf(tokens[tokenCount],"%d", terms[i]);
		tokenCount++;
		if(i!= n-1){
			strcpy(tokens[tokenCount], "+");
			tokenCount++;
		}
	}

	printf("\nSeries: ");
	for(int i = 0; i < n; i++){
		printf("%d",terms[i]);
		if(i!=n-1) printf(" + ");
	}
	printf("\n");

	char postfix[MAX][20];
	int postCount;

	infixToPostfix(tokens, tokenCount, postfix, &postCount);

	char prefix[MAX][20];
	int preCount;

	infixToPrefix(tokens, tokenCount, prefix, &preCount);

	printf("Postfix: ");
	display(postfix, postCount);
	printf("Prefix: ");
	display(prefix, preCount);

	int sum = 0;
	for(int i = 0; i < n; i++){ sum = sum+terms[i];}
	printf("\nSum of series = %d\n", sum);
}
