#include<iostream>
using std::cout;
using std::endl;

typedef struct q_node{
    int num;
    struct q_node *pNext;
}node,*pNode;

class Queue{
public:
    Queue()
    :_head(nullptr)
     ,_tail(nullptr)
    {
        cout<<"对象初始化"<<endl;
    }
    
    void push(int x){
        pNode pnew = (pNode)malloc(sizeof(node));
        pnew->num = x;
        pnew->pNext = nullptr;
        if(_head == _tail && _tail == nullptr){
            _head = pnew;
            _tail = pnew;
        }
        else{
            _tail->pNext = pnew;
            _tail = pnew;
        }
        cout<<"push success"<<endl;
    }

    void pop(){
        if(_head == _tail && _head == nullptr){
            cout<<"empty"<<endl;
        }else if(_head == _tail){
            _head = nullptr;
            _tail = nullptr;
            cout<<"last one has fly...."<<endl;
        }else{
            _head = _head->pNext;
            cout<<"pop success"<<endl;
        }
    }

    int front(){
        if(_head == _tail && _head == nullptr){
            cout<<"empty"<<endl;
            return 0;
        }
        else{
            return _head->num;
        }
    }
    int back(){
        if(_head == _tail && _head == nullptr){
            cout<<"empty"<<endl;
            return 0;
        }
        else{
            return _tail->num;
        }
    }
    bool empty(){
        if(_head == _tail && _head == nullptr){
            return true;            
         }
        else
            return false;
    }

private:
     pNode _head;
     pNode _tail;
};


int main(void){
    
    Queue que;
    que.push(1);
    que.push(3);
    que.push(5);
    que.pop();
    int a = que.back();
    cout<<"a = "<<a<<endl;

    int b = que.front();
    cout<<"b = "<<b<<endl;
    if(que.empty()){
        cout<<"empty"<<endl;
    }
    else{
        cout<<"not empty"<<endl;

    }

    return 0;
}
