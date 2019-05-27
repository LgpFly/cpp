#include<string.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class OnlyStack{
public:
    OnlyStack(const char *name,int num)
    :_name(new char[strlen(name)+1]())
     ,_num(num)
    {
       strcpy(_name,name);
       cout<<"OnlyStack()"<<endl;
    }

    ~OnlyStack(){
        cout<<"~OnlyStack()"<<endl;
    }

private:
    void * operator new(size_t sz);
    void operator delete(void * ret);


private:
    char *_name;
    int _num;

};

int main(void){

    //再创建对象的话用new这个就不行了，
    //new创建对象时就是他的私有函数了。
    OnlyStack stu("xiaoming",1);

    return 0;
}
