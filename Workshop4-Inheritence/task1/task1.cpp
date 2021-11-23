// CMP2801M Advanced Programming
// Workshop Week6
#include <iostream>
#include "reg.h"

void RegisterCall(Registration& myCode){
	std::cout << "\nRegistration:\n";
	if (myCode.input())
	{
		std::cout << "The input code is " << myCode.getCode() << "\n";
		std::cout << "The system has been updated: ";
		myCode.output();
	}
	else
	{
		std::cout << "Your input code " << myCode.getCode() << " doesn't match the access code\n";
		std::cout << "Registration unsuccessful." << std::endl;
	}
}

int main()
{
	Registration myCode(12345);
	Registration myCode2(54321);

	RegisterCall(myCode);
	RegisterCall(myCode2);

	return 0;
}
