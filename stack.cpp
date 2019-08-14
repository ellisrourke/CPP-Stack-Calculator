#include <iostream>
#include "stack.h"

class stack {
private:
    int *list;
    int items;

public:
    stack(){
        list = new int[100];
        items = 0;
    }

    void push(int x){
        list[items] = x;
        items++;

    };

    //int pop();

    int display(){
        for(int i=0;i<items;i++){
            std::cout << list[i] << " ";
        }
    }
};