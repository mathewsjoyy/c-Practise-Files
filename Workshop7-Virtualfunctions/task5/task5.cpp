#include <iostream>


class A {
private:
std::string unique1;

public:
    virtual void print() {
        std::cout << "A" << std::endl;
    }

    std::string getValue() const {
        return unique1;
    }

    A() {}
    A(std::string unique1) : unique1(unique1) {}

};

class B : public A {
private:
std::string unique2;

public:
    void print() override {
        std::cout << "B" << std::endl;
    }

    std::string getValue() const {
        return unique2;
    }

    B() {}
    B(std::string unique2) : unique2(unique2) {}
};

class C : public B {
private:
std::string unique3;

public:
    void print() override {
        std::cout << "C" << std::endl;
    }

    std::string getValue() const {
        return unique3;
    }

    C(std::string unique3) : unique3(unique3) {}
};


void doStuff (const A _in) {
    std::cout << "Returned value: "<< _in.getValue() << std::endl;
}

int main () {

    A a = A("42");
    B b = B("20.21");
    C c = C("test");
    A *pB = &b;
    A *pC = &c;
    a.print();
    pB->print();
    pC->print();
    
    //--put code for task 6main() here
    doStuff(a);
    doStuff(b);
    doStuff(c);

    return 0;
}