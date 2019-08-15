#include <iostream>
#include "calculator.cpp"

int main() {
    calculator myCalc;
    myCalc.displayEquation();
    myCalc.calcLogic();
    std::cout << "answer: " << myCalc.answer << std::endl;

    //std::cout << myCalc.operation(12,3,-2);


}
