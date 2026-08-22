#include <iostream>
#include <string>
using namespace std;

class PlayList{
	string* tracks;
	int size;
	
	public:
		PlayList(string list[], int size){
			this->size = size;
			tracks = new string[size];
			for(int i = 0; i < size; i++){
				tracks[i] = list[i];
			}
		}
		
		PlayList(const PlayList& p){ //copy
			size = p.size;
			tracks = new string[size];
			
			for(int i = 0; i < size; i++){
				tracks[i] = p.tracks[i];
			}
		}
		
		PlayList& operator=(const PlayList& p){ //Assignment
			delete [] tracks;
			size = p.size;
			tracks = new string[size];
			
			for(int i = 0; i < size; i++){
				tracks[i] = p.tracks[i];
			}
			return *this;
		}
		 void display(){
		 	cout<< "List: \n";
		 	for (int i = 0; i < size; i++){
		 		cout << tracks[i] << endl;
			 }
			 cout << endl;
		 }
		 
		 void changeTrack(int index, string title){
		 	if(index >= size || index < 0){
		 		return;
			 }
			 tracks[index] = title;	 
		 }
         ~PlayList(){
             delete[] tracks;
         }
};

int main(){
	string list1[2] = {"Blinding Lights", "StarBoy" };
	string List2[3] = {"Hum", "Tum", "Woh"};
	string List3[1] = {"NOKIA"};
	
	PlayList p1(list1, 2);
	PlayList p2(p1);
	p2.changeTrack(1, "False Alarm");
	PlayList p3(List2, 3);
	PlayList p4(List3, 1);
	p3 = p4;
	p3.changeTrack(0, "Hum");
	p1.display();
	p2.display();
	p3.display();
	p4.display();
	
}
