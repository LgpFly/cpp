#include<string.h>
#include<vector>
#include<iostream>
#include<string>
using namespace std;


class String {
public:
    String()
    :_pstr(new char[1]())
    {
        cout<<"String()"<<endl;
    }
    String(const char *p)
    :_pstr(new char[strlen(p) + 1]())
    {
        strcpy(_pstr,p);
        cout<<"String(const char *p)"<<endl;
    }
    String(const String & p)
    //:_pstr(new char[p.size() + 1]())
    {
        const char *ptr = p.c_str();
        _pstr = new char[strlen(ptr) + 1]();
        strcpy(_pstr,ptr);
        cout<<"String(const String &p)"<<endl;
    }

    void print(){
        cout<<_pstr<<endl;
    }
    ~String(){
        delete [] _pstr;
    }
    String &operator=(const String & p)
    {
        if(this == &p){
            return *this;
        }else{
            delete [] _pstr;
            const char *str = p.c_str();
            int len = strlen(str);
            _pstr = new char[len + 1]();
            strcpy(_pstr,str);
            return *this;
        }
    }

    String &operator=(const char *p){
        if(!(strcmp(this->_pstr,p))){
            return *this;
        }else{
            delete [] _pstr;
            _pstr = new char[strlen(p) + 1]();
            strcpy(_pstr,p);
            return *this;
        }
    }

    String &operator+=(const String & str){
        const char *p = str.c_str();
        char *p2 = new char[strlen(this->_pstr) + 1]();
        strcpy(p2,this->_pstr);
        int len1 = strlen(this->_pstr);
        int len2 = strlen(p);
        delete [] _pstr;
        _pstr = new char[len1 + len2 + 1]();
        strcpy(_pstr,p2);
        delete [] p2;
        strcat(_pstr,p);
        //cout<<_pstr<<endl;
        return *this;
    }
    String &operator+=(const char *p){
        int len1 = strlen(p);
        int len2 = strlen(this->_pstr);
        char *p2 = new char[strlen(this->_pstr) + 1]();
        strcpy(p2,this->_pstr);
        delete [] _pstr;
        _pstr = new char[len1 + len2 + 1]();
        strcpy(_pstr,p2);
        delete [] p2;
        strcat(_pstr,p);
        return *this;
    }
    char &operator[](std::size_t index){
        return *((this->_pstr) + index);    
    }
    const char &operator[](std::size_t index) const{
        const static  char _a = *((this->_pstr) + index);
        return _a;
    }

    std::size_t size() const{
        std::size_t size_num = 0;
        while(*(this->_pstr + size_num) != '\0'){
            size_num++;
        }
        return size_num;

    }
    const char* c_str() const{
        const char *p = this->_pstr;
        return p;
    }

    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);

    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>=(const String &, const String &);

    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend std::istream &operator>>(std::istream &is, String &s);

private:
    char * _pstr;

};

bool operator==(const String & str, const String & str1){
    if(!strcmp(str.c_str(),str1.c_str())){
        return true;
    }
    else
        return false;
}
bool operator!=(const String & str, const String & str1){
    if(!strcmp(str.c_str(),str1.c_str())){
        return false;
    }
    else
        return true;

}

bool operator<(const String & str, const String & str1){
    if(strcmp(str.c_str(),str1.c_str()) > 0){
        return false;
    }else
        return true;
}
bool operator>(const String & str, const String & str1){
    if(strcmp(str.c_str(),str1.c_str()) > 0){
        return true;
    }else
        return false;

}
bool operator<=(const String & str, const String & str1){
    if(strcmp(str.c_str(),str1.c_str()) > 0){
        return false;
    }else
        return true;
}
bool operator>=(const String & str, const String & str1){
    if(strcmp(str.c_str(),str1.c_str()) >= 0){
        return true;
    }else
        return false;

}

std::ostream &operator<<(std::ostream &os, const String &s){
    os<<s._pstr;
    return os;
}
std::istream &operator>>(std::istream &is, String &s){
    vector<char> num;
    num.reserve(32);
    delete [] s._pstr;
    char ch;
    while((ch = is.get()) != '\n'){
        num.push_back(ch);
    }
    s._pstr = new char[num.size() + 1]();
    strncpy(s._pstr,&num[0],num.size());
    return is;
}


int main(void){
    String s0;
    cin>>s0;
    s0.print();
    String s;
    s.print();
    String s2("hello,world");
    s2.print();
    String s3(s2);
    s3.print();
    s = s3;
    s.print();
    s = "hello";
    s.print();
    s += s3;
    s.print();
    s += ",nihao";
    s.print();
    char _a = s[5];
    cout<<"_a = "<<_a<<endl;
    const char _b = s[5];
    cout<<"_b = "<<_b<<endl;
    cout<<s.size()<<endl;
    if(s>s2){
        cout<<"s>s2"<<endl;
    }
    else
        cout<<"s<s2"<<endl;
    return 0;
}
