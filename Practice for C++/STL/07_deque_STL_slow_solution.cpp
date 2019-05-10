//https://www.hackerrank.com/challenges/deque-stl/problem?h_r=next-challenge&h_v=zen

//quite slow solution

#include <iostream>
#include <deque> 
#include <algorithm>
using namespace std;

void printKMax(int arr[], int n, int k){
    deque<int> dq;
    int max = 0;
    for(int i=0;i<k;i++){
        dq.push_back(arr[i]);
        max = (max<arr[i]?arr[i]:max);
    }
    
    for (int i=0;i<n-k+1;i++) {
        cout <<max<< " ";
        int pop_value = *dq.begin();
        dq.pop_front();
        dq.push_back(arr[k + i]);
        if(arr[k+i]>max){
            max = arr[k+i];
        }
        else if(pop_value==max){
            max = *max_element(dq.begin(), dq.end()) ;
        }
      
    }
    cout<<endl;

}

int main(){
  
    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
              cin >> arr[i];
        printKMax(arr, n, k);
        t--;
      }
      return 0;
}

