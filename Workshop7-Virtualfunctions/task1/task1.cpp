#include <iostream>

class A {
private:
    int value; // must stay private
public:
    A(int value) : value(value) {}
    void print() {
        std::cout << "My value is: " << value << std::endl;
    }

    friend A add(A a1, A a2);

    A operator+(A a2) {
        return add(*this, a2);
    }

    A operator++() {
        value++;
        return *this;
    }
};

A add(A a1, A a2) {
    return A(a1.value + a2.value);
}

int main(){
    A a1(2);
    A a2(3);

    A a3 = add(a1, a2);
    
    a3.print();

    A a4 = a1 + a2 + a3;
    a4.print();

    A a5 = ++a4;
    a4.print();
    a5.print();

    return 0;
}

