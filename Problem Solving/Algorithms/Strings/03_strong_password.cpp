//https://www.hackerrank.com/challenges/strong-password/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    return max(6-n,4-(
        regex_search(password,regex("[0-9]"))+
        regex_search(password,regex("[a-z]"))+
        regex_search(password,regex("[A-Z]"))+
        regex_search(password,regex("[!@#$%^&*()\\-+]"))       
    )
    );

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
