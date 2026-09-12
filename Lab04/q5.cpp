#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int data) : data(data), next(nullptr){}
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
		
		void reverse(Node* start, Node* end){
			Node* previous = nullptr;
			Node* current = start;
			Node* nextNode;
			
			while(current != end){
				nextNode = current->next;
				current->next = previous;
				previous = current;
				current = nextNode;
			}
			
			start->next = end;
		}
		
		void K(int k){
			if(head == nullptr || k <= 1)
				return;
			
			Node* current = head;
			Node* previousGroupEnd = nullptr;
			
			while(current != nullptr){
				
				Node* temp = current;
				int count = 0;
				
				while(temp != nullptr && count < k){
					temp = temp->next;
					count++;
				}
				
				if(count < k)
					break;
				
				Node* groupStart = current;
				Node* previous = nullptr;
				Node* nextNode;
				
				for(int i = 0; i < k; i++){
					nextNode = current->next;
					current->next = previous;
					previous = current;
					current = nextNode;
				}
				
				if(previousGroupEnd == nullptr){
					head = previous;
				}
				else{
					previousGroupEnd->next = previous;
				}
				
				previousGroupEnd = groupStart;
			}
		}
};

int main(){
	
	singly list;
	int n;
	int data;
	int k;
	
	cout<<"Enter number of elements: ";
	cin>>n;
	
	cout<<"Enter elements: ";
	
	for(int i=0;i<n;i++){
		cin>>data;
		list.insertNode(data);
	}
	
	cout<<"Enter K: ";
	cin>>k;
	
	cout<<"Original List: ";
	list.display();
	
	list.K(k);
	
	cout<<"After reversing in groups: ";
	list.display();

}
