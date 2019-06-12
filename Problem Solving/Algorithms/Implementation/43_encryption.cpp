//https://www.hackerrank.com/challenges/encryption/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    string result = "";
    int num = ceil(sqrt(s.size()));
    for(int i=0;i<num;++i){
        for(int j=i;j<s.size();j+=num){
            result += s[j];
        }
        result += " ";
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
