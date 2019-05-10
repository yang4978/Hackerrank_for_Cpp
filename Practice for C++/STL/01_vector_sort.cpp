//https://www.hackerrank.com/challenges/vector-sort/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    int temp;
    vector<int> vec;

    for(int i=0;i<n;i++){
        cin>>temp;
        vec.push_back(temp);
    }   
    sort(vec.begin(),vec.end());
    
    vector<int>::iterator iter=vec.begin();
    while(iter!=vec.end()){
        cout<<*iter<<" ";
        iter++;
    }
    
    return 0;
}
