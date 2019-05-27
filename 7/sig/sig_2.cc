#include<iostream>

using namespace std;

class Sig_2{
public:
    static Sig_2 * getInstace(){
        if(_pSig == nullptr){
           _pSig = new Sig_2();
           //静态方法只能访问静态成员函数和静态成员
           atexit(destroy);
        }
        return _pSig;
    }

    void print(){
        cout<<"print()"<<endl;
    }

    static void destroy(void){
        if(_pSig){
            delete _pSig;
        }
    }
private:
    Sig_2(){
        cout<<"Sig_2()"<<endl;
    }
    ~Sig_2(){
        cout<<"~Sig_2"<<endl;
    }
private:
    static Sig_2 *_pSig;
};
Sig_2 *Sig_2::_pSig = getInstace();

int main(void){
    Sig_2 *p = Sig_2::getInstace();
    p->print();
}
