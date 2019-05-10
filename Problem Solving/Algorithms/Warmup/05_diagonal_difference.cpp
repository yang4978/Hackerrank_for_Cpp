//https://www.hackerrank.com/challenges/diagonal-difference/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the diagonalDifference function below.
int diagonalDifference(vector<vector<int>> arr) {
    int n = arr.size();
    double pri_diag = 0;
    double sec_diag = 0;
    for(int i=0;i<n;i++){
        pri_diag += arr[i][i];
        sec_diag += arr[i][n-1-i];
    }
    return abs(pri_diag-sec_diag);


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
