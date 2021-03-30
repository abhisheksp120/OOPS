#include <bits/stdc++.h>
using namespace std;

class Student {
	
	static int count;
	
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
	
	void f1(){
		cout<<"Hi you are using base class method f1"<<endl;
	}
	
	friend void check(Student);
	friend class A;
};

// Static variable
int Student::count = 0;

// Friend function of class Student
void check(Student s1){
	cout<<"Hi i am friend fucntion"<<endl;
}

// Friend class A of class Student
class A {
	public:
	A(){
		cout<<"Hi I am A friend class of Student"<<endl;
	}
	void f1(){
		cout<<"Hi I am f1 of class A"<<endl;
	}
};

// Single Inheritance
class details:public Student {
	
	public:
	
		details(int x){
			Student(5);
			cout<<"SAD"<<endl;
		}
		
		details(){
			cout<<"I am first derived class "<<endl;
		}
		void f2(){
			f1();
			cout<<"Hi you are using first derived class method f2"<<endl;
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

// Multilevel Inheritance
class more:public details{
	public:
	 more(){
		 cout<<"I am in second derived class"<<endl;
	 }
	 void f3(){
		 f2();
		cout<<"Hi you are using second dervied class method f3"<<endl;
	}
};

// Multiple Inheritance
class one: public Student, public A{
	
	public:
		one(){
			
			// handling ambiguity in function f1 using class resolution operator
			
			Student::f1();
			cout<<"Hi I am the construtor"<<endl;
		}
};

// Hierarchical Inheritance
class B:public Student {
	public:
		B(){
			cout<<"Hi you are in class B"<<endl;
		}
		void f1(){
			cout<<"HI f1 in class B"<<endl;
		}
};

class C:public Student {
	public:
		C(){
			cout<<"Hi you are in class C"<<endl;
		}
		void f1(){
			cout<<"Hi f1 in class C"<<endl;
		}
};

// Hybrid Inheritance
class D:public B,public C {
	public:
	D(){
		C::f1();
		B::f1();
		cout<<"Hi you are in class D and you are now using hybrid Inheritance"<<endl;
	}
};

enum week { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };  

int main()
{	
	D d1;
	
    return 0;
}
























