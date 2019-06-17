//https://www.hackerrank.com/challenges/weighted-uniform-string/problem 

#include <bits/stdc++.h>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector<string> result;
    vector<int> num;
    int time = 1;
    for(int i=0;i<s.size();++i){
        if(i!=s.size()-1 && s[i]==s[i+1]){
            num.push_back(time * (s[i] - 'a' + 1));
            time++;
            
        }
        else{
            num.push_back(time * (s[i] - 'a' + 1));
            time = 1;
        }
    }


    for(auto i: queries){
        result.push_back(find(num.begin(),num.end(),i)!=num.end()?"Yes":"No");
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
