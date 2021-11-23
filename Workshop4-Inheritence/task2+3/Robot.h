# pragma once
#include <iostream>
#include <vector>

class Robot{
    private:
        int workUnit = 0;
        // A better way is to use a unique_ptr but for sake of this workshop we do a raw pointer 
        std::vector<int>* _history; // pointer to vector of ints (NOT a vector of int pointers)

    public:
        Robot(const std::string& name) : name(name){_history = new std::vector<int>();};
        Robot() : Robot("DEFAULT") {};

        Robot(const Robot& rhs) : // copy constructor
            workUnit(rhs.workUnit),
            _history(new std::vector<int>(*rhs._history)), // copy over the vector of ints
            name(rhs.name)
        {};

        Robot& operator=(const Robot& rhs) {        // copy assignment operator
            workUnit = rhs.workUnit;
            *_history = *rhs._history; // use vector's copy assignment operator
            name = rhs.name;
            return *this;
        };

        ~Robot() {                                  // destructor
            std::cout << name << ": Goodbye!\n";
            delete _history;
        };

        std::string whoAmI() const {return name;};
        void setName(const std::string& name){this->name = name;};
        void work();
        void printWork() const;
        std::vector<int>* getHistory() const { return _history; };

    protected:
        std::string name;        
};