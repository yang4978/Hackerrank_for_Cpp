//https://www.hackerrank.com/challenges/variable-sized-arrays/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,q,temp_col;
    cin>>n>>q;
    int **p = new int*[n];
    for(int i=0;i<n;i++){
      cin>>temp_col;
      p[i] = new int[temp_col];
      for(int j=0;j<temp_col;j++){
        cin>>p[i][j];
      }
    }
    int q_i,q_j;
    for(int queries=0;queries<q;queries++){
      cin>>q_i>>q_j;
      cout<<p[q_i][q_j]<<endl;
    }
   
    for(int i=0;i<n;i++){
      delete[] p[i];
    }
    delete[] p;

    return 0;
}

