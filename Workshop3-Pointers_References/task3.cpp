#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

// MUCH MORE EFFICIENT TO JUST USE A MAP BUT for the sake of this workshop we do it an inefficent way
void getStatistics(vector<string> list,vector<string>& listOfDistinctWords,
                    vector<int>& listOfCounts){
    
    string currentSearchValue;
    int currentSearchCount = 0;

    for(int i = 0; i < list.size(); i++){
        currentSearchValue = list[i];
        if(currentSearchValue == "MATCHED"){ // If we get a matched carry onto next index
            continue;
        }
        listOfDistinctWords.push_back(currentSearchValue); // Add the search value to distinct vector

        for(int x = 0; x < list.size(); x++){
            if(list[x] == currentSearchValue){ // If we get a match increment count
                currentSearchCount++;
                list[x] = "MATCHED";
            }
        }
        listOfCounts.push_back(currentSearchCount);
        currentSearchCount = 0; // Reset count
    }
}

int searchWord(const string& searchedWord, vector<string> listOfDistinctWords,
 vector<int> listOfCounts){
    
    // returns iterator to search element if found
    auto it = find(listOfDistinctWords.begin(), listOfDistinctWords.end(), searchedWord);
 
    // If element was found
    if (it != listOfDistinctWords.end())
    {
        // calculating the index of search term
        int index = it - listOfDistinctWords.begin();
        return listOfCounts[index]; // We matched words to count in getStat func so we can just use same index
    }
    return 0; // Search term not found
}


int main(){
    string fileName = "input.txt";
    std::ifstream myFile(fileName);  // For reading only

    char buf[1024];
    vector<string> listOfWords, listOfDistinctWords;
    vector<int> listOfCounts;
    std::vector<char> punctuation = {'.',',','?','!',':',';'};

	if (myFile.is_open()) { // Check if the stream is associated with a valid file
		while (!myFile.eof()) { // While not end of file
            myFile.getline(buf, 1024);

            std::stringstream ss(buf);

            while(ss >> buf){ // Splits by space
                string toString = buf;
				if(find(punctuation.begin(), punctuation.end(), toString[toString.length() - 1]) != punctuation.end()) { //get rid of punctuation
					toString.pop_back(); // get rid of the punctuation
				}

                listOfWords.push_back(toString);
            }
        }
        myFile.close();
    }

    // Get the statistics using call by reference
    getStatistics(listOfWords, listOfDistinctWords, listOfCounts);

    // Search for a word by user input
    string userInput;
    cout << "> Enter a word to search for in:\n " << fileName;
    cin >> userInput;

    cout << searchWord(userInput, listOfDistinctWords, listOfCounts);

    return 0;
};