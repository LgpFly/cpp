#include<iostream>
using std::cout;
using std::endl;

class Condition{
public:
    Condition(){
        pthread_cond_init(&_cond,NULL);
        pthread_mutex_init(&_mutex,NULL);

        cout<<"Init"<<endl;
    }

    void notify(){
       pthread_cond_signal(&_cond); 
       cout<<"send signal"<<endl;
    }
    void wait(){
        pthread_cond_wait(&_cond,&_mutex);
        cout<<"wait signal"<<endl;
    }

private:
    pthread_cond_t _cond;
    pthread_mutex_t _mutex;
};

void * pthFunc(void *p){
    Condition *pp = (Condition*)p;
    pp->notify();
    return NULL;
}

int main(void){
    Condition con;
    pthread_t pid;
    
    pthread_create(&pid,NULL,pthFunc,&con);
    con.wait();
    pthread_join(pid,NULL);
    return 0;
}
