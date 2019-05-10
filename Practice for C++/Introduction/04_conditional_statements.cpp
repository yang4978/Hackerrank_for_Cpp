//https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string eng_of_num[10] = {"Greater than 9","one","two","three","four","five","six","seven","eight","nine"};

    if(n>9){
      cout<<eng_of_num[0]<<endl;
    }
    else{
      cout<<eng_of_num[n]<<endl;
    }

    return 0;
}
