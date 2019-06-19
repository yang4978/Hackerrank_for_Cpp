//https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int result=0;
    for(int len=1;len<s.size();++len){     
        for(int i=0;i<=s.size()-len;++i){
            vector<int> s1(26,0);
            for(auto letter: s.substr(i,len)){
                ++s1[letter-'a'];
            }
            
            for(int j=i+1;j<=s.size()-len;++j){
                vector<int> s2(26,0);
                for(auto letter: s.substr(j,len)){
                    ++s2[letter-'a'];
                }

                if(s1==s2){
                    ++result;
                }
            }
        }
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

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
