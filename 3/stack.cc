#include<iostream>
using std::cout;
using std::endl;

class Stack{

public:
    void initStack(){
        stackTop = _sta;
        stackBottom = _sta;
        cout<<"InitStack Success"<<endl;
    }
    void push(int num){
        if(stackTop <= _sta+9){
            *stackTop = num;
            stackTop++;
            cout<<"push(int) success"<<endl;
        }
        else{
            cout<<"stack full"<<endl;
        }
    }

    void pop(){
        if(stackTop == stackBottom){
            cout<<"stack empty"<<endl;
        }
        else{
            stackTop--;
            cout<<"pop"<<*stackTop<<endl;
        }
    }

    int top(){
        if(stackTop == stackBottom){
            cout<<"stack empty"<<endl;
            return 0;
        }
        else{
            return *(stackTop-1);
        }
    }

    bool empty(){
        if(stackTop == stackBottom){
            return true;
        }
        else{
            return false;
        }
    }

    bool full(){
        if(stackTop == (_sta+10)){
            return true;
        }
        else{
            return false;
        }
    }

private:
    int _sta[10];
    int *stackTop;
    int *stackBottom;
};

int main(void){
    Stack sta1;
    sta1.initStack();
    sta1.push(10);
    sta1.push(12);
    sta1.push(14);
    sta1.pop();
    int a = sta1.top();
    cout<<"top is "<<a<<endl;
    if(sta1.empty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;

    }
    if(sta1.full()){
        cout<<"stack is full"<<endl;
    }
    else{
        cout<<"stack is not full"<<endl;

    }
    return 0;
}
