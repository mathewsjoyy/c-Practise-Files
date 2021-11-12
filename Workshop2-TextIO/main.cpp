#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "student.h"


void print_map(const std::map<std::string, int>& theMap)
{
	for (const auto& pair : theMap) {
		std::cout << "-> " << pair.first << ": " << pair.second << "\n";
	}
}

int main()
{
	// == NOT PART OF THE WORKSHOP BUT JUST A TEST FOR HEADER AND CPP CLASS FILES IN VSCODE ==
	Student JDWAI13("Barry", 18);
	Student* ptr = &JDWAI13;
	ptr -> printDetails();
	
	std::string end;
	std::getline(std::cin, end);
	// == WORKSHOP STARTS FROM HERE ==


	// EXCERSIZE 1
	//vector<unsigned> grade{ 100, 98, 15, 30, 25, 70, 82, 66, 78, 40 };
	//vector<unsigned> scores(11, 0);
	//array
	//unsigned grade []={ 100, 98, 15, 30, 25, 70, 82, 66, 78, 40 };
	//unsigned scores[11] = {};
	//for (vector<unsigned>::iterator i = grade.begin(); i != grade.end(); i++)
	//{
	//	++scores[*i / 10];
	//}
	//for (vector<unsigned>::iterator j = scores.begin(); j != scores.end(); j++)
	//	cout << *j << "";
	//cout << endl;

	//for (auto i : grade)
	//{
	// ++scores[i / 10];
	//}
	//string result;
	//for (auto j : scores)
	// cout << j << "";
	//cout << endl;

	// EXCERSIZE 2
	char buf[1024];
	char filename[17] = "inputs/input.txt";
	std::ifstream myFile(filename);  // For reading only

	int numberOfWords = 0, numberOfSentences = 0;
	std::map<std::string, int> wordList;
	std::vector<char> punctuation = {'.',',','?','!',':',';'};

	if (myFile.is_open()) { // Check if the stream is associated with a valid file
		numberOfSentences++; // Increment once at the start

		while (!myFile.eof()) { // While not end of file

			myFile.getline(buf, 1024);//Extracts characters from the stream as unformatted input and stores them into buf as a c-string
			//until either the extracted character is '\n', or 1024 characters have been written to buf .

			std::stringstream ss(buf); // Insert the string into a stream

			while (ss >> buf) { // splits by spaces
				numberOfWords++; // increment for every word
				std::string toString = buf;
				
				if (toString[toString.length() - 1] == '.') { // If we have a end of sentence
					numberOfSentences++; // Increment sentences once after every getline
				}

				if(std::find(punctuation.begin(), punctuation.end(), toString[toString.length() - 1]) != punctuation.end()) { //get rid of punctuation
					toString.pop_back(); // get rid of the punctuation
				}

				if (wordList.find(toString) == wordList.end()) { // Haven't stored this word before
					wordList.insert({ toString, 1});
				}
				else {
					wordList[toString]++; // Increment the words count
				}
			}
		}
		myFile.close();
	}

	std::cout << "Analysing File : " << filename << "\n";
	std::cout << "> Number of sentences is " << numberOfSentences << "\n";
	std::cout << "> Number of words is " << numberOfWords << "\n";
	print_map(wordList);

	return 0;
}