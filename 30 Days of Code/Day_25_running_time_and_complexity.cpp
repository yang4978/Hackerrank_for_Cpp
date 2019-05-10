//https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string prime_check(int num){
    if(num==1){
        return "Not prime";
    }
    for (int j = 2; j <= int(sqrt(num)); j++) {
        if (num % j == 0) {
        return "Not prime";
        }

    }
    return "Prime";
}

int main() {
    int n;
    cin>>n;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        cout<<prime_check(num)<<endl;
    }  
    return 0;
}
