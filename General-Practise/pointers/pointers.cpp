#include <iostream>
#include <vector>
#include <random>
#include <ctime>

int getRandNum(const int& min_range, const int& max_range){
    srand(std::time(NULL)); // Seed the time
    int finalNum = rand()%(max_range-min_range+1)+min_range;

    return finalNum;
}


void printSum(const int& num1, const int& num2){
    std::cout << "Sum of " << num1 << " + " << num2 << " = " << num1+num2 << std::endl;
}

void forEach(const std::vector<int>& vec, void(* externalFunc)(const int&) ){ // pass func pointer variable as argument
    for(const auto& num : vec){
        externalFunc(num); // call the func pointer 
    }
}

int main(){

    // ARRAYS
    int array1[10] = {1, 3, 4, 2, 12};
    int* arrPtr = array1; //arrays are just pointers to the begining of the block of memory so we dont need &

    for(int x = 0; x < 5; x++){
        std::cout << arrPtr[x] << "\n"; // Notice we dont need to dereference
    }

    // CHARS
    char initial = 'P';
    char* pInitial = &initial;

    // Compiler expects us to print our actual initial as a string because characters usually point to strings
    // So to get the address of a single char we have to use casting
    // (void *) tell us the compiler i want the pointer value and not the string at that address
    std::cout << "Address for initial P " << (void *)pInitial << "\n";

    // Char pointers can also be used to point to a string literal via a const pointer char
    // And we dont need to dereference when outputing the value
    // We can have a char pointer point to a string literal as a char pointer points to the first char, make sure 
    // to make it const however
    const char* stringy1{"Hello"};
    const char* stringy2{" World!"};
    std::cout << (void *)stringy1 << stringy2 << "\n";


    // 8 BALL POOL WISH GAME
    // The vector's destructor won't call delete on the pointers, so it's easy to accidentally leak memory. A vector's 
    // destructor calls the destructors of all the elements in the vector, but raw pointers don't have destructors.
    // So we use unique pointers (smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope)
    // Or manually delete the pointers once finished

    // std::vector<const char*> answers{"Maybe...", "No.", "Yes!", "It's a possibility", "This will become true.", "Its not looking good"};

    // std::cout << "Think of a Yes/No question in your head, when ready press enter and reveal your fortune!" << "\n";
    // std::cin.ignore();

    // std::cout << answers[getRandNum(0, 3)];

    // for(const auto& answer : answers){
    //     delete answer; // Stop memory leaks
    // }
    // answers.clear();


    // ARRAYS OF POINTERS
    int testScores[5] = {1,4,6,7,3};
    int* arrayPointers[5];

    for(int x = 0; x < 5; x++){
        arrayPointers[x] = &testScores[x]; // filling up the arrayPointers with pointers
        //std::cout << *arrayPointers[x] << " ";
        std::cout << **arrayPointers + x<< " "; // dereference pointer to testerscores and dereference testerscore to get numbers
    }
    std::cout << "\n";


    // FUNCTION POINTERS
    // make our function 'variable', can then assign any function with the same return, and parameter types as we defined
    void(* myFunction)(const int&, const int&);
    myFunction = &printSum; // Without the () it just gives the address off the function (we dont actually need &)

    myFunction(5, 5); // Call via the variable

    // Example above is not a practical use case however
    // Say we wanted to call a function that loops through a given array, and calls another function on each value
    std::vector<int> nums = {4,6,2,5,87};

    // The second paramenter is just a lambda (like a temporary function)
    //, saves lines, otherwise put a predefined function name minus the ()
    forEach(nums, [](const int& num){std::cout << "Nice Number! - " << num << "\n";});

    return 0;
}