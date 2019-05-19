//https://www.hackerrank.com/challenges/magic-square-forming/problem

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> calculateAllMagicSqure() {
  vector<int> num;
  for (int i = 1; i < 10; i++) {
    num.push_back(i);
  }

  vector<int> arr;
  vector<vector<int>> arr_list;

  for (auto i_1 : num) {
    arr.push_back(i_1);
    for (auto i_2 : num) {
      if (i_2 == i_1)
        continue;
      arr.push_back(i_2);
      for (auto i_3 : num) {
        if ((i_1 + i_2 + i_3) != 15 or i_3 == i_1 or i_3 == i_2)
          continue;
        arr.push_back(i_3);
        for (auto i_4 : num) {
          if (i_4 == i_1 or i_4 == i_2 or i_4 == i_3)
            continue;
          arr.push_back(i_4);
          for (auto i_5 : num) {
            if (i_5 == i_1 or i_5 == i_2 or i_5 == i_3 or i_5 == i_4)
              continue;
            arr.push_back(i_5);
            for (auto i_6 : num) {
              if ((i_4 + i_5 + i_6) != 15 or i_6 == i_1 or i_6 == i_2 or
                  i_6 == i_3 or i_6 == i_4 or i_6 == i_5)
                continue;
              arr.push_back(i_6);
              for (auto i_7 : num) {
                if ((i_1 + i_4 + i_7) != 15 or (i_3 + i_5 + i_7) != 15 or
                    i_7 == i_1 or i_7 == i_2 or i_7 == i_3 or i_7 == i_4 or
                    i_7 == i_5 or i_7 == i_6)
                  continue;
                arr.push_back(i_7);
                for (auto i_8 : num) {
                  if ((i_2 + i_5 + i_8) != 15 or i_8 == i_1 or i_8 == i_2 or
                      i_8 == i_3 or i_8 == i_4 or i_8 == i_5 or i_8 == i_6 or
                      i_8 == i_7)
                    continue;
                  arr.push_back(i_8);
                  for (auto i_9 : num) {
                    if (((i_3 + i_6 + i_9) != 15) or
                        ((i_7 + i_8 + i_9) != 15) or
                        ((i_1 + i_5 + i_9) != 15) or i_9 == i_1 or i_9 == i_2 or
                        i_9 == i_3 or i_9 == i_4 or i_9 == i_5 or i_9 == i_6 or
                        i_9 == i_7 or i_9 == i_8)
                      continue;
                    arr.push_back(i_9);
                    arr_list.push_back(arr);
                    arr.pop_back();
                  }
                  arr.pop_back();
                }
                arr.pop_back();
              }
              arr.pop_back();
            }
            arr.pop_back();
          }
          arr.pop_back();
        }
        arr.pop_back();
      }
      arr.pop_back();
    }
    arr.pop_back();
  }
  return arr_list;
}

int formingMagicSquare(vector<vector<int>> s) {
  int min_sum = 100;
  vector<int> s_flatten;

  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j < s[0].size(); ++j) {
      s_flatten.push_back(s[i][j]);
    }
  }

  vector<vector<int>> arr_list = calculateAllMagicSqure();
  for (auto arr : arr_list) {
    int sum = 0;
    for (int i = 0; i < s_flatten.size(); ++i) {
      sum += abs(s_flatten[i] - arr[i]);
    }
    min_sum = sum < min_sum ? sum : min_sum;
  }
  return min_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
