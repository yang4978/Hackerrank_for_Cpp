//https://www.hackerrank.com/challenges/palindrome-index/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the palindromeIndex function below.

int palindromeIndex(string s) {
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]==s[j]){
            ++i;
            --j;
        }
        else{
            int flag = 0;
            int k = j-1;
            while(i<k){
                if(s[i]!=s[k]){
                    flag = 1;
                    break;
                }
                ++i;
                --k;
            }
            return flag==0?j:s.size()-j-1;
        }
    }
    return -1;
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

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
