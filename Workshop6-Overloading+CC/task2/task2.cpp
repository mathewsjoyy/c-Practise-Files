#include <iostream>
#include <vector>
#include <algorithm>

// Templates all you to have multiples data types, rather then making a new function for each data type
template <typename T>
void sortVector(std::vector<T>& vector, const bool& option){
    if(option){
        std::sort(vector.begin(), vector.end()); // sort ascending
    }
    else{
        std::sort(vector.begin(), vector.end(), std::greater<>()); // sort descending
    }

    // print out the sorted version
    for(auto& i : vector){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}



int main(){

    std::vector<int> numbers = {1, 3, 5, 2, 10, 4};
    // std::vector<double> numbers2 = {1.2, 3.4, 5.1, 2.3, 10.1, 4.3};

    sortVector(numbers, false);
    // sortVector(numbers2, true);

    return 0;
};