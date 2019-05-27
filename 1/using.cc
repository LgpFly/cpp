#include <iostream>
using std::cout;
using std::endl;
namespace lu{
    int num=10;
    void print(){
        cout<<"i am out"<<endl;
    }
    namespace gp{
        int num=1;
        void print(){
            cout<<"i am in"<<endl;
        }
    }
}
using lu::num;
using lu::gp::print;
int main()
{
    std::cout << "Hello world" << std::endl;
    cout<<num<<endl;
    print();
    return 0;
}

