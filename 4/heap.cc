#include<string.h>
#include<stdlib.h>

#include<iostream>

using namespace std;
class OnlyHeap{
public:
    OnlyHeap(const char *name,int num)
    :_name(new char[strlen(name) + 1]())
     ,_num(num)
    {
        strcpy(_name,name);
    }

private:
    ~OnlyHeap(){
        delete [] _name;
    }

private:
    char *_name;
    int _num;
};
int main(void){
    cout<<"hello world"<<endl;
    OnlyHeap *stu = new OnlyHeap("xiaoming",01);
    //OnlyHeap stu1("xiaohong",2);
}
