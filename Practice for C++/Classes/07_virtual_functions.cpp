//https://www.hackerrank.com/challenges/virtual-functions/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    private:
        string name;
        int age;
    public:
        virtual void getdata(){cout<<"getdata"<<endl;}
        virtual void putdata(){cout<<"putdata"<<endl;}

        void input_name(string in_name){
            name = in_name;
        }

        string get_name(){
            return name;
        }

        void input_age(int in_age){
            age = in_age;
        }

        int get_age(){
            return age;
        }
};

class Student: public Person{
    private:
        int marks[6];
        int cur_id;
        static int id;

    public:
        Student(){
            cur_id = ++id;
        }
        void getdata();
        void putdata();

        void input_marks(int in_marks[6]){
            for(int i=0;i<6;i++){
                marks[i] = in_marks[i];
            }
        }

        int* get_marks(){
            return marks;
        }

        int get_cur_id(){
            return cur_id;
        }
};

int Student::id = 0;

void Student::getdata(){
    string in_name;
    int in_age;
    int in_marks[6];
    int temp;
    cin>>in_name>>in_age;

    for(int i=0;i<6;i++){
        cin>>temp;
        in_marks[i] = temp;
    }

    input_name(in_name);
    input_age(in_age);
    input_marks(in_marks);
}

void Student::putdata(){
    int* temp = get_marks();
    int sum=0;
    for(int i=0;i<6;i++){
        sum+=temp[i];
    }
    cout<<get_name()<<" "<<get_age()<<" "<<sum<<" "<<get_cur_id()<<" "<<endl;
}

class Professor: public Person{
    private:
        int publications;
        int cur_id;
        static int id;

    public:
        Professor(){
            cur_id = ++id;
        }
        void getdata();
        void putdata();

        void input_publications(int in_publications){
            publications = in_publications;
        }

        int get_publications(){
            return publications;
        }

        int get_cur_id(){
            return cur_id;
        }
};

int Professor::id = 0;

void Professor::getdata(){
    string in_name;
    int in_age;
    int in_publications;
    cin>>in_name>>in_age>>in_publications;

    input_name(in_name);
    input_age(in_age);
    input_publications(in_publications);
}

void Professor::putdata(){
    cout<<get_name()<<" "<<get_age()<<" "<<get_publications()<<" "<<get_cur_id()<<" "<<endl;
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
