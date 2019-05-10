//https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    string output[11] = {"one","two","three","four","five","six","seven","eight","nine"};
    int a,b;
    cin>>a>>b;

    for(int i=a;i<=b;i++){

      if(i<=9){
        cout<<output[i-1]<<endl;
      }

      else if(i%2){
        cout<<"odd"<<endl;  //odd number
      }
      
      else{
        cout<<"even"<<endl; //even number
      }
    }
    return 0;
}

