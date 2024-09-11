#include <iostream>
using namespace std;
// project for all OOP-Principles.
class Work_Type{
    virtual void Work()=0;
};
class Company:Work_Type {
private:
    int Employee_ID;
protected:
    string NameEmployee;
    int AgeEmployee;
    int YearsOfExperience;
    string Type_work;
public:
    Company(string Name, int Age, int Years , int ID, string type){
        NameEmployee = Name;
        AgeEmployee = Age;
        YearsOfExperience = Years;
        Employee_ID = ID;
        Type_work = type;
    }
    void SetId (int ID){
        Employee_ID=ID;
    }
    int GetID (){
        return Employee_ID;
    }
    void Work() {
        cout<< NameEmployee << " is working in " << Type_work <<" field"<<endl;
    }
};
class rest_time: public Company{
public:
    int restTime;
    rest_time(string Name, int Age, int Years , int ID, string type, int rest) :Company(Name,Age,Years,ID,type){
        restTime = rest;
    }
    virtual void restInWorkTime(){
        if( YearsOfExperience >= 5 & AgeEmployee >= 30 ){
            restTime = 4;
            cout<<NameEmployee<<" Your rest time is:"<< restTime<<"h"<< endl;
        }
        else{
            restTime = 2;
            cout<<NameEmployee<<" Your rest time is:"<< restTime<<"h"<<endl;
        }
    }
};
int main() {
    string name , type;
    int age, experience, rest, ID;
    cout<<"Enter your name:";    cin>>name;
    cout<<"Enter your age:";     cin>>age;
    cout<<"Enter your experience years:";  cin>>experience;
    cout<<"Enter your ID:";  cin>>ID;
    cout<<"Enter your work type:";  cin>>type;
    rest_time e1 = rest_time(name, age, experience, ID, type,rest);
    Company * e2=&e1;
    e2->Work();
    e1.restInWorkTime();
    return 0;
}