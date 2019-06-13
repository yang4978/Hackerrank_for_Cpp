//https://www.hackerrank.com/challenges/the-time-in-words/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    string result="";

    string hours[] = {"one",   "two",   "three", "four", "five",   "six",
                   "seven", "eight", "nine",  "ten",  "eleven", "twelve"};

    string minutes[] = {
      "one",         "two",        "three",        "four",
      "five",        "six",        "seven",        "eight",
      "nine",        "ten",        "eleven",       "twelve",
      "thirteen",    "fourteen",   "fifteen",      "sixteen",
      "seventeen",   "eighteen",   "ninteen",      "twenty",
      "twenty one",  "twenty two", "twenty three", "twenty four",
      "twenty five", "twenty six", "twenty seven", "twenty eight",
      "twenty nine"};

  string hour;

    if (m == 0) {
        hour = hours[h - 1];
        result = hour+" o' clock";

    } else if (m == 1) {
        hour = hours[h - 1];
        result ="one minute past "+ hour;
    } else if (m == 15) {
        hour = hours[h - 1];
        result = "quarter past "+hour;
    } else if (m == 30) {
        hour = hours[h - 1];
        result ="half past "+hour;
    } else if (m == 45) {
        hour = hours[h];
        result = "quarter to "+hour;
    } else if (m < 30) {
        hour = hours[h - 1];
        result = minutes[m - 1]+" minutes past "+hour;
    } else if (m > 30) {
        hour = hours[h];
        result = minutes[60 - m - 1]+" minutes to "+hour;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
