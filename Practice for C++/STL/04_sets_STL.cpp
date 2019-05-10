//https://www.hackerrank.com/challenges/cpp-sets/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int n,query,num;
    set<int> s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>query>>num;
        switch(query){
            case 1: 
                s.insert(num);
                break;
            case 2: 
                s.erase(num);
                break;
            case 3: 
                cout<<(s.find(num)!=s.end()?"Yes":"No")<<endl;
                break;

        }
    }
    return 0;
}
