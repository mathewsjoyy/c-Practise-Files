// Lecture3.cpp : This file contains the 'main' function. Program execution begins and ends there. //
#include <iostream>
using namespace std;

//to be completed (call by value)
void swapv(int x, int y) {
    int temp = x;
    x = y;
    y = temp;

    std::cout << "Task 1 (call by value) X:" << x << " Y:" << y << std::endl;
}

// Calling by pointers
void swapr(int* x, int* y) {
    int aux = *x;
    *x = *y;
    *y = aux;
}

// Call by reference
void swap(int& x, int& y) {
    int aux = x;
    x = y;
    y = aux;
}

void (*pf)(int& x, int& y);


int main()
{
    int a = 2;
    int b = 3;
    printf("%d,%d \n", a, b);
    swapr(&a, &b);
    printf("%d,%d \n", a, b);
    // void (*pf)(int& x, int& y) = swapr;
    pf = swap;
    pf(a, b);
    printf("pf %d,%d \n", a, b);

    // TASK 1 (call by value)
    int x = 2;
    int y = 3;

    swapv(x, y);

    return 0;
}
