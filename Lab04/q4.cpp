#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		
		Node(int data) : data(data), next(nullptr), prev(nullptr){}
};

class singly{
	Node* head;
	
	public:
		singly(): head(nullptr){}
		
		void insertNode(int data){
			Node* newNode = new Node(data);
			
			if(head == nullptr){
				head = newNode;
				return;
			}
			
			Node* temp = head;
			
			while(temp->next != nullptr){
				temp = temp->next;
			}
			
			temp->next = newNode;
		}
		
		void display(){
			Node* temp = head;
			
			while(temp != nullptr){
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			
			cout<<"NULL"<<endl;
		}
		
		void rotateRight(int k){
			if(head == nullptr || head->next == nullptr)
				return;
			
			int count = 1;
			Node* tail = head;
			
			while(tail->next != nullptr){
				tail = tail->next;
				count++;
			}
			
			k = k % count;
			
			if(k == 0)
				return;
			
			int steps = count - k - 1;
			Node* temp = head;
			
			for(int i=0;i<steps;i++){
				temp = temp->next;
			}
			
			Node* newHead = temp->next;
			temp->next = nullptr;
			tail->next = head;
			head = newHead;
		}
		
		void rotateLeft(int k){
			if(head == nullptr || head->next == nullptr)
				return;
			
			int count = 1;
			Node* tail = head;
			
			while(tail->next != nullptr){
				tail = tail->next;
				count++;
			}
			
			k = k % count;
			
			if(k == 0)
				return;
			
			Node* temp = head;
			
			for(int i=0;i<k-1;i++){
				temp = temp->next;
			}
			
			Node* newHead = temp->next;
			temp->next = nullptr;
			tail->next = head;
			head = newHead;
		}
};

class doubly{
	Node* head;
	Node* tail;
	
	public:
		doubly(): head(nullptr), tail(nullptr){}
		
		void insertNode(int data){
			Node* newNode = new Node(data);
			
			if(head == nullptr){
				head = newNode;
				tail = newNode;
				return;
			}
			
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		
		void display(){
			Node* temp = head;
			
			while(temp != nullptr){
				cout<<temp->data<<"<->";
				temp = temp->next;
			}
			
			cout<<"NULL"<<endl;
		}
		
		void rotateRight(int k){
			if(head == nullptr || head->next == nullptr)
				return;
			
			int count = 1;
			Node* temp = head;
			
			while(temp->next != nullptr){
				temp = temp->next;
				count++;
			}
			
			k = k % count;
			
			if(k == 0)
				return;
			
			for(int i=0;i<k;i++){
				Node* oldTail = tail;
				
				tail = tail->prev;
				tail->next = nullptr;
				
				oldTail->prev = nullptr;
				oldTail->next = head;
				head->prev = oldTail;
				head = oldTail;
			}
		}
		
		void rotateLeft(int k){
			if(head == nullptr || head->next == nullptr)
				return;
			
			int count = 1;
			Node* temp = head;
			
			while(temp->next != nullptr){
				temp = temp->next;
				count++;
			}
			
			k = k % count;
			
			if(k == 0)
				return;
			
			for(int i=0;i<k;i++){
				Node* oldHead = head;
				
				head = head->next;
				head->prev = nullptr;
				
				oldHead->next = nullptr;
				oldHead->prev = tail;
				tail->next = oldHead;
				tail = oldHead;
			}
		}
};

class circular{
	Node* head;
	Node* tail;
	
	public:
		circular(): head(nullptr), tail(nullptr){}
		
		void insertNode(int data){
			Node* newNode = new Node(data);
			
			if(head == nullptr){
				head = newNode;
				tail = newNode;
				tail->next = head;
				return;
			}
			
			tail->next = newNode;
			tail = newNode;
			tail->next = head;
		}
		
		void display(){
			if(head == nullptr)
				return;
			
			Node* temp = head;
			
			do{
				cout<<temp->data<<"->";
				temp = temp->next;
			}while(temp != head);
			
			cout<<"HEAD"<<endl;
		}
		
		void rotateRight(int k){
			if(head == nullptr || head->next == head)
				return;
			
			int count = 1;
			Node* temp = head;
			
			while(temp->next != head){
				temp = temp->next;
				count++;
			}
			
			k = k % count;
			
			if(k == 0)
				return;
			
			// This class never links 'prev', so we can't walk backwards
			// from tail. Rotating right by k is equivalent to rotating
			// left by (count - k), which only needs 'next'.
			k = count - k;
			
			for(int i=0;i<k;i++){
				head = head->next;
				tail = tail->next;
			}
		}
		
