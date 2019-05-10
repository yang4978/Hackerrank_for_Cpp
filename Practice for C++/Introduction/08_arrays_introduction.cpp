//https://www.hackerrank.com/challenges/arrays-introduction/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    } 
    for(int i=n-1;i>=0;i--){
      cout<<arr[i]<<" ";
    }
    return 0;
}

/*another brilliant solution by JChiquin

int main() {
    int N,i=0;
    cin>>N;
    int *A = new int[N];
    while(std::cin>>A[i++]);
    while(std::cout<<A[--N]<<' ' && N);
    delete[] A;
    return 0;
}

*/


