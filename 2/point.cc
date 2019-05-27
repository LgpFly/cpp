#include<iostream>
using namespace std;
class Point{
public:
    Point(int x=0,int y=0)
    :_ix(x)
     ,_iy(y)
    {
        cout<<"构造函数"<<endl;
    }

    void print(){
        cout<<"x:"<<_ix<<endl<<"y:"<<_iy<<endl;
    }

    //赋值运算符函数
    Point & operator=(const Point & p)
    //这是个函数没有初始化那一套
    {
        cout<<"赋值运算符函数"<<endl;
        _ix=p._ix;
        _iy=p._iy;
        return *this;
    }

private:
    int _ix;
    int _iy;
};

int main(void)
{
    Point p1(1,1);
    p1.print();
    Point p2(2,2);
    p2.print();
    p1 = p2;
    p1.print();
    return 0;
}
