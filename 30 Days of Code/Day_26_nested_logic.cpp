//https://www.hackerrank.com/challenges/30-nested-logic/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int d_a,m_a,y_a;
    int d_e,m_e,y_e;
    cin>>d_a>>m_a>>y_a;
    cin>>d_e>>m_e>>y_e;
    cout<<((y_a-y_e)>0)*10000+((y_a-y_e)==0)*max(m_a-m_e,0)*500+((y_a-y_e)==0)*((m_a-m_e)==0)*max(d_a-d_e,0)*15<<endl;
    return 0;
}
