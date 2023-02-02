#include<iostream>
#include<string>
// using std::string;
// using std::cout;
// using std::endl;
// using std::bool;
using namespace std;


class base{
public:
    virtual void print(){
        cout << "this is base class print"<<endl;
    }
    void display(){
        cout<<"this is base class display"<<endl; 
    }
};
class derived: public base{
public:
       void print(){
        cout << "this is derived class print"<<endl;
    }
    void display(){
        cout<<"this is derived class display"<<endl; 
    }
};
int main(){
    base *basePtr;
    derived d;
    basePtr = &d;
    basePtr->print();
    basePtr->display();
}
#if 0
class Cmplx{
private:
     int real,imag;
public:
     Cmplx(int r,int i){
        real = r;
        imag = i;
     }
     //default constructor
     Cmplx(){
     }
     Cmplx operator + (Cmplx const &x){
        Cmplx y;
        y.real = real + x.real;
        y.imag = imag + x.imag;
        return y;
     } 
     void display(){
        cout << real << " +i " << imag << endl;
     }
};

int main(){
    Cmplx a(4,2);
    Cmplx b = Cmplx(6,8);
    Cmplx c = a + b;
    c.display();
}
#endif 
#if 0
class funcOverloading{
    public:
    void fun(){
        cout << "i have no arguments" << endl;
    }
    void fun(int x){
        cout << "i have a single intiger argument = " << x << endl; 
    }
    void fun(double d){
        cout << "i have a single double argument = " << d << endl;
    }
};

int main(){
    funcOverloading f;
    f.fun();
    f.fun(5);
    f.fun(3.14);
    return 0;
}
#endif //#if 0

#if 0
class A{
public:
    void Afunc(){
        cout << "inside class A" << endl;
    }
};
class B : public A{
public:
    void Bfunc(){
        cout <<"inside class B"<<endl;
    };
};
class C : public B{
public:
    void Cfunc(){
        cout << "inside class C"<< endl;
    }
}; 
int main(){
    C v;
    v.Afunc();
    v.Bfunc();
    v.Cfunc();
    return 0;
}

#endif 

#if 0
class A{
public:
    void func1(){
        cout <<"inherited from A"<<endl;
    }
protected:
    void func2(){
        cout <<"i am protected from A"<<endl;
    }
};
class B{
public:
    void func3(){
        cout <<"from calss B"<<endl;
    }
};
class C: public A, public B{
public:
    void func4(){
        func2();
    }
    
};

int main(){
    C v;
    v.func4();
    v.func1();
    v.func3();
    
return 0;
}
#endif //#if 0

#if 0
class student{
    int age ;   
public:
    string name;
    string course;
    string getName(){
        return name;
    } 
    void setName(string Name){
        name = Name;
    }
    //constructors
    //defualt constructors
    student(){
        cout <<"calling default constructor" << endl;
    }
    //parameterised constructor
    student(string Name,int Age,string Course){
        cout <<"calling parameterised constructor" << endl;
        age = Age;
        name = Name;
        course = Course;
    }
    //copy sonctructor
    student(student &S){
        cout <<"calling copy constructor" << endl;
        name = S.name;
        age = S.age;
        course = S.course;
    }
    //destructor
    ~student(){
        cout <<"destructor called" <<endl;
    }
    //operator overloading
    bool operator == (student &A){
        if(name == A.name && age == A.age && course == A.course){
            return true;
        }
        return false;
    }
    void printInfo(){
        cout<<"Name : "<<name << " Age : " << age << " Course : " << course << endl;
    }
};
int main(){
    student a("Naveen",30,"Embedded");
    student b("Disant",32,"DSP");
    a.printInfo();
    b.printInfo();
    student c = a;
    student d(b);
    if(c == a){
        cout << "matching" <<endl;
    }
    else{
        cout << "not matching" <<endl;
    }
    return 0;
}
#endif //#if 0