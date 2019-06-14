//https://www.hackerrank.com/challenges/bomber-man/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string> grid) {
  int rows = grid.size();
  int columns = grid[0].size();
  if (n == 1) {
        return grid;
  } 
  else if (n % 2 == 0) {
        for(int i=0;i<rows;++i){
            for(int j=0;j<columns;++j){
                grid[i][j] = 'O';
            }
        }
        return grid;
  } 
  else{
    n = 1+(n+1)/2%2;
    map<vector<int>,char> dict_grid;
    
    while(n>0){
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
          dict_grid[vector<int>{i, j}] = 'O';
        }
      }

      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
          if (grid[i][j] == 'O'){
            dict_grid[vector<int>{i, j}] = '.';
            if(i>0){
                dict_grid[vector<int>{i - 1, j}] = '.';
            }
            if(i<rows-1){
                dict_grid[vector<int>{i + 1, j}] = '.';
            }
            if(j>0){
                dict_grid[vector<int>{i, j - 1}] = '.';
            }
            if(j<columns-1){
                dict_grid[vector<int>{i, j + 1}] = '.';
            }
          }
        }
      }

      for (auto item : dict_grid) {
        grid[item.first[0]][item.first[1]] = item.second;
      }

      n -= 1;
    }
  }
    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