		void rotateLeft(int k){
			if(head == nullptr || head->next == head)
				return;
			
			int count = 1;
			Node* temp = head;
			
			while(temp->next != head){
				temp = temp->next;
				count++;
			}
			
			k = k % count;
			
			if(k == 0)
				return;
			
			for(int i=0;i<k;i++){
				head = head->next;
				tail = tail->next;
			}
		}
};

class doublyCircular{
	Node* head;
	Node* tail;
	
	public:
		doublyCircular(): head(nullptr), tail(nullptr){}
		
		void insertNode(int data){
			Node* newNode = new Node(data);
			
			if(head == nullptr){
				head = newNode;
				tail = newNode;
				
				head->next = head;
				head->prev = head;
				return;
			}
			
			newNode->prev = tail;
			newNode->next = head;
			tail->next = newNode;
			head->prev = newNode;
			tail = newNode;
		}
		
		void display(){
			if(head == nullptr)
				return;
			
			Node* temp = head;
			
			do{
				cout<<temp->data<<"<->";
				temp = temp->next;
			}while(temp != head);
			
			cout<<"HEAD"<<endl;
		}
		
		void rotateRight(int k){
			if(head == nullptr || head->next == head)
				return;
			
			int count = 1;
			Node* temp = head;
			
			while(temp->next != head){
				temp = temp->next;
				count++;
			}
			
			k = k % count;
			
			if(k == 0)
				return;
			
			for(int i=0;i<k;i++){
				head = tail;
				tail = tail->prev;
			}
		}
		
		void rotateLeft(int k){
			if(head == nullptr || head->next == head)
				return;
			
			int count = 1;
			Node* temp = head;
			
			while(temp->next != head){
				temp = temp->next;
				count++;
			}
			
			k = k % count;
			
			if(k == 0)
				return;
			
			for(int i=0;i<k;i++){
				head = head->next;
				tail = tail->next;
			}
		}
};

int main(){

	int choice;
	int n;
	int data;
	int k;
	char direction;
	
	cout<<"Select List Type:"<<endl;
	cout<<"1. Singly Linked List"<<endl;
	cout<<"2. Doubly Linked List"<<endl;
	cout<<"3. Circular Linked List"<<endl;
	cout<<"4. Doubly Circular Linked List"<<endl;
	
	cin>>choice;
	
	cout<<"Enter number of elements: ";
	cin>>n;
	
	if(choice == 1){
		
		singly list;
		
		for(int i=0;i<n;i++){
			cin>>data;
			list.insertNode(data);
		}
		
		cout<<"Enter K: ";
		cin>>k;
		
		cout<<"Enter Direction (L/R): ";
		cin>>direction;
		
		if(direction == 'R' || direction == 'r')
			list.rotateRight(k);
		else
			list.rotateLeft(k);
		
		cout<<"After Rotation: ";
		list.display();
	}
	
	else if(choice == 2){
		
		doubly list;
		
		for(int i=0;i<n;i++){
			cin>>data;
			list.insertNode(data);
		}
		
		cout<<"Enter K: ";
		cin>>k;
		
		cout<<"Enter Direction (L/R): ";
		cin>>direction;
		
		if(direction == 'R' || direction == 'r')
			list.rotateRight(k);
		else
			list.rotateLeft(k);
		
		cout<<"After Rotation: ";
		list.display();
	}
	
	else if(choice == 3){
		
		circular list;
		
		for(int i=0;i<n;i++){
			cin>>data;
			list.insertNode(data);
		}
		
		cout<<"Enter K: ";
		cin>>k;
		
		cout<<"Enter Direction (L/R): ";
		cin>>direction;
		
		if(direction == 'R' || direction == 'r')
			list.rotateRight(k);
		else
			list.rotateLeft(k);
		
		cout<<"After Rotation: ";
		list.display();
	}
	
	else if(choice == 4){
		
		doublyCircular list;
		
		for(int i=0;i<n;i++){
			cin>>data;
			list.insertNode(data);
		}
		
		cout<<"Enter K: ";
		cin>>k;
		
		cout<<"Enter Direction (L/R): ";
		cin>>direction;
		
		if(direction == 'R' || direction == 'r')
			list.rotateRight(k);
		else
			list.rotateLeft(k);
		
		cout<<"After Rotation: ";
		list.display();
	}
	
	else{
		cout<<"Invalid choice"<<endl;
	}
}
