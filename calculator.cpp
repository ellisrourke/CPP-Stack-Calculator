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


    static int operation(int operator1, int operator2, int operand){
        switch (operand){
            case -4:
                return operator1 + operator2;
            case -5:
                return operator1 - operator2;
            case -6:
                return operator1 * operator2;
            case -7:
                return operator1 / operator2;
            default: return 0;

        }
    }

    void displayEquation(){
        for(int i=0;i<equationLen;i++){
            std::cout << equation[i] << " ";
        }
        std::cout << std::endl;
    }

//operator     $  (  )  +  −  ∗  /
//identifier  -1 -2 -3 -4 -5 -6 -7
//precedence 0 0  1  1  2  2  3  3

//(c) When you get an operator ) in the array, keep popping operators from the operator stack until
//you pop (. For each operator popped, except the last ( of course, pop two operands from the
//operand stack, compute the result depending on the popped operator and and push the result
//back to the operand stack. Carefully notice the left and the right operands.

    void calcLogic(){
        for(int i=0;i<equationLen;i++){
            operands.display();
            operators.display();
            int current = equation[i];

            if(current>=0){
                operands.push(current);
            }
            else if(current == -2){
                operators.push(-2);
                //pushing (
            } else if(current == -3) {
                while (true) {
                    int op = operators.pop();
                    if(op == -2)
                        break;
                    else {
                        int op1 = operands.pop();
                        int op2 = operands.pop();
                        int result = operation(op1, op2, op);
                        std::cout << result << std::endl;
                        operands.push(result);
                    }
                }
            }
        }
    }

};