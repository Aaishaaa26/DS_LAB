#include <iostream>
using namespace std;

class Book{
	string title, author;
	int copies;
	
	public:
		Book(){
        	title = "";
			author = "";
			copies = 0;	
 		}
 		
 		Book(string t, string a, int c) : title(t), author(a), copies(c){}
 		
 		void details(){
 			cout << "Title: " << title <<"\nAuthor: " << author << "\nCopies: " << copies << endl<< endl;
		 }
		 
		 Book(const Book& b){
		 	title = b.title;
		 	author = b.author;
		 	copies = b.copies;
		 }
		 
		 void borrowBook(){
		 	--copies;
		 }
};

int main(){
	Book book1;
	book1.details();
	
	Book book2("OOP", "Me", 10);
	Book book3(book2);
	book3.borrowBook();
	book3.borrowBook();
	book3.borrowBook();
	book3.details();
	book2.details();
	}
