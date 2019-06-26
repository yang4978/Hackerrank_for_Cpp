//https://www.hackerrank.com/challenges/insertion-sort/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the insertionSort function below.
long insertionSort(vector<int> &arr) {
    long n = arr.size();

    if(n==1){
        return 0;
    }

    long n1 = n/2;
    long n2 = n-n1;

    vector<int> left(arr.begin(),arr.begin()+n1);
    vector<int> right(arr.begin()+n1,arr.end());

    long ans = insertionSort(left)+insertionSort(right);

    int l = 0;
    int r = 0;
    for(int i=0;i<n;++i){
        if(l<n1 && r<n2){
            if(left[l]<= right[r]){
                arr[i] = left[l];
                l += 1;
            }
            else{
                arr[i] = right[r];
                r += 1;
                ans += n1 - l;
            }
        }
        else if(l<n1){
            arr[i] = left[l];
            l += 1;
        }
        else{
            arr[i] = right[r];
            r += 1;
        }
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = insertionSort(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
