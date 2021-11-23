#pragma once
#include <iostream>

class Registration
{
public:
    Registration(const int& code) : accessCode(code){};

	bool input();
	void output();
	void setRecord(const bool& index);
	int getCode() const;		//Returns the input code
private:
	bool checkCode(); 	//to check the input matches the access code
	int accessCode, code;
	std::string attend;
};
