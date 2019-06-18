//https://www.hackerrank.com/challenges/separate-the-numbers/problem separate_the_numbers

#include <bits/stdc++.h>

using namespace std;

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    if (s.size() == 1 || s[0] == '0') {
        cout<<"NO"<<endl;
        return;
    }
    else{
        for(int i=1;i<s.size();++i){
            string temp = s.substr(0,i);
            stringstream ss(temp);
            long num;
            ss>>num;
            while(temp.size()<s.size()){
                ++num;
                temp += to_string(num);
            }
            if(temp==s){
              cout << "YES " << s.substr(0, i) << endl;
              return;
            }
        }
        cout<<"NO"<<endl;
        return;
    }
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);
        separateNumbers(s);
    }

    return 0;
}
