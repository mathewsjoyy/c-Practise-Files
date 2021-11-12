#include <iostream>
#include <vector>
#include <unordered_map>

int main(){
    std::vector<int> list = {1,4,2,6,4};

    // Using normal for loop
    std::cout << "Normal For Loop ";
    for(int x = 0; x < list.size(); x++ ){
        std::cout << list[x] << " ";
    }

    // Better more friendly loop
    std::cout << "Cleaner loop ";
    for(const int& num : list){
        std::cout << num << " ";
    }

    // With iterators
    std::cout << "Iterator ";
    for(std::vector<int>::iterator it = list.begin(); it != list.end(); it++){
        std::cout << *it << " "; // iterator are pointers so we need to dereference them
    }
    std::cout << std::endl;

    // How with normal vectors the second simple loop is best iterators are just more code for no reason
    // But we can use iterators when we want to loop through things that cant be done with indexes,
    // or you want to erase / maipulate an element but still be able to iterate through the rest
    // Or in datastructures like tress, we will use a unordered map as an example for iterator use case
    // as we cant simple loop through a map as we cant get key/values by index
    using ScoreMap = std::unordered_map<std::string, int>; // using can be used so we dont have to write out massive lines of code everytime

    ScoreMap map;
    map["Matt"] = 18;
    map["Boris"] = 105;

    // We use const_iterator as we dont need to change we just read the value
    for(ScoreMap::const_iterator it = map.begin(); it != map.end(); it++){
        // With this scenario (maps) we cant just derefence we have to use pointer arrow to get key and value
        // Remember iterator are basically pointers so we can use ->
        // As what would be dereference if we used *? key? value?
        std::cout << "Key " << it -> first; // Gets the key
        std::cout << " - Value " << it -> second << "\n"; //Gets the value 
    }
    std::cout << std::endl;

    // We can also use the simple for loop as well
    for(const auto& k : map){
        std::cout << "Key " << k.first;
        std::cout << " - Value " << k.second << "\n";
    }
    std::cout << std::endl;

    // Alternative way using "structured bindings"
    for(const auto& [key, value] : map){
        std::cout << "Key " << key;
        std::cout << " - Value " << value << "\n"; 
    }


    return 0;
};