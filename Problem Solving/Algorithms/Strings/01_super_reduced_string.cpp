//https://www.hackerrank.com/challenges/reduced-string/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    string pattern = "([a-z])\\1";
    regex express(pattern);
    string substitutes = "";

    while (regex_search(s, express)) {
        s = regex_replace(s, express, substitutes);    
    }
    if(s==""){
        s = "Empty String";
    }
    return s;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
