//https://www.hackerrank.com/challenges/30-binary-numbers/problem

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int max_num = 0;
    int temp = 0;
    while(n){
        if(n%2==1){
            temp += 1;
        }
        else{
            temp = 0;
        }
        if (max_num < temp) {
            max_num = temp;
        }
        n/=2;
    }
    cout<<max_num<<endl;
    return 0;
}
