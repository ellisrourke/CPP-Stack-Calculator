//
// Created by Ellis on 14/08/2019.
//
#include "calculator.h"
#include "stack.cpp"
#include <string>
#include <sstream>
#include <iostream>
class calculator {
public:
    const int *precedence = new int[8] {0,0,1,1,2,2,3,3};
    int *equation;
    int equationLen=0;
    int answer=0;
    std::string strin;

    stack operators;
    stack operands;

    calculator(){
        operators.push(-1);
        std::cout << "Enter an equation: ";
        std::getline(std::cin, strin);
        equation = new int[strin.length()];
        createEquation();
    }

    void createEquation(){

        std::stringstream iss(strin);
        std::string value;

        while(iss >> value) {
            if (isdigit(value[0])) {
                equation[equationLen] = std::stoi(value);
            } else {
                int prec = 0;
                switch (value[0]){
                    case '(' : prec = -2;
                        break;
                    case ')' : prec = -3;
                        break;
                    case '+' : prec = -4;
                        break;
                    case '-' : prec = -5;
                        break;
                    case '*' : prec = -6;
                        break;
                    case '/' : prec = -7;
                        break;
                }
                equation[equationLen] = prec;
            }
            equationLen += 1;
        }
    }


    void displayEquation(){
        for(int i=0;i<equationLen;i++){
            std::cout << equation[i] << " ";
        }
        std::cout << std::endl;
    }

};