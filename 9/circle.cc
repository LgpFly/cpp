#include<iostream>

using namespace std;

class Circle{
public:
    Circle()
    :_circle(0)
    {cout<<"Circle()"<<endl;}

    Circle(double r)
    :_circle(r)
    {
        cout<<"Circle(double)"<<endl;
    }

    double getArea(){
        return 3.14 * _circle * _circle;
    }
    double getPerimeter(){
        return 3.14 * 2 * _circle;
    }
    void show(){
        cout<<"circle:"<<_circle<<endl<<
            "Area:"<<getArea()<<endl
            <<"Perimeter:"<<getPerimeter()<<endl;
    }

private:
    double _circle;

};
class Cylinder
:public Circle
{
public:
    Cylinder (double r, double  h)
    :Circle(r)
    ,_high(h)
    {
        cout<<"Cylinder(double,double)"<<endl;
    }
    double getVolume(){
        return _high * getArea();
    }
    void  showVolume(){
        cout<<"volume:"<<getVolume()<<endl;
    }
private:
    int _high;
};

int main(void){
    Cylinder c(2.0,2.0);
    c.show();
    c.showVolume();
    return 0;
}

