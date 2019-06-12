//https://www.hackerrank.com/challenges/kaprekar-numbers/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    int flag = 0;
    for(long i=p;i<=q;++i){
        long mod = pow(10,(to_string(i*i).size()+1)/2);

        if(int(i*i%mod)+int(i*i/mod)==i){
            flag = 1;
            cout<<i<<" ";
        }
    }
    if(!flag){
        cout<<"INVALID RANGE";
    }

}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
