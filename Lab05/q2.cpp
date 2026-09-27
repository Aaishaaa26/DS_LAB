#include <iostream>
using namespace std;

class Stack{
    int arr[20];
    int top;
	public:
	    Stack():top(-1){}
	    void push(int val){
	        top++;
	        arr[top] = val;
	    }
	    int get(int index){return arr[index];}
	    int size(){return top + 1;}
};

class Node{
	public:
	    int data;
	    Node* next;
	    Node(int val): data(val), next(nullptr){}
};

class ThirdStack{
    Node* top;
    Node* bottom;

	public:
	    ThirdStack(): top(nullptr), bottom(nullptr){}
	    void push(int val){
	        Node* newNode = new Node(val);
	        if(bottom == nullptr){
	            bottom = newNode;
	            top = newNode;
	        }
	        else{
	            top->next = newNode;
	            top = newNode;
	        }
	    }
	    void sort(){
	        for(Node* i = bottom; i != nullptr; i = i->next){
	            for(Node* j = i->next; j != nullptr; j = j->next){
	                if(i->data > j->data){
	                    int temp = i->data;
	                    i->data = j->data;
	                    j->data = temp;
	                }
	            }
	        }
	    }
	    void display(){
	        Node* temp = bottom;
	        while(temp != nullptr){
	            cout << temp->data << " ";
	            temp = temp->next;
	        }
	        cout << endl;
	    }
	    Node* getBottom(){
	        return bottom;
	    }
};

class CircularQueue{
    Node* rear;
	public:
	    CircularQueue() : rear(nullptr){}
	    void enqueue(int val){
	        Node* newNode = new Node(val);
	        if(rear == nullptr){
	            rear = newNode;
	            rear->next = rear;
	        }
	        else{
	            newNode->next = rear->next;
	            rear->next = newNode;
	            rear = newNode;
	        }
	    }
	    void display(){
	        if(rear == nullptr) return;	
	        Node* temp = rear->next;
	        do{
	            cout << temp->data << " ";
	            temp = temp->next;
	        }while(temp != rear->next);
	
	        cout << endl;
	    }
};

int main(){
    Stack s1, s2;
    ThirdStack s3;

    int n1, n2, value;

    cout << "Enter number of elements in Stack 1: ";
    cin >> n1;

    cout << "Enter Stack 1 elements: ";
    for(int i = 0; i < n1; i++){
        cin >> value;
        s1.push(value);
    }
    cout << "Enter number of elements in Stack 2: ";
    cin >> n2;

    cout << "Enter Stack 2 elements: ";
    for(int i = 0; i < n2; i++){
        cin >> value;
        s2.push(value);
    }
    int smaller;

    if(n1 < n2) smaller = n1;
    else smaller = n2;

    for(int i = 0; i < smaller; i++){
        s3.push(s1.get(i));
        s3.push(s2.get(i));
    }
    if(n1 > n2){
        for(int i = smaller; i < n1; i++) s3.push(s1.get(i));
    }
    else{
        for(int i = smaller; i < n2; i++) s3.push(s2.get(i));
    }
    cout << "\nThird Stack: ";
    s3.display();
    s3.sort();
	cout << "Sorted Stack: ";
    s3.display();

    CircularQueue q;
    Node* temp = s3.getBottom();
    while(temp != NULL){
        q.enqueue(temp->data);
        temp = temp->next;
    }

    cout << "Circular Queue: ";
    q.display();
}
