//https://www.hackerrank.com/challenges/bigger-is-greater/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    string result = "no answer";
    string temp="";
    for(int i=w.size()-1;i>0;--i){
        if(w[i]>w[i-1]){
            int num = i;
            for(int j=w.size()-1;j>=i;--j){
                if(w[j]>w[i-1] && w[j]<w[num]){
                    num = j;
                }
            }
            swap(w[i-1],w[num]);
            temp = w.substr(i);
            sort(temp.begin(),temp.end());
            result = w.substr(0,i)+temp;
            break;
        }
    }
    // for(int i=w.size()-1;i>0;--i){
    //     if(w[i]>w[i-1]){
    //         result = w.substr(0,i-1);
    //         temp = w.substr(i-1);
    //         break;
    //     }
    // }
    // if(temp!=""){
    //     char head = temp[0];
    //     sort(temp.begin(),temp.end());
    //     for(int i=0;i<temp.size();i++){
    //         if(temp[i]>head){
    //           result += temp[i] + temp.substr(0, i)+temp.substr(i+1);
    //           break;
    //         }
    //     }
    // }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
