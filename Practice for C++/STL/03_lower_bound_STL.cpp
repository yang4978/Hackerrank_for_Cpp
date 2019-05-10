//https://www.hackerrank.com/challenges/cpp-lower-bound/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   
    int q_num,q;
    cin>>q_num;
    for(int i=0;i<q_num;i++){
        cin>>q;
        int index =lower_bound(arr.begin(), arr.end(), q) - arr.begin(); 
        if(arr[index]==q){
            cout<<"Yes ";
        }
        else{
            cout<<"No ";
        }
        cout<<index+1<<endl;
    }
    return 0;
}
