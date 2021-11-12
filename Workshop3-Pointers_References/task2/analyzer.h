# pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <algorithm>

class Analyzer {
    private:
        // Class fields
        std::string filename;
        int numberOfWords = 0, numberOfSentences = 0;
        std::unordered_map<std::string, int> wordList;
        char buf[1024];

        // Private functions
        void printSummary() const;
        void updateSentenceCount(const std::string& word);
        void removePunc(std::string& word) const;
        void addWord(const std::string& word);

    public:
        // Constructor which just sets filename
        Analyzer(const std::string& filename) : filename(filename) {numberOfSentences++;};

        void analyseDocument(); // Main analyze function
        std::string getFileName() const { return filename; }; // Getter to return filename
        void changeFileName(const std::string& filename) { this->filename = filename; } // Option to change filename

};
