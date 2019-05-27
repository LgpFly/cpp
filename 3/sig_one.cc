#include<iostream>
using std::cout;
using std::endl;

class Sigone{
    
public:
    //3.定义一个返回值位类指针的静态成员函数
    //静态成员函数（没有隐藏的this指针了就）只能访问静态成员（函数）
    //不能访问非静态的成员和函数。
    //静态成员函数通过类名来访问。
    static Sigone * getfunc(){
        if(_sig==nullptr){
            _sig = new Sigone();
        }
        return _sig;
    }

    void print() const{
        cout<<"print() const"<<endl;
    }

    static void destroy(){
        if(_sig){
            delete  _sig;
        }
    }


private:
    //1.将构造函数私有化
    Sigone(){
        cout<<"Sigone"<<endl;
    }
    //为了使函数看起来对称，所以析构函数也要怎么设计
    ~Sigone(){
        cout<<"~Sigone()"<<endl;
    }
private:
    //2.定义一个静态的指针变量，并在类外初始化为空。
    static Sigone * _sig;
};

//静态成员的初始化要在类外部
Sigone *Sigone::_sig=nullptr;
int main(void){
    
    Sigone *p1 = Sigone::getfunc();
    Sigone *p2 = Sigone::getfunc();
    cout<<"p1="<<p1<<endl
        <<"p2="<<p2<<endl;
    Sigone::getfunc()->print();
    
    Sigone::destroy();
    return 0;
}
