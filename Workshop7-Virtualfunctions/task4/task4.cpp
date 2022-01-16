#include <iostream>

class Employee
{
private:
    std::string name;
    double salary;
public:
    Employee(const std::string& name, const double& salary)
    {
        this->name = name;
        this->salary = salary;
    }
    virtual void print() const
    {
        std::cout << name << " earns " << salary << std::endl;
    }

    void changeSalary(const double& newSalary)
    {
        salary = newSalary;
    }

    double getSalary() const
    {
        return salary;
    }
};

class Manager : public Employee
{  
private:
    Employee* assigned = nullptr;
public:
    Manager(const std::string& name, const double& salary) : Employee(name, salary){};

    void assignEmployee(Employee &assigned)
    {
        this->assigned = &assigned;
    }

    void giveRaise(const double& percent)
    {   
        if (assigned != nullptr)
        {   
            double newSalary = assigned->getSalary() + assigned->getSalary();
            assigned->changeSalary(newSalary);
        }
    }
};


int main(){

    Employee cook = Employee("Jesse", 5000);
    cook.print(); // should print "Jesse earns 5000"

    Manager boss = Manager("Walter", 10000);
    boss.print(); // should print "Walter earns 10000"

    boss.assignEmployee(cook);
    boss.giveRaise(5000);
    cook.print(); // should print "Jesse earns 10000"

    return 0;
}