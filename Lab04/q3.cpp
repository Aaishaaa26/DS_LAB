#include <iostream>
using namespace std;

const int MAX = 50;

enum ListType{
	SINGLY,
	DOUBLY,
	CIRCULAR,
	DOUBLY_CIRCULAR
};

string typeName(ListType type){
	if(type == SINGLY)
		return "Singly";
	if(type == DOUBLY)
		return "Doubly";
	if(type == CIRCULAR)
		return "Circular";
	return "Doubly Circular";
}

bool circularType(ListType type){
	return type == CIRCULAR || type == DOUBLY_CIRCULAR;
}
bool doublyType(ListType type){
	return type == DOUBLY || type == DOUBLY_CIRCULAR;
}

class Node{
	public:
		int data;
		Node* next;
		Node* prev;		
		Node(int data): data(data), next(nullptr), prev(nullptr){}
};

void insertNode(Node*& head, ListType type, int data){
	Node* newNode = new Node(data);	
	if(head == nullptr){
		head = newNode;		
		if(circularType(type)){
			head->next = head;
			if(type == DOUBLY_CIRCULAR) head->prev = head;
		}		
		return;
	}	
	Node* temp = head;
	if(circularType(type)){
		while(temp->next != head){
			temp = temp->next;
		}
	}
	else{
		while(temp->next != nullptr){
			temp = temp->next;
		}
	}	
	temp->next = newNode;
		
	if(doublyType(type))
		newNode->prev = temp;
	
	if(circularType(type)){
		newNode->next = head;	
		if(type == DOUBLY_CIRCULAR) head->prev = newNode;
	}
}

int getLength(Node* head, ListType type){
	if(head == nullptr)	return 0;	
	int count = 0;
	Node* temp = head;
	if(circularType(type)){
		do{
			count++;
			temp = temp->next;
		}while(temp != head);
	}
	else{
		while(temp != nullptr){
			count++;
			temp = temp->next;
		}
	}	
	return count;
}

Node* findTail(Node* head, ListType type){
	if(head == nullptr)	return nullptr;
	
	Node* temp = head;	
	if(circularType(type)){
		while(temp->next != head){
			temp = temp->next;
		}
	}
	else{
		while(temp->next != nullptr){
			temp = temp->next;
		}
	}	
	return temp;
}

bool detectCycle(Node* head){
	if(head == nullptr)
		return false;	
	Node* slow = head;
	Node* fast = head;
	
	while(fast != nullptr && fast->next != nullptr){
		slow = slow->next;
		fast = fast->next->next;		
		if(slow == fast) return true;
	}
	
	return false;
}

void bubbleSort(Node* head, int n){
	if(head == nullptr || n <= 1) return;
	
	for(int i = 0; i < n - 1; i++){
		Node* temp = head;	
		for(int j = 0; j < n - 1 - i; j++){
			
			if(temp->data > temp->next->data){
				int x = temp->data;
				temp->data = temp->next->data;
				temp->next->data = x;
			}			
			temp = temp->next;
		}
	}
}

void display(Node* head, ListType type){
	if(head == nullptr){
		cout<<"Empty";
		return;
	}	
	int n = getLength(head,type);
	Node* temp = head;
	
	for(int i = 0; i < n; i++){
		cout<<temp->data;	
		if(i < n - 1) cout<<"->";		
		temp = temp->next;
	}	
	if(circularType(type))
		cout<<"->("<<head->data<<")";
}

