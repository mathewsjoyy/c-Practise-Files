#include "analyzer.h"

void Analyzer::analyseDocument(){
    std::ifstream myFile(filename);  // For reading only

    if (myFile.is_open()) { // Check if the stream is associated with a valid file
        while (!myFile.eof()) { // While not end of file
            myFile.getline(buf, 1024);

            std::stringstream ss(buf);

            while(ss >> buf){ // Splits by space
                numberOfWords++;
                std::string toString = buf;

                updateSentenceCount(toString);
                removePunc(toString);
                addWord(toString);
            }
        }
        myFile.close();
        printSummary(); // Display statistics
    }
    else{
        std::cout << "\nThis file is unavailable to analyse";
    }
    std::cout << "\n> PRESS ENTER TO CONTINUE/EXIT.";
    std::cin.ignore();
}


void Analyzer::removePunc(std::string& word) const {
    std::vector<char> punctuation = {'.',',','?','!',':',';'};

    if(std::find(punctuation.begin(), punctuation.end(), word[word.length() - 1]) != punctuation.end()) { //get rid of punctuation
        word.pop_back(); // get rid of the punctuation
    }
}

void Analyzer::printSummary() const {
	std::cout << "\n> Number of sentences is " << numberOfSentences << "\n";
	std::cout << "> Number of words is " << numberOfWords << "\n";

	for (const auto& pair : wordList) {
		std::cout << "-> " << pair.first << ": " << pair.second << "\n";
	}
}

void Analyzer::updateSentenceCount(const std::string& word){
    if (word[word.length() - 1] == '.') { // If we have a end of sentence
        numberOfSentences++; // Increment sentences once after every getline
    }
}

void Analyzer::addWord(const std::string& word){
    if (wordList.find(word) == wordList.end()) { // Haven't stored this word before
		wordList.insert({ word, 1});
    }
    else {
        wordList[word]++; // Increment the words count
    }
}