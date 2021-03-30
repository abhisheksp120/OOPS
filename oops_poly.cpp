#include <bits/stdc++.h>
using namespace std;

// Ambiguity in function overloading 

// Type Conversion
void fun(int x){
	cout<<x*x<<endl;
} 

void fun(float x){ 	 // Replace float with double to fix the ambiguity as floating constant are treated as double
	cout<<x*x<<endl;
}

// default arguments
void cal(int x){
	cout<<2*x<<endl;
}
void cal(int x, int y = 10){ // this function can be called as cal(12) or cal(12, 14) whcih is causing ambiguity
	cout<<x+y<<endl;
}

// Pass by reference
void doit(int x){		// one function with int as argument other with reference parameter as an argument
	cout<<x*2<<endl;
}
void doit(int &b){
	cout<<b*2<<endl;
}

// Operator Overloading

class Student{
	public:
		int num;
		
	public:    
       Student(int x){
			num = x;
	   }
    void operator +(Student); 	
    // overload ++ when used as prefix
    void operator ++(int){
		num++;
	}
    void get(){
		cout<<num<<endl;
	}
};

class complex1 {
	public:
		int real, img;
		complex1() : real(0), img(0) {}

	complex1 operator +(const complex1& c2){  // & used to giving the reference to
		complex1 c3;						// the obj c2 while const prevent the
											// operator function form modifying the object
		c3.real = real + c2.real;
		c3.img = img + c2.img;
		return c3;
	}
};

class A {
	public:
		A(){
			cout<<"Hi I am Base class"<<endl;
		}
	// pure virtual function
	// Can't have its own object
	// such class are called abstract class
	
	virtual void get() = 0;
};

class temp:public A {
	public:
		int id = 10;
	// override identifier is used to check for
	// error while define function which will
	// override the base class function
	void get() override{
		
		// Using scope resolution operator to call
		// the base class get function which get overridden
		//complex1::get();
		
		cout<<"Hi I am derived class"<<endl;
	}
};
int main()
{	
	/*fun(2);
	fun(1.2);
	
	cal(12);
	
	int a = 13;
	doit(13);
	*/
	//complex1 c1;
	
	A *a;
	temp t1;
	
	a = &t1;
	a->get();
    return 0;
}
























