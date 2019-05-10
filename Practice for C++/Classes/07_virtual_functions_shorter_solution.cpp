//https://www.hackerrank.com/challenges/virtual-functions/problem

//all data are public, so there's no need to establish interface function to read and write data


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    public:
        string name;
        int age;
    
        virtual void getdata(){cout<<"getdata"<<endl;}
        virtual void putdata(){cout<<"putdata"<<endl;}
};

class Student: public Person{
    public:
        int marks[6];
        int cur_id;
        static int id;

        Student(){
            cur_id = ++id;
        }

        void getdata();
        void putdata();

};

int Student::id = 0;

void Student::getdata(){
    int temp;
    cin>>name>>age;

    for(int i=0;i<6;i++){
        cin>>temp;
        marks[i] = temp;
    }
}

void Student::putdata(){
    int sum=0;
    for(int i=0;i<6;i++){
        sum+=marks[i];
    }
    cout<<name<<" "<<age<<" "<<sum<<" "<<cur_id<<" "<<endl;
}

class Professor: public Person{
    public:
        int publications;
        int cur_id;
        static int id;

        Professor(){
            cur_id = ++id;
        }
        void getdata();
        void putdata();

};

int Professor::id = 0;

void Professor::getdata(){
    cin>>name>>age>>publications;
}

void Professor::putdata(){
    cout<<name<<" "<<age<<" "<<publications<<" "<<cur_id<<" "<<endl;
}

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
