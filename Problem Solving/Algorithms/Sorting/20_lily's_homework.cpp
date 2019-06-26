//https://www.hackerrank.com/challenges/lilys-homework/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the lilysHomework function below.
int lilysHomework(vector<int> arr) {
    int n = arr.size();
    map<int,int> dict;

    vector<int> re_arr(arr.begin(),arr.end());

    vector<int> sorted_arr(arr.begin(),arr.end());
    sort(sorted_arr.begin(),sorted_arr.end());
    
    vector<int> re_sorted_arr(sorted_arr.begin(),sorted_arr.end());
    reverse(re_sorted_arr.begin(),re_sorted_arr.end());

    for(int i=0;i<n;++i){
        dict[arr[i]] = i;
    }

    map<int,int> re_dict(dict.begin(),dict.end());

    int num=0;
    int re_num = 0;

    for(int i=0;i<n;++i){
        if(arr[i]!=sorted_arr[i]){
            arr[dict[sorted_arr[i]]] = arr[i];
            dict[arr[i]] = dict[sorted_arr[i]];
            arr[i] = sorted_arr[i];
            ++num;
        }

        if(re_arr[i]!=re_sorted_arr[i]){
            re_arr[re_dict[re_sorted_arr[i]]] = re_arr[i];
            re_dict[re_arr[i]] = re_dict[re_sorted_arr[i]];
            re_arr[i] = re_sorted_arr[i];
            ++re_num;
        }
    }

    return min(num,re_num);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    int result = lilysHomework(arr);

    fout << result << "\n";

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
