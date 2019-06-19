//https://www.hackerrank.com/challenges/two-strings/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    set<char> s1_set(s1.begin(),s1.end());
    set<char> s2_set(s2.begin(),s2.end());
    for(auto i:s1_set){
        if(find(s2_set.begin(),s2_set.end(),i)!=s2_set.end()){
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
