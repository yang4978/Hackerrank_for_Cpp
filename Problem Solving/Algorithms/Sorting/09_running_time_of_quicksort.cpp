//https://www.hackerrank.com/challenges/quicksort4/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int shift_count = 0;
int swap_count = 0;

void insertion_sort(vector<int> &arr){
    for(int i=1;i<arr.size();++i){
        int num = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j]>num){
            arr[j+1] = arr[j];
            --j;
            ++shift_count;
        }
        arr[j+1] = num;
    }
}

int find_pivot_index(vector<int> &arr, int start, int end){
    int idx = start;
    for(int i=start;i<end;++i){
        if(arr[i]<=arr[end]){
            swap(arr[i],arr[idx]);
            ++idx;
            ++swap_count;
        }
    }
    swap(arr[idx],arr[end]);
    ++swap_count;
    return idx;
}

void quick_sort(vector<int> &arr, int start, int end){
    if(start<end){
        int idx = find_pivot_index(arr,start,end);
        quick_sort(arr, start, idx-1);
        quick_sort(arr, idx+1, end);
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> arr_insert(n);
    for(int i=0;i<n;++i){
        cin>>arr_insert[i];
    }
    vector<int> arr_quick = arr_insert;

    insertion_sort(arr_insert);
    quick_sort(arr_quick,0,n-1);

    cout<<shift_count-swap_count<<endl;
    
    return 0;
}
