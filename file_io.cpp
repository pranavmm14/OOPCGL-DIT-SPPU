#include<iostream>
#include<fstream>
#include<string>
using namespace std; 

class Employee{
	public:
		string name;
		float salary;
		int age;
		char sex;
		void accept();
		void display();

};

void Employee::accept(){
	cout << "Enter Name: ";
	cin.ignore();
	getline(cin,name);
	cout << "Age: ";
	cin >> age;
	cout << "Sex(M/F): ";
	cin>>sex;
	cout << "Salary: ";
	cin>>salary;
}

void Employee::display(){
	cout << "\nName: " <<name<<endl;
	cout << "Age: " << age<<endl;
	cout << "Sex: " << sex<<endl;	
	cout << "Salary: " << salary<<endl;
}


int main()
{
	fstream f;
	int num;
	string sentence;
	cout << "Enter no. of Employee: ";
	cin >> num;	
	Employee e1[num],e2[num];

	f.open("test.txt",ios::out);
	//sentence="My name is Pranav.\nThis is OOP test.";
	//f << sentence <<endl;
		
	for(int i=0;i<num;i++){
	       e1[i].accept();
	       //f << e[i] <<endl;
	       f.write((char*)&e1[i],sizeof(e1[i]));
	}

	for(int i=0;i<num;i++) e1[i].display();
	f.close();

	f.open("test.txt",ios::in);
	for(int i=0;i<num;i++){
	       f.read((char*)&e2[i],sizeof e2[i]);
	}

	f.close();
	for(int i=0;i<num;i++) e2[i].display();
	
	return 0;
}
