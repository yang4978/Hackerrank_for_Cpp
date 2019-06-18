//https://www.hackerrank.com/challenges/the-love-letter-mystery/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the theLoveLetterMystery function below.
int theLoveLetterMystery(string s) {
    int result = 0;
    for(int i=0;i<s.size()/2;++i){
        result += abs(s[i]-s[s.size()-1-i]);
    }
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = theLoveLetterMystery(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
