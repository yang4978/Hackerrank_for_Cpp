//https://www.hackerrank.com/challenges/repeated-string/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    return n/s.size()*1.0L*count(s.begin(),s.end(),'a')+1.0L*count(s.begin(),s.begin()+n%s.size(),'a');

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
