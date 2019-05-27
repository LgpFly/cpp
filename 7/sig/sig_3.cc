#include<pthread.h>
#include<iostream>
using namespace std;
class Sig{
public:
    static Sig *getInstance(){
        pthread_once(&_once,init);
        return _sig;
    }
    static void init(){
        _sig = new Sig();
        ::atexit(destroy);
    }
    static void destroy(void){
        if(_sig){
            delete _sig;
        }
    }

    void print(){
        cout<<"print()"<<endl;
    }

private:
    Sig(){
        cout<<"sig()"<<endl;
    }
    ~Sig(){
        cout<<"~sig()"<<endl;
    }
private:
    static Sig *_sig;
    static pthread_once_t _once;
};

Sig *Sig::_sig = nullptr;
pthread_once_t Sig::_once;

int main(void)
{
    Sig *sig = Sig::getInstance();
    sig->print();
    return 0;
}
