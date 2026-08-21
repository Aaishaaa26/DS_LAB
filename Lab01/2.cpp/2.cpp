#include <iostream>
using namespace std;

class Employee{
	string name, depart;
	float salary;
	
	public:
		Employee(string n, string d, float s): name(n), depart(d), salary(s){}
		Employee( const Employee& e){
			name = e.name;
			depart = e.depart;
			salary = e.salary;
		}
		void details(){cout<<"Name: " << name << "\nDepartment: " << depart << "\nSalary: " << salary << endl << endl;}	
		void changeSalary(float s){
			salary+=s;
		}	
};
int main(){
        Employee emp1("Aaisha", "AI" , 0.0);
        Employee emp2(emp1);
        emp2.changeSalary(5.0);
        emp2.details();
        emp1.details();
}

