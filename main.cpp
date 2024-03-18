#include <iostream>

class Base
{
private:
    /* data */
public:
    Base();
   virtual ~Base();
   //如果不将基类的析构函数声明为虚函数，则在上述示例中，当通过基类指针删除派生类对象时，只会调用基类的析构函数，而不会调用派生类的析构函数。
   //这可能导致派生类中的资源无法正确释放，造成内存泄漏或其他问题。因此，在面向对象设计中，经常将基类的析构函数声明为虚函数，以确保正确地析构派生类对象。
};

Base::Base()
{
      std::cout << "Base constructor" << std::endl;
}


 Base::~Base()//将析构函数声明为虚函数
{
      std::cout << "Base destructor" << std::endl;
}
class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived constructor" << std::endl;
    }

    ~Derived() {
        std::cout << "Derived destructor" << std::endl;
    }
};


int main(int, char**){
    Base * ptr=new Derived();//基类指针指向派生内对象
    delete ptr;//删除对象，会调用派生内的析构函数
    return 0;
}
