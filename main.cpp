#include <iostream>
#include "calculator.cpp"

int main() {
    calculator myCalc;
    myCalc.displayEquation();
    myCalc.calcLogic();
    std::cout << "answer: " << myCalc.answer << std::endl;
    //myCalc.operators.push(-4);
    //std::cout << myCalc.operation(12,3,-2);
    //std::cout << myCalc.precedence[-(-6)];

    myCalc.myFunc(myCalc);

}
