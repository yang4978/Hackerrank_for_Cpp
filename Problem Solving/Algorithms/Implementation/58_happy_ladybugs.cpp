//https://www.hackerrank.com/challenges/happy-ladybugs/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    map<char,int> dict;
    for(auto i : b){
        dict[i]++;
    }
    int empty = dict['_'];
    dict.erase('_');
    for(auto i:dict){
        if(i.second==1) return "NO";
    }
    if(empty>0){
        return "YES";
    }
    else{
        if(b[0]!=b[1] || b[b.size()-1]!=b[b.size()-2]){
            return "NO";
        }
        for(int i=1;i<b.size()-1;++i){
            if(b[i-1]!=b[i] && b[i]!=b[i+1]){
                return "NO";            
            }
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
