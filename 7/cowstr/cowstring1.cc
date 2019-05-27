#include<string.h>
#include<iostream>
using namespace std;
class CowString{
    class CharProxy{
    public:
        CharProxy(int idex,CowString & p)
        :_iidex(idex)
         ,_self(p)
        {
            cout<<"CharProxy()"<<endl;
        }
        char & operator=(const char &p);
        operator char(){
            return _self._pstr[_iidex];
        }
    private:
        int _iidex;
        CowString & _self;
    };
    
   public:

    CowString()
    :_pstr(new char[1 + 4]() + 4)
    {
        initRef();
        cout<<"CowString()"<<endl;
    }
    CowString(const char *p)
    :_pstr(new char[strlen(p) + 5]() + 4)
    {   
        initRef();
        strcpy(_pstr,p);
        cout<<"CowString(const char *)"<<endl;
    }    
    CowString(const CowString & p)
    :_pstr(p._pstr)
    {
        cout<<"CowString(const CowString &)"<<endl;
        incrementRef();
    }
    CowString & operator=(const CowString &p){
        if(this != &p){
            release();
            _pstr = p._pstr;
            incrementRef();
        }
        return *this;
    }
    int size(){
        return strlen(_pstr);
    }
    ~CowString(){
        release();
    }
    CharProxy  operator[](int idex){
        return CharProxy(idex,*this);
#if 0
        if(idex >= 0 && idex <= size()){
            if(getRef()>1){
                descend();
                char *pstr = new char[strlen(_pstr) + 5]() + 4;
                strcpy(pstr,_pstr);
                _pstr = pstr;
                initRef();
            }
            return _pstr[idex];
        }
        else{
            cout<<"下标越界"<<endl;
            static char null = '\0';
            return null;
        }
#endif
    }
    int getRef(){
        return *((int *)(_pstr - 4));
    }
    char *c_str(){
        return _pstr;
    }
    friend ostream & operator<<(ostream &os,const CowString &s);
private:
    void release(){
        descend();
        if(0 == getRef()){
            delete [] (_pstr -4);
        }
    }
    void initRef(){
         *((int *)(_pstr - 4)) = 1;
    }
    void incrementRef(){
        ++(*(int *)(_pstr - 4));
    }
    void descend(){
        --(*(int *)(_pstr - 4));
    }


private:
    char *_pstr;
};

char & CowString::CharProxy::operator=(const char &p){
        if(_iidex >= 0 && _iidex <= _self.size()){
            if(_self.getRef()>1){
                _self.descend();
                char *pstr = new char[strlen(_self._pstr) + 5]() + 4;
                strcpy(pstr,_self._pstr);
                _self._pstr = pstr;
                _self.initRef();
            }
            _self._pstr[_iidex] = p;
            return _self._pstr[_iidex];
        }
        else{
            cout<<"下标越界"<<endl;
            static char null = '\0';
            return null;
        }
    
    
}
ostream & operator<<(ostream &os,const CowString &s){
    os<<s._pstr;
    return os;
}
#if 0
ostream & operator<<(ostream &os,const CowString::CharProxy &p){
    os<<p._self._pstr[p._iidex];
    return os;
}
#endif
int main(void){
    CowString s1("hello,world");
    CowString s2(s1);
    cout<<"s1:"<<s1.getRef()<<endl;
    printf("%p\n",s1.c_str());
    cout<<"s2:"<<s2.getRef()<<endl;
    printf("%p\n",s2.c_str());
    s1[0] = 'H';
    cout<<s1[0]<<endl;
    cout<<"s1:"<<s1.getRef()<<endl;
    printf("%p\n",s1.c_str());
    cout<<"s2:"<<s2.getRef()<<endl;
    printf("%p\n",s2.c_str());
    cout<<s2<<endl;
}
