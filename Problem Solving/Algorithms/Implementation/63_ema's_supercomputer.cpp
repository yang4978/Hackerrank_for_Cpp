//https://www.hackerrank.com/challenges/two-pluses/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the twoPluses function below.
int twoPluses(vector<string> grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= m; y++) {
        int r = 0;
        while (r <= x && r <= y && r <= n - 1 - x && r <= m - 1 - y &&
               grid[x + r][y] == 'G' && grid[x - r][y] == 'G' &&
               grid[x][y + r] == 'G' && grid[x][y - r] == 'G') {
          grid[x + r][y] = grid[x - r][y] = grid[x][y + r] = grid[x][y - r] = 'g';
          for (int X = 1; X <= n; X++) {
            for (int Y = 1; Y <= m; Y++) {
              int R = 0;
              while (R<=X && R<=Y && R<=n-1-X && R<=m-1-Y &&
                    grid[X + R][Y] == 'G' && grid[X - R][Y] == 'G' &&
                    grid[X][Y + R] == 'G' && grid[X][Y - R] == 'G'
                      ) {
                ans = max(ans, (1 + 4 * r) * (1 + 4 * R));
                R++;
              }
            }
          }
          r++;
        }
        r = 0;
        while (r <= x && r <= y && r <= n - 1 - x && r <= m - 1 - y &&
               grid[x + r][y] == 'g' && grid[x - r][y] == 'g' &&
               grid[x][y + r] == 'g' && grid[x][y - r] == 'g') {
          grid[x + r][y] = grid[x - r][y] = grid[x][y + r] = grid[x][y - r] = 'G';
          r++;
        }
      }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

    fout << result << "\n";

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
