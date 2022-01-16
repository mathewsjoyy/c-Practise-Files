#include <iostream>

class Example {
public:
    Example(const int& i) : i(i) {};
    int getInt() { return i;}
private:
    int i;
    // Friend function
    friend int getMemberInt(Example&);
};

// Make this a friend function so it can access private members
int getMemberInt(Example &in) {
    return in.i;
}


int main(){

    Example e(5);
    std::cout << getMemberInt(e) << std::endl;

    return 0;
};