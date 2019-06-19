//https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    map<char,int> dict;
    for(auto i:s){
        ++dict[i];
    }
    map<int,int> result;
    for(auto iter:dict){
        ++result[iter.second];
    }    

    if(result.size()==1)return "YES";
    else if(result.size()>2) return "NO";
    else{
            map<int,int>::iterator iter = result.begin();
            map<int,int>::iterator end = (--result.end());
            if((iter->second==1 && (iter->first-end->first==1 || iter->first==1))
            || (end->second==1 && (end->first-iter->first==1 || end->first==1))){
                return "YES";
            }
            else{
                return "NO";
                }
        }
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
