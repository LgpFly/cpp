#include "line.h"
#include<math.h>
#include<iostream>
using namespace std;
class Line::LineImpl{
    class Point{
    public:
        Point(int x = 0,int y = 0)
        :_ix(x)
        ,_iy(y)
        {
            cout<<"Point()"<<endl;
        }
        void print() const{
            cout<<"("<<_ix<<","<<_iy<<")"<<endl;
        }
        ~Point(){
            cout<<"~Point"<<endl;
        }
    private:
        int _ix;
        int _iy;
    };
public:
    LineImpl(int x1,int y1,int x2,int y2)
    :_p1(x1,y1)
    ,_p2(x2,y2)
    {
        cout<<"LineImpl()"<<endl;
    }
    void printImpl() const{
        _p1.print();
        cout<<"---->"<<endl;;
        _p2.print();
    } 
    ~LineImpl(){
        cout<<"~LineImpl()"<<endl;
    }

private:
    Point _p1;
    Point _p2;
};

Line::Line(int x1,int y1,int x2,int y2)
:_impl(new LineImpl(x1,y1,x2,y2))
{
    cout<<"Line()"<<endl;
}

void Line::printline() const{
    _impl->printImpl();
}

Line::~Line(){
    if(_impl){
        delete _impl;
    }
}
