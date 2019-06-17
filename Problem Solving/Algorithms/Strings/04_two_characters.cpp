//https://www.hackerrank.com/challenges/two-characters/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
int alternate(string s) {
  set<char> letter(s.begin(), s.end());
  int result = 0;
  for (auto i : letter) {
    for (auto j : letter) {
      string temp = s;
      if (i != j) {
        for (auto k : letter) {
            string::size_type pos(0);
            while (k != i && k != j && (pos = temp.find(k)) != string::npos) {
                temp.replace(pos, 1, "");
            }
        }
        if (regex_search(temp, regex("([a-z])\\1")) == false) {
            result = max(result, int(temp.size()));
        }
      }
    }
  }
  return result;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string l_temp;
  getline(cin, l_temp);

  int l = stoi(ltrim(rtrim(l_temp)));

  string s;
  getline(cin, s);

  int result = alternate(s);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
