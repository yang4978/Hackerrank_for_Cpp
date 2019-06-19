//https://www.hackerrank.com/challenges/game-of-thrones/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    map<char,int> dict;
    int result = 0;
    for(auto i:s){
        ++dict[i];
    }
    for(auto iter:dict){
        result += iter.second%2;
    }
    return result<2?"YES":"NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
