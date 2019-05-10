//https://www.hackerrank.com/challenges/staircase/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    for(int i=1;i<=n;i++){
        // for(int j=1;j<=n-i;j++){
        //     cout<<" ";
        // }
        // for(int j=1;j<=i;j++){
        //     cout<<"#";
        // }
        // cout<<endl;
        string s(n-i,' ');
        string p(i,'#');
        cout<<s<<p<<endl;
    }

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
