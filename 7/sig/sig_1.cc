
#include<iostream>
using namespace std;
class Sig{
    class AutoRelase{
    public:
        AutoRelase(){
            cout<<"AutoRelase()"<<endl;
        }
        ~AutoRelase(){
            cout<<"~AutoRelase()"<<endl;
        }
    };
public:
    static Sig *getInstance(){
        if(nullptr == _sig){
            _sig = new Sig();
        }
        return _sig;
    }

    void print(){
        cout<<"print()"<<endl;
    }
private:
    Sig()
    {
        cout<<"sig()"<<endl;
    }
    ~Sig()
    {
        cout<<"~sig()"<<endl;
    }

private:
    static Sig *_sig;
    static AutoRelase _auto;
};

Sig *Sig::_sig = nullptr;
Sig::AutoRelase Sig::_auto;

int main(void){
    Sig *sig = Sig::getInstance();
    sig->print();
}