int main(){
	
	int n;	
	cout<<"Enter total number of linked lists: ";
	cin>>n;
	
	if(n < 12){
		cout<<"Minimum 12 lists are required."<<endl;
		return 0;
	}
	
	if(n > MAX){
		cout<<"Maximum "<<MAX<<" lists are allowed."<<endl;
		return 0;
	}	
	ListType types[MAX];
	int typeCount[4] = {0,0,0,0};
	
	cout<<endl;
	cout<<"0 = Singly"<<endl;
	cout<<"1 = Doubly"<<endl;
	cout<<"2 = Circular"<<endl;
	cout<<"3 = Doubly Circular"<<endl;
	cout<<endl;
	
	for(int i = 0; i < n; i++){		
		int type;		
		while(true){
			cout<<"Enter type for list "<<i + 1<<": ";
			cin>>type;			
			if(type < 0 || type > 3){
				cout<<"Invalid type."<<endl;
				continue;
			}		
			if(i > 0 && types[i - 1] == (ListType)type){
				cout<<"Two consecutive lists cannot have the same type."<<endl;
				continue;
			}			
			break;
		}		
		types[i] = (ListType)type;
		typeCount[type]++;
	}
	
	for(int i = 0; i < 4; i++){
		if(typeCount[i] < 3){
			cout<<endl;
			cout<<typeName((ListType)i);
			cout<<" must appear at least 3 times."<<endl;
			return 0;
		}
	}
	
	Node* heads[MAX];
	int sizes[MAX];
	bool cyclic[MAX];
	bool used[MAX];	
	for(int i = 0; i < n; i++){
		heads[i] = nullptr;
		sizes[i] = 0;
		cyclic[i] = false;
		used[i] = false;
	}	
	for(int i = 0; i < n; i++){		
		int m;
		
		cout<<endl;
		cout<<"List "<<i + 1<<" ("<<typeName(types[i])<<")"<<endl;
		cout<<"Enter number of elements: ";
		cin>>m;		
		cout<<"Enter elements: ";		
		for(int j = 0; j < m; j++){
			int data;
			cin>>data;
			insertNode(heads[i],types[i],data);
		}		
		sizes[i] = getLength(heads[i],types[i]);
	}
	cout<<"\n\nSOrt: "<<endl;	
	for(int i = 0; i < n; i++){
		
		bubbleSort(heads[i],sizes[i]);
		
		cout<<"List "<<i + 1<<" ("<<typeName(types[i])<<"): ";
		display(heads[i],types[i]);
		cout<<endl;
	}
	
	cout<<"\nCycle Detection:"<<endl;	
	int cycleCount = 0;	
	for(int i = 0; i < n; i++){	
		cyclic[i] = detectCycle(heads[i]);	
		cout<<"List "<<i + 1<<": ";
		
		if(cyclic[i]){
			cout<<"Cycle detected"<<endl;
			cycleCount++;
		}
		else{
			cout<<"No cycle"<<endl;
		}
	}
	
	cout<<endl;
	cout<<"Cyclic Groups"<<endl;	
	int groupStart[MAX];
	int groupEnd[MAX];
	int groupCount = 0;	
	for(int i = 0; i < n; i++){		
		if(cyclic[i] && !used[i]){		
			groupStart[groupCount] = i;			
			int j = i;			
			while(j < n){				
				used[j] = true;				
				if(j != i && cyclic[j]){
					break;
				}				
				j++;
			}			
			groupEnd[groupCount] = j;			
			cout<<"Group "<<groupCount + 1<<": ";			
			for(int k = i; k < j; k++){
				cout<<"List "<<k + 1;	
				if(k < j - 1) cout<<" -> ";
			}			
			cout<<endl;			
			groupCount++;
		}
	}
	cout<<"\nMerging Cyclic Groups"<<endl;
	
	Node* mergedHeads[MAX];
	int mergedSizes[MAX];	
	for(int g = 0; g < groupCount; g++){		
		int start = groupStart[g];
		int end = groupEnd[g];		
		mergedHeads[g] = heads[start];
		mergedSizes[g] = 0;	
			
		for(int i = start; i < end; i++){
			mergedSizes[g] += sizes[i];
		}
		
		for(int i = start; i < end; i++){		
			Node* tail = findTail(heads[i],types[i]);			
			if(circularType(types[i])){
				tail->next = nullptr;
			}			
			if(i < end - 1){
				tail->next = heads[i + 1];				
				if(doublyType(types[i + 1])){
					heads[i + 1]->prev = tail;
				}
			}
		}		
		Node* tail = findTail(mergedHeads[g],SINGLY);
		tail->next = mergedHeads[g];		
		cout<<"Group "<<g + 1<<" merged: ";
		
		for(int i = start; i < end; i++){
			cout<<"List "<<i + 1;
			
			if(i < end - 1)
				cout<<" + ";
		}	
		cout<<endl;
	}
	
	cout<<"\nBubble Sort Compatible Parts"<<endl;
	
	for(int g = 0; g < groupCount; g++){		
		int start = groupStart[g];
		int end = groupEnd[g];		
		int last = end - 1;		
		while(last > start){
			if(types[last - 1] == SINGLY || types[last - 1] == CIRCULAR){
				last--;
			}
			else{
				break;
			}
		}
		
		if(last < end){			
			int total = 0;			
			for(int i = last; i < end; i++){
				total += sizes[i];
			}			
			Node* temp = heads[last];			
			bubbleSort(temp,total);			
			cout<<"Group "<<g + 1;
			cout<<" Bubble Sort applied to lists ";			
			for(int i = last; i < end; i++){
				cout<<i + 1<<" ";
			}			
			cout<<endl;
		}
		else{
			cout<<"Group "<<g + 1;
			cout<<" has no compatible part."<<endl;
		}
	}	
	cout<<"FINALLLYYYY:"<<endl;
	cout<<"Number of cycles: "<<cycleCount<<endl;
	cout<<"Number of cyclic groups: "<<groupCount<<endl;	
	for(int g = 0; g < groupCount; g++){		
		cout<<"Merged Cyclic List "<<g + 1<<": ";	
		Node* temp = mergedHeads[g];		
		for(int i = 0; i < mergedSizes[g]; i++){
			cout<<temp->data;			
			if(i < mergedSizes[g] - 1)	cout<<"->";		
			temp = temp->next;
		}		
		cout<<"->("<<mergedHeads[g]->data<<")"<<endl;
	}

	cout<<"Independent Lists:"<<endl;	
	for(int i = 0; i < n; i++){
		
		if(!used[i]){
			cout<<"List "<<i + 1<<" ("<<typeName(types[i])<<"): ";
			display(heads[i],types[i]);
			cout<<endl;
		}
	}
}
