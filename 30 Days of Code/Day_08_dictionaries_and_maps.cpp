//https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int n;
    cin>>n;
    map<string,string> phoneBook;
    for (int i=1;i<=n;i++){
        string name,number;
        cin>>name>>number;
        phoneBook[name] = number;
    }  
    string val;
    while(cin>>val){
        if(phoneBook.count(val)){
            cout<<val<<"="<<phoneBook[val]<<endl;
        }
        else{
            cout<<"Not found"<<endl;
        }
    }
    return 0;
}

