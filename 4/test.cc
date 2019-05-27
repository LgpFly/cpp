
#include<string.h>
#include<stdlib.h>

#include<iostream>

using namespace std;

class OnlyHeap{
public:
    OnlyHeap(const char *name,int num)
    :_name(new char[strlen(name)+1]())
     ,_num(num)
    {
        strcpy(_name,name);
        cout<<"OnlyHeap"<<endl;
    }
    void * operator new(size_t sz)
    
    {
        cout<<"new()"<<endl;
        void *ret=malloc(sz);
        return ret;
    }
    void operator delete(void *ret){
        cout<<"delete()"<<endl;
        free(ret);

    }

    void destroy(){
        delete this;
    }

private:
    ~OnlyHeap(){
        delete [] _name;
        cout<<"~OnlyHeap"<<endl;
    }


private:
    char *_name;
    int _num;

};
//创建只能在堆上的对象，只要把析构函数私有话就行了。
int mian(void){
    OnlyHeap *stu = new OnlyHeap("xiaoming",1);
    //OnlyHeap stu1("xiaohong",2);
    stu->destroy();
    return 0;
}
