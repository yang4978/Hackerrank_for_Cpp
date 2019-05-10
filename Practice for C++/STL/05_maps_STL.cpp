//https://www.hackerrank.com/challenges/cpp-maps/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int n,query,marks;
    string name;

    map<string,int> m;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>query;
        cin>>name;
        switch(query){
            case 1:
                cin>>marks;
                m[name] = (m.find(name)!=m.end()?m[name]:0)+marks;
                //default value of map value is 0, so it's also ok to use following code
                //m[name]+=marks;
                break;
            case 2:
                m.erase(name);
                break;
            case 3:
                cout<<(m.find(name)!=m.end()?m[name]:0)<<endl;
                break;             
        }
    }

    return 0;
}



