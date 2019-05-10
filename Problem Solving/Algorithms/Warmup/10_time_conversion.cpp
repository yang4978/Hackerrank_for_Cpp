//https://www.hackerrank.com/challenges/time-conversion/problem

#include <bits/stdc++.h>

using namespace std;


string timeConversion(string s) {
    /*
    string time = s.substr(0,s.size()-2);
    if(s[s.size()-2]=='A' & s.substr(0,2)=="12"){
        time.replace(0,2,"00");
    }
    if(s[s.size()-2]=='P' & s.substr(0,2)!="12"){
        stringstream ss;
        ss<<s.substr(0,2);
        int number;
        ss>>number;
        time.replace(0,2,string(to_string(number+12)));
    }
    return time;
    */
    
    int n = s.length();
    int hh, mm, ss;
    hh = (s[0] - '0') * 10 + (s[1] - '0');
    mm = (s[3] - '0') * 10 + (s[4] - '0');
    ss = (s[6] - '0') * 10 + (s[7] - '0');

    if (hh < 12 && s[8] == 'P') hh += 12;
    if (hh == 12 && s[8] == 'A') hh = 0;

    printf("%02d:%02d:%02d\n", hh, mm, ss);

    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
