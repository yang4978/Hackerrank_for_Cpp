//https://www.hackerrank.com/challenges/mars-exploration/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the marsExploration function below.
int marsExploration(string s) {
    int result = 0;
    for(int i=0;i<s.size();i+=3){
        result += (s[i]!='S')+(s[i+1]!='O')+(s[i+2]!='S');
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
