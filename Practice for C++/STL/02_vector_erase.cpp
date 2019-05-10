//https://www.hackerrank.com/challenges/vector-erase/problem

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

    int index;
    cin>>index;

    int del_begin,del_end;
    cin>>del_begin>>del_end;

    arr.erase(arr.begin()+index-1);
    arr.erase(arr.begin()+del_begin-1,arr.begin()+del_end-1);

    cout<<arr.size()<<endl;
    
    // vector<int>::iterator iter=arr.begin();
    // while(iter!=arr.end()){
    //     cout<<*iter<<" ";
    //     iter++;
    // }
    
    for(auto _arr:arr){
        cout<<_arr<<" ";
    }
    cout<<endl;

    return 0;
}
