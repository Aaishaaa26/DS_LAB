#include <iostream>
using namespace std;

class stack{
	int arr[10];
	int top;
	public:
		stack() : top(-1){}
		void push(int val){
			if(top == 9){
				cout<<"overflow\n";
				return;
			}
			top++;
			arr[top] = val;
		}
		void findMinMaxMid(){
			if(top == -1) return;
			int max = arr[0], min = arr[0], mid;
			for(int i = 0; i <= top; i++){
				if(max < arr[i])max = arr[i];
				if(min > arr[i])min = arr[i];
			}
			if((top + 1) % 2 != 0){
				mid = arr[top / 2];
				cout<<"max: "<<max<<", min: "<<min<<", mid: "<<mid<<endl;
			}
			else{
				int mid1 = arr[top / 2];
				int mid2 = arr[top / 2 + 1];
				cout<<"max: "<<max<<", min: "<<min;
				cout<<", middle: "<<mid1<<" and "<<mid2<<endl;
			}
		}
};
int main(){
	stack s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	s.findMinMaxMid();
}
