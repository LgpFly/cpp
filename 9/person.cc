#include<iostream>

using namespace std;

//构建一个类person，包含字符串成员name（姓名），整型数据成员age（年龄），成员函数
//   display（）用来输出name和age。构造函数包含两个参数，用来对name和age初始化。
class Person{

public:
    Person(string name,int age)
    :_name(name)
     ,_age(age)
    {
        cout<<"Person(string,int)"<<endl;
    }
    void display() const{
        cout<<"name:"<<_name<<endl
            <<"age:"<<_age<<endl;
    }
private:
    string _name;
    int _age;
};

//构建一个类employee由person派生，包含department（部门），实型数据成员salary（工资）,
       //成员函数display（）用来输出职工姓名、年龄、部门、工资，其他成员根据需要自己设定。
class Employee
:public Person
{
public:
    Employee(string name,int age,string department,double salary)
    :Person(name,age)
     ,_department(department)
     ,_salary(salary)
    {  cout<<"Employee(string,int,string,double)"<<endl;  }

    void display() const{
        Person p(*this);
        p.Person::display();
        cout<<"department:"<<_department<<endl
            <<"salary:"<<_salary<<endl;
    }
    double getSalary(){
        return _salary;
    }
private:
    string _department;
    double _salary;

};

int main(void){
    Employee e("zhangsan",33,"AI",99999.0);
    e.display();
    Employee e1("lisi",44,"IA",88888.0);
    e1.display();
    Employee e2("wangwu",55,"FBI",567893456.0);
    e2.display();
    double average = (e.getSalary() + e1.getSalary() + e2.getSalary())/3;
    cout<<"average:"<<average<<endl;
}
