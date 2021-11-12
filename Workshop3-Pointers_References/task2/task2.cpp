#include <iostream>
#include "analyzer.h"
#include <memory>

int main(){
	std::string fileNames;
	std::cout << "> Enter file names to analyse separated by a space:\n ";

	// Get as many files as user wanted
	getline(std::cin, fileNames);

	// List of Analyzer objects using unique pointers
	// By using unique pointers it means that the Analyzer objects will be deleted automatically
	// when the last pointer to them is deleted / goes out of scope, so i dont need to dynamically allocate
	// memory for them with new and risk forgetting to call delete.
	// Negative of unique pointers is we cant copy them, so we cant pass them by value etc
	// However we can se shared pointers, which are pointers that can be copied, and pass them by value etc.
	// But in this scenario we dont shared as we dont want to copy the Analyzer objects, we want to use them
	std::vector<std::unique_ptr<Analyzer>> list;

	std::istringstream iss(fileNames);
	for (std::string s; iss >> s;){ // Get all file names user inputted
		list.push_back(std::make_unique<Analyzer>(s)); // Create new Analyzer object for each file using unique pointers
	}

	// Analyze all text files in list
	for(const auto& documents : list){
		std::cout << "\n" << "NOW ANALYZING ->"<< documents -> getFileName() <<"<- " << std::endl;
		documents -> analyseDocument();
		std::cout << std::endl;
	}

    return 0;
};