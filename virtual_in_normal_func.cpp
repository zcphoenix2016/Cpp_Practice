#include <iostream>

class A
{
public:
    virtual ~A()
    {
    }

    virtual void display()
    {
        std::cout << "A::display()" << std::endl;
    }

};

class B : public A
{
public:
    virtual void display()
    {
        std::cout << "B::display()" << std::endl;
    }

    void func()
    {
        display();
    }
};

int main()
{
    /*
    A* pb = new B();
    pb->func();
    delete pb;
    */
    std::cout << "-------------------------" << std::endl;

    B* pa = static_cast<B*>(new A());
    pa->func();
    delete pa;
 
    return 0;
}
