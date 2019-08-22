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
    int precedence[8] = {0, 0, 1, 1, 2, 2, 3, 3};
    int *equation;
    int equationLen = 0;
    int answer = 0;
    std::string strin;
    stack operators;
    stack operands;
    stack postfix;

    //default constructor
    calculator() {
        operators.push(-1);
        postfix.push(-1);
        std::cout << "Enter an equation: ";
        std::getline(std::cin, strin);
        equation = new int[strin.length()];
        createEquation();
    }

    //copy constructor
    calculator(calculator const & that):equationLen{that.equationLen}, answer{that.answer}{
        operators = that.operators;
        operands = that.operands;
        equation = new int[that.strin.length()];

        for(int i=0;i<equationLen;i++){
            equation[i] = that.equation[i];
        }
    }

    //move constructor
    calculator(calculator && that) noexcept : operators{that.operators},operands{that.operands},
    answer{that.answer},equation{that.equation},equationLen{that.equationLen}{
        that.equation = nullptr;
    }

    //copy assignment
    calculator & operator = (calculator const & that){
        if(this != &that){
            operands = that.operands;
            operators = that.operators;
            answer = that.answer;
            equationLen = that.equationLen;
            equation = new int[equationLen];

            for(int i=0;i<equationLen;i++){
                equation[i] = that.equation[i];
            }
        }
        return *this;
    }

    //move assignment
    calculator & operator = (calculator && that) noexcept {
        operators = that.operators;
        operands = that.operands;
        equation = that.equation;
        equationLen = that.equationLen;
        answer = that.answer;
        that.equation = nullptr;
        return *this;
    }

    //destructor
    ~calculator(){
        delete[] equation;
    }

    void createEquation() {
        //CONVERT INPUT STING INTO STREAM
        std::stringstream iss(strin);
        std::string value;
        //FOR EVERY CHAR, IF AN INT (OPERAND) PUSH TO EQUATION
        //ELSE, IF ITS A OPERATOR, GET ITS PRECEDENCE
        while (iss >> value) {
            if (isdigit(value[0])) {
                equation[equationLen] = std::stoi(value);
            } else {
                int opIdentifier = 0;
                switch (value[0]){
                    case '(' :
                        opIdentifier = -2;
                        break;
                    case ')' :
                        opIdentifier = -3;
                        break;
                    case '+' :
                        opIdentifier = -4;
                        break;
                    case '-' :
                        opIdentifier = -5;
                        break;
                    case '*' :
                        opIdentifier = -6;
                        break;
                    case '/' :
                        opIdentifier = -7;
                        break;
                }
                equation[equationLen] = opIdentifier;
            }
            equationLen += 1;
        }
    }


    static int operation(int operand1, int operand2, int op) {
        //take in two operands and an operate, compute the result and return the value
        switch (op) {
            case -4:
                std::cout << "operation: " << operand1 << " " << op << " " << operand2 << std::endl;
                return operand1 + operand2;
            case -5:
                return operand2 - operand1;
            case -6:
                return operand1 * operand2;
            case -7:
                return operand2 / operand1;
            default:
                return operand1;

        }
    }

    void displayEquation() {
        for (int i = 0; i < equationLen; i++) {
            std::cout << equation[i] << " ";
        }
        std::cout << std::endl;
    }

//operator     $  (  )  +  −  ∗  /
//identifier  -1 -2 -3 -4 -5 -6 -7
//precedence 0 0  1  1  2  2  3  3

    void calcLogic() {
        //get each element.
        //First, check if it is an operand, if is, push to operands stack.
        //if the current element is an open bracket... push to the operators stack

        for (int i = 0; i < equationLen; i++) {
            int current = equation[i];
            if (current >= 0) {
                operands.push(current);
            } else if (current == -2) {
                operators.push(-2);
            } else if (current == -3) {
                while (true) {
                    int operate = operators.pop();
                    if (operate == -2)
                        break;
                    int operand1 = operands.pop();
                    int operand2 = operands.pop();
                    operands.push(operation(operand1, operand2, operate));
                }
            } else if (precedence[-(operators.nextPop())] < precedence[-(current)]) {
                operators.push(current);
            } else {
                int operand1 = operands.pop();
                int operand2 = operands.pop();
                operands.push(operation(operand1, operand2, operators.pop()));
                operators.push(current);
            }

            std::cout << "operators" << std::endl;
            operators.display();
            std::cout << "operands" << std::endl;
            operands.display();
        }

        int operand1 = operands.pop();
        int operand2 = operands.pop();
        answer = operation(operand1, operand2, operators.pop());



    }

    void myFunc(calculator const & C){
        std::cout << C.equationLen << std::endl;
    }

};