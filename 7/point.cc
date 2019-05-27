#include<iostream>

using namespace std;

class Complex{
public:
    Complex(int x = 0,int y = 0)
    :_rear(x)
     ,_xu(y)
    {
        cout<<"Complex()"<<endl;
    }

    int getRear() const {
        return this->_rear;
    } 
    int getXu() const {
        return this->_xu;
    }

    ~Complex(){
        cout<<"~Complex()"<<endl;
    }
private:
    int _rear;
    int _xu;
};

class Point{
public:
    Point(int x = 0,int y = 0)
    :_ix(x)
     ,_iy(y)
    {
        cout<<"Point()"<<endl;
    }
    
    Point(const Complex & rhs)
    :_ix(rhs.getRear())
     ,_iy(rhs.getXu())
    {
        cout<<"Point(Complex)"<<endl;
    }
    
    operator int(){
        return _ix + _iy;
    }


    friend std::ostream &operator<<(std::ostream &os,const Point & rhs){
        os<<"("<<rhs._ix<<","<<rhs._iy<<")";
        return os;
    }
    
    ~Point(){
        cout<<"~point()"<<endl;
    }

private:
    int _ix;
    int _iy;
};

int main(void){
    Complex com(1,2);
    Point poi = com;
    cout<<poi<<endl;

    int a = poi;
    cout<<a<<endl;
}
