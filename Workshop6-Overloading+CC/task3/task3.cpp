#include <iostream>

// Should be done in header file, but cba.
class A {
private:
    std::string name;

public:
    A(const std::string& name) : name(name) {};

    void setName(std::string name) {
        this->name = name;
    }

    void printName() const {
        std::cout << name << std::endl;
    }

    std::string getName() const {
        return name;
    }

    // Copy constructor
    A(const A& other) : name(other.getName()) {};
};


int main(){

    A *a1= new A("a");
    a1->setName("IamA");

    //Cant dothis as a pointer needs a address to be passed, not a value/object
    // A *a2= *a1;

    // So we need to call the new word (create new address space) to create a new object
    // and uses copy constructor to copy the values
    A *a2 = new A(*a1);

    delete a1;
    a2 -> printName();

    delete a2;
    return 0;

};