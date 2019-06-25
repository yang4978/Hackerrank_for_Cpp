//https://www.hackerrank.com/challenges/quicksort3/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find_seg_point(vector <int> &arr,int start, int end){
    int seg_point = start;
    for(int i=start;i<end;++i){
        if(arr[i]<=arr[end]){
            swap(arr[i],arr[seg_point]);
            ++seg_point;
        }
    }
    swap(arr[end],arr[seg_point]);
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return seg_point;
}

void quick_sort(vector <int> &arr,int start, int end) {
    if(start<end){
        int seg_point = find_seg_point(arr,start,end);
        quick_sort(arr, start, seg_point-1);
        quick_sort(arr, seg_point+1, end);
    }
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quick_sort(arr,0,n-1);

    return 0;
}
