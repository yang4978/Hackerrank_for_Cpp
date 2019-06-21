//https://www.hackerrank.com/challenges/maximum-palindromes/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'initialize' function below.
 *
 * The function accepts STRING s as parameter.
 */

static map<int,vector<long>> dict;
const long long modulo= 1000000007;
static vector<long long> mod_fact;   //factorial after modulo calculation
static vector<long long> inv_fact;   //inverse modulo of factorial, i.e. num^(p-2)

 long long calculate_power_modulo(int n, int power){
    long long result = 1;
    long long x = n%modulo;
    while(power>0){
        if(power%2==1){
            result = (result*x)%modulo;
        }
        x = (x*x)%modulo;
        power = power/2;
    }
    return result;
 }

void initialize(string s) {
    // This function is called once before all queries.
    dict[0] = vector<long>(26,0);
    for(int i=0;i<s.size();++i){
        dict[i+1] = dict[i];
        ++dict[i+1][s[i]-'a'];
    }
    mod_fact = {1,1};
    inv_fact = {1,1};
    
    for(int i=2;i<50000+1;++i){
        //factorial after modulo (a*b)%modulo = ((a%modulo)*(b%modulo))%modulo
        mod_fact.push_back(((mod_fact[i-1]%modulo)*(i%modulo))%modulo);
        //inverse factorial after modulo (a^(p-2)*b^(p-2))%modulo = ((a^(p-2)%modulo)*(b^(p-2)%modulo))%modulo
        //calculate a^(p-2)%modulo with calculate_power_modulo
        //inv_fact.push_back(((inv_fact[i-1]%modulo)*(calculate_power_modulo(i, modulo-2)%modulo))%modulo);
        inv_fact.push_back(calculate_power_modulo(mod_fact[i],modulo-2));
    }
}

/*
 * Complete the 'answerQuery' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */

int answerQuery(int l, int r) {
    // Return the answer for this query modulo 1000000007.
    vector<long> letter_num;
    for(int i=0;i<26;++i){
        letter_num.push_back(dict[r][i] - dict[l-1][i]);
    }

    long long div = 1;
    int total = 0;    //total number of usable letter pairs
    int odd = 0;   //number of single letter
    for(auto i:letter_num){
        div = 1LL*(div*inv_fact[i/2])%modulo;
        total += i/2;
        odd += i%2;
    }

    int result = 1LL*((max(1,odd)*mod_fact[total]%modulo)*(div%modulo))%modulo;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    initialize(s);

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    cout<<q<<endl;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int l = stoi(first_multiple_input[0]);

        int r = stoi(first_multiple_input[1]);

        int result = answerQuery(l, r);

        fout << result << "\n";
    }

    fout.close();

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
