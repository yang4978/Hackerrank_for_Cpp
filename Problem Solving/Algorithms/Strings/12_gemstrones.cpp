//https://www.hackerrank.com/challenges/gem-stones/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
    map<char,int> dict;
    int result=0;
    for(auto word:arr){
        set<char> word_set(word.begin(),word.end());
        for(auto letter:word_set){
            ++dict[letter];
        }
    }
    for(auto iter:dict){
        if(iter.second==arr.size()){
            ++result;
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
