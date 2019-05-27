#include<iostream>
#define N 10000000
using std::cout;
using std::endl;
int sum = 0;

class MutexLock{
public:

    static MutexLock * getInit(){
        if(_mlock == nullptr){
            _mlock = new MutexLock();
        }
        return _mlock;
    }

    void lock(){
        while(1){
            if(_lock == 1){
                _lock--;
                break;
            }
        }
    }
    
    void unlock(){
        _lock++;
    }


private:
    MutexLock(int x = 1)
    :_lock(x)
     //,_sum(y)
    {
        cout<<"Init"<<endl;
    }


private:
    static MutexLock * _mlock;
    int _lock;
    //int _sum;
    //int _N
};

MutexLock * MutexLock::_mlock = nullptr;


void *pthFunc(void *p){
    MutexLock *pp = (MutexLock *)p;
    for(int i = 0;i<N;++i){
        pp->lock();
        sum++;
        pp->unlock();
    }
    //return NULL;
    pthread_exit(NULL);
}

int main(void){
    MutexLock *ptr = MutexLock::getInit();
    pthread_t pid;
    pthread_create(&pid,NULL,pthFunc,ptr);
    for(int i = 0;i < N;++i){
        ptr->lock();
        sum++;
        ptr->unlock();
    }
    pthread_join(pid,NULL);
    cout<<"sum is "<<sum<<endl;
    return 0;
}
