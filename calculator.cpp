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
    int answer= 0;
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


    int operation(int operator1, int operator2, int op){
        switch (op){
            case -4 :
                return operator1 + operator2;
            case -5 :
                return operator2 - operator1;
            case -6 :
                return operator1 * operator2;
            case -7 :
                return operator2 / operator1;
            default:
                return operator1;

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
            int current = equation[i];
            if(current>=0){
                operands.push(current);
            }
            else if(current == -2){
                operators.push(-2);
                //pushing (
            } else if(current == -3) {
                while (true) {
                    int operate = operators.pop();
                    if (operate == -2)
                        break;
                    int operand1 = operands.pop();
                    operands.push(operation(operand1, operands.pop(), operate));
                }
            } else {
                //When you get an operator O in the array e.g. +, −, ∗, /, assume O-
                //is the operator e.g. +, −, ∗,
                ///, (, $ to be popped from the stack next. If O- has a lower precedence than O then push O to the
                //operator stack. Otherwise, if O- has a higher/equal precedence than O, then pop O-
                //from the
                //operator stack and pop two operands from the operand stack, compute the result depending on
                //the popped operator, and push the result to the operand stack. Carefully notice the left and the
                //right operands. Go to the beginning of this step to consider the next operator O-
                //to be popped
                //from the operator stack since we have not yet done with the operator O.










            }
                std::cout << "Operands:  ";
                operands.display();
                std::cout << "Operators: ";
                operators.display();
                std::cout << std::endl;

        }
        int operand1 = operands.pop();
        answer = operation(operand1, operands.pop(), operators.pop());

    }

    void main(){
        //std::cout << answer << std::endl;
    }

};