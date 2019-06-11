//https://www.hackerrank.com/challenges/append-and-delete/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    int same = 0;
    for(int i=0;i<min(s.size(),t.size());++i){
        if(s[i]==t[i]) ++same;
        else break;
    }
    int time = s.size()+t.size()-2*same;
    if((k>=time && (k-time)%2==0) || k>=s.size()+t.size()) return "Yes";
    else return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
