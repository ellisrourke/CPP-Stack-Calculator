#include <iostream>
#include "stack.h"

class stack {
public:
    int *list;
    int items;


    stack(){
        list = new int[256];
        items = 0;
    }

    void push(int x){
        items+=1;
        list[items - 1] = x;
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