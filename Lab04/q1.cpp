#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node* child;
		Node(int data) : data(data), next(nullptr), child(nullptr){}
};

void restructured(Node* head){
	Node * curr = head;
	while(curr != nullptr){
		if(curr->child != nullptr){
			Node* childHead = curr->child;
			restructured(childHead);
			Node * temp = childHead;
			while(temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = curr->next;
			curr->next = childHead;
			curr->child = nullptr;
		}		
	curr = curr->next;			
	}	
}

int main(){
Node* n10 = new Node(10);
	Node* n20 = new Node(20);
	Node* n30 = new Node(30);
	Node* n40 = new Node(40);
	Node* n50 = new Node(50);
	Node* n60 = new Node(60);
	Node* n70 = new Node(70);
	Node* n80 = new Node(80);
	Node* n90 = new Node(90);
	n10->next = n20;
	n20->next = n30;
	n30->next = n60;
	n60->next = n90;	
	n20->child = n40;
	n40->next = n80;
	n40->child = n70;
	n60->child = n50;	
	Node* head = n10;	
	restructured(head);
	Node* curr = head;
	
	while(curr != nullptr){
		cout << curr->data << "->";
		curr = curr->next;
	}	
	cout <<"BULL (haha)";
}
