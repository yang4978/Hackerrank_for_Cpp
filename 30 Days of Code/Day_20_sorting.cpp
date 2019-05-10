//https://www.hackerrank.com/challenges/30-sorting/problem

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
    	cin >> a[a_i];
    }
    int swap_num = 0;
    int temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
                // temp = a[i];
                // a[i] = a[j];
                // a[j] = temp;
                swap_num++;
            }
        }
    }
    cout<<"Array is sorted in "<<swap_num<<" swaps."<<endl;
    cout<<"First Element: "<<a[0]<<endl;
    cout<<"Last Element: "<<a[n-1]<<endl;
    return 0;
}
