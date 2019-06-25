//https://www.hackerrank.com/challenges/quicksort2/problem

#include <bits/stdc++.h>
using namespace std;

void quickSort(vector <int> &arr) {
    if(arr.size()<2){
        return;
    }
	int pivot = arr[0];
    vector<int> left;
    vector<int> right;
    for(auto i:arr){
        if(i<pivot){
            left.push_back(i);
        }
        if(i>pivot){
            right.push_back(i);
        }
    }

    quickSort(left);
    quickSort(right);

    int index = 0;

    for(auto i:left){
        arr[index++] = i;
        cout<<i<<" ";
    }

    cout<<pivot<<" ";
    arr[index++] = pivot;

    for(auto i:right){
        arr[index++] = i;
        cout<<i<<" ";
    }
    cout<<endl;   
}


int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}

