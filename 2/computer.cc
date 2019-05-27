#include <iostream>
#include<string.h>
using namespace std;
class Computer{
    
public:

    //构造函数
    //初始化时只与变量的声明顺序有关，其他均无关。
    Computer(const char *str,float price)
    :_brand(new char[strlen(str) + 1]())
     ,_price(price)
    {
        strcpy(_brand,str);
    }
    //打印用于
    void print(){
        cout<<"brand:"<<_brand<<endl<<"price:"<<_price<<endl;;
    }
    
    //复制构造函数：
    //为什么要重新定义复制构造函数？（当类的成员变量是一个指针时，指向的
    //是一个堆空间，若用系统定义的复制构造函数时，两个对象指向同一块堆空间
    //这就容易引发问题。such as 2次delete）
    //1.已经存在的一个对象赋值给一个新对象。
    //2.当实参和形参都是对象，进行传递时（值传递）。
    //3.return一个对象时会调用复制构造函数。
    //question:为什么形式不能变？
    //① 不能去const 非const的引用只能绑定到左值上，加上const也能绑定到
    //右值上。②引用  若不是引用则在形参和实参传递时已是复制构造函数则会进入到死循环中.
    Computer(const Computer & com)//这个形式不能改变
    :_brand(new char[strlen(com._brand) + 1]())
     ,_price(com._price)
    {
        strcpy(_brand,com._brand);
        cout<<"复制构造函数"<<endl;
    }


    //析构函数（用来释放内存等资源）
    //当用到堆空间时要自己写析构函数
    ~Computer(){
        delete [] _brand;
        cout<<"~Computer"<<endl;
    }

    //赋值运算符函数
    Computer & operator=(const Computer & com){
        //如果两个指针不相等的话才会有下面的操作
        if(this != &com){
            //回收操作数开辟的空间
            delete [] _brand;
            //深拷贝
            _brand = new char[strlen(com._brand) + 1]();
            strcpy(_brand,com._brand);
            _price=com._price;
        }
        return *this;
    }


private:
    char * _brand;
    float _price;
};

Computer pc2("lenvo",1);
int main()
{
    //栈对象同时要求构造函数和析构函数都是public类型。
    Computer cp("xiaomi",8888);
    cp.print();

    //堆对象在进行delete时才会调用析构函数
    Computer *pc1 = new Computer("dell",2222);
    pc1->print();
    delete  pc1;
    cout<<"........."<<endl;


    //全局对象在main函数退出后才调用析构函数
    pc2.print();

    //static对象和全局变量时一样的，都是在main函数退出后才调用析构函数
    static Computer cp3("shadan",111);
    cp3.print();
    //复制构造函数
    Computer cp4=cp;
    cp4.print();
    //赋值运算符函数
    cp4 = cp3;
    cp4.print();
    return 0;
}

