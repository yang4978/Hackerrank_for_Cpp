//https://www.hackerrank.com/challenges/30-review-loop/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin>>T;
    for(int n=1;n<=T;n++){
        string S;
        cin>>S;
        string S_even="",S_odd="";
        for(int i=0;i<S.length();i++){
            if(i%2){
                S_odd+=S[i];
            }
            else{
                S_even+=S[i];
            }
        }
        cout<<S_even<<" "<<S_odd<<endl;
    }  
    return 0;
}
