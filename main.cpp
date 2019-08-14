#include <iostream>
#include "calculator.cpp"

int main(){
    calculator myCalc;

    myCalc.displayEquation();

    std::cout << myCalc.equationLen;

}