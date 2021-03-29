#include <bits/stdc++.h>
using namespace std;

class Student {
	
	private:
		string pass = "1234";
		
	protected:
		string pass2 = "4567";
		
	public:
		int id;
		string s;
		
	Student(){
		cout<<"I am Base class"<<endl;
		id = 35;
		s = "Abhishek";
	}
	
	Student(int x){
		cout<<"happy"<<endl;
	}
	
	string get_pri(){
		return pass;
	}
	friend void check(Student);
	friend class A;
};

void check(Student s1){
	cout<<"Hi i am friend fucntion"<<endl;
}

class A {
	public:
	A(Student s1){
		cout<<"Hi I am A friend class of Student"<<endl;
		cout<<s1.pass<<" "<<s1.pass2<<endl;
	}
};

class details:public Student {
	
	public:
	
		details(){
			Student(5);
			cout<<"SAD"<<endl;
		}
		
		details(int x){
			cout<<"I am derived class "<<x<<endl;
		}
		
		void get(){
			cout<<s<<" "<<id<<endl;
			cout<<get_pri()<<endl;
			cout<<pass2<<endl;
		}
	friend void check2(details);
};

void check2(details d1){
	d1.get();
}

enum week { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };  

int main()
{	
	details d1;
	check2(d1);
    return 0;
}
























