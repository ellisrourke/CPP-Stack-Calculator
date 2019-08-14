//
// Created by Ellis on 14/08/2019.
//
#include "calculator.h"
#include "stack.cpp"
#include <string>
#include <sstream>
#include <iostream>
class calculator {
private:
    const int *precedence = new int[8] {0,0,1,1,2,2,3,3};
    int *equation;
    int eqautionLen=0;
    int answer=0;
    std::string data;

    stack operators;
    stack operands;

    calculator(){
        std::getline(std::cin, data);
        equation = new int[data.length()];
    }

    void createEquation(){
        std::stringstream iss(data);
        std::string value;

        while(iss>>value) {
            if (isdigit(value[0])) {
                equation[eqautionLen] = std::stoi(value);
            } else {
                int prec = 0;
                
            }
        }
    }
};