//https://www.hackerrank.com/challenges/extra-long-factorials/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    vector<int> result(200,0);
    result[0] = 1;
    int modulo;
    int k = 1;
    for(int i=1;i<=n;++i){
        modulo = 0;
        for(int j=0;j<k;++j){
            result[j] = result[j]*i+modulo;
            modulo = result[j]/10;
            result[j] %= 10;
        }
        while(modulo>0){
            ++k;
            result[k-1] = modulo%10;
            modulo/=10;
        }
    }
    for (int i = k - 1; i >= 0; --i) {
      cout << result[i];
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
