//https://www.hackerrank.com/challenges/matrix-rotation-algo/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int r) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    for (int layer = 0; layer < min(rows, columns) / 2; ++layer) {
      int layer_r = r % (rows * 2 + columns * 2 - 4 - 8 * layer);
      while (layer_r > 0) {
            int temp = matrix[layer][columns-layer-1];
            for (int j=columns-layer-2;j>layer-1;--j){                
                swap(temp,matrix[layer][j]);
            }
            for (int i=layer+1;i<rows-layer;++i){
                swap(temp,matrix[i][layer]);
            }
            for (int j=layer+1;j<columns-layer;++j){
                swap(temp,matrix[rows-1-layer][j]);
            }
            for (int i=rows-layer-2;i>layer-1;--i){
                swap(temp,matrix[i][columns-1-layer]);
            }
        --layer_r;
      }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
