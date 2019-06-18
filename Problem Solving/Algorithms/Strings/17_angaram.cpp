//https://www.hackerrank.com/challenges/anagram/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    if(s.size()%2==1){
        return -1;
    }

    map<char,int> dict;
    int result = 0;

    for(int i=0;i<s.size()/2;++i){
        ++dict[s[i]];
        --dict[s[s.size()-1-i]];
    }

    for(auto iter:dict){
        result += abs(iter.second);
    }
    return result/2;
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

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
