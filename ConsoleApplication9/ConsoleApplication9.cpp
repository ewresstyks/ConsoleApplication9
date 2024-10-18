#include<iostream>
using namespace std;
class Student {
	char* name;
	int age;
public:
	Student();
	Student(const char* name, int age);
	~Student();
	Student(const Student& obj2);
	void Print();
	void Input();
};

Student::Student()
{
	name = nullptr;
	age = 0;
}

Student::Student(const char* _name, int _age)
{
	age = _age;
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}

Student::~Student()
{
	cout << "DESTRUCTOR" << endl;
	delete[] name;
}

Student::Student(const Student& obj2)
{
	age = obj2.age;
	if (name != nullptr) {
		delete[]name;
	}
	name = new char[strlen(obj2.name) + 1];
	strcpy_s(name, strlen(obj2.name) + 1, obj2.name);
	cout << "Copy const" << endl;
}

void Student::Print()
{
	cout << "Name -- " << name << endl << "Age -- " << age << endl;
}

void Student::Input()
{
	char buff[100];
	cout << "Write your name -- ";
	cin >> buff;
	cout << "Write your age -- ";
	cin >> age;
	if (name != nullptr) {
		delete[] name;
	}
	name = new char[strlen(buff) + 1];
	strcpy_s(name, strlen(buff) + 1, buff);
}


int main()
{
	Student a;
	a.Input();
	a.Print();
	Student b(a);
	b.Print();
}