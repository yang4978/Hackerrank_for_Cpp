//https://www.hackerrank.com/challenges/almost-sorted/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
    vector<int> arr_sort(arr);
    vector<int> num;
    sort(arr_sort.begin(),arr_sort.end());
    for(int i=0; i<arr.size();i++){
        if(arr[i]!=arr_sort[i]){
            num.push_back(i);
        }
    }

    if(num.size()==2){
        cout<<"yes"<<endl<<"swap "<<num.front()+1<<" "<<num.back()+1<<endl;
        return;
    }
    else{
        vector<int>temp (arr.begin()+num.front(),arr.begin()+num.back()+1);
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            if(temp[i]!=arr_sort[i+num.front()]){
                cout<<"no"<<endl;
                return;
            }
        }
        cout << "yes"<<endl<<"reverse " << num.front()+1 << " " << num.back()+1<< endl;
        return;
    }

}

int main()
{
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

    almostSorted(arr);

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
