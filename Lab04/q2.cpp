#include <iostream>
using namespace std;

class Node{
	public:
		int id;
		Node* next;
		Node* prev;
		Node(int id): id(id), next(nullptr), prev(nullptr){}
};

class circularTrain{
	Node * head;
	public:
		circularTrain(){head = nullptr;}
		void insert(int id){
			Node* newNode = new Node(id);
			if(head == nullptr){
				head= newNode;
				head->next = head;
				head->prev = head;
				return;
			}
			Node * prevHead = head->prev;
			newNode->next= head;
			newNode->prev = prevHead;
			head->prev = newNode;
			prevHead->next = newNode;
		}
		void display(){
			if(head== nullptr){
				cout<<"Empty list";
				return;
			}
			Node *temp = head;
			do{
				cout<<temp->id<<"->";
				temp = temp->next;
			}while(temp != head);
			cout<<"back to head"<<endl<<endl;
		}
		Node* search(int id){
			if (head == nullptr) return nullptr;
			Node *temp = head;
			do{
				if(temp->id ==id){
					return temp;
				}
				temp = temp->next;
			}while(temp!=head);
			return nullptr;
		}
		void moveRight(int id){
			Node* found = search(id);
			if(found == nullptr || found == head){
				return;
			}
			found->prev->next = found->next;
			found->next->prev = found->prev;
			
			Node* temp = head->next;
			temp->prev = found;
			head->next = found;
			found->prev = head;
			found->next = temp;
			display();
		}
		void moveLeft(int id){
			Node* found = search(id);
			if(found == nullptr || found == head){
				return;
			}
			found->prev->next = found->next;
			found->next->prev = found->prev;
			
			Node* temp = head->prev;
			temp->next = found;
			head->prev = found;
			found->next = head;
			found->prev = temp;
			display();
		}
		void detach(int id){
			Node* found = search(id);
			if(found == nullptr){
				return;
			}
			if(found->prev == found){
				delete found;
				head = nullptr;
				return;
			}
			found->next->prev = found->prev;
			found->prev->next = found->next;
			if(found == head) head= head->next;	
			delete found;
			display();
		}
		void moveHead(int id){
			Node* found = search(id);
			if(found == head || found == nullptr){
				return;
			}
			head = found;
			display();
		}
		void path(Node* tail, int direction){
			Node* temp = head;	
			cout<<"\npath: ";
			if(direction == 0){
				while(temp!=tail){
					cout<<temp->id<<"->";
					temp = temp->next;
				}	
			}
			else{
				while(temp!=tail){
					cout<<temp->id<<"->";
					temp = temp->prev;
				}
			}
			cout<<temp->id<<endl;
		}
		void shortSearch(int id){
			Node* found = search(id);
			if(found == nullptr){
				cout<<"coach not found"<<endl;
				return;
			}
			if(found == head){
				cout<<"First Node was head"<< endl;
				return;
			}
			Node *nextStep = head->next;
			Node *prevStep = head->prev;
			int count = 1;
			do{
				if(prevStep->id == id && nextStep->id == id){
					cout<<" Direction: Equal"<<endl;
					path(prevStep,1);
					cout<<"steps: "<<count<<endl;
					return;
				}
				if(prevStep->id == id){
					cout<<" Direction: previous"<<endl;
					path(prevStep, 1);
					cout <<"steps: " << count;
					return;
				}
				if(nextStep->id == id){
					cout<<"Direction: nexr"<<endl;
					path(nextStep,0);
					cout <<"steps: " << count;
					return;
				}	
				count++;
				nextStep = nextStep->next;
				prevStep = prevStep->prev;
			}while(nextStep!=prevStep);		
		}
};

int main(){
	circularTrain train;
	train.insert(10);
	train.insert(20);
	train.insert(30);
	train.insert(40);
	train.insert(50);
	
	cout<<"Initial List: ";
	train.display();
	
	cout<<"After R 40: ";
	train.moveRight(40);
	
	cout<<"After S 30: ";
	train.moveHead(30);
	
	cout<<"After D 20: ";
	train.detach(20);
	
	cout<<"After L 50: ";
	train.moveLeft(50);
	
	cout<<"F 10:"<<endl;
	train.shortSearch(10);
}
