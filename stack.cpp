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

    int pop(){
        if(items <= 0)
            return 0;
        items -= 1;
        return list[items];
    };

    int nextPop(){
        return list[items-1];

    }

    void display(){
        for(int i=0;i<items;i++){
            std::cout << list[i] << " ";
        }
        std::cout << std::endl;
    }
};