//https://www.hackerrank.com/challenges/pangrams/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    for(int i=0;i<s.size();++i){
        if(s[i]>='A' && s[i]<='Z'){
            s[i] -= 'A'-'a';
        }
    }
    set<char> letter(s.begin(),s.end());
    return letter.size() == 27 ? "pangram" : "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
