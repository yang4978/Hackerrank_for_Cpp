//https://www.hackerrank.com/challenges/queens-attack-2/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int result = 0;

    //up, up left, left, left down, down, down right, right, right up
    vector<vector<int>> main_obstacles;
    // up
    main_obstacles.push_back(vector<int>{n+1, c_q});
    // up left
    main_obstacles.push_back(vector<int>{r_q+min(n-r_q,c_q-1)+1,c_q-min(n-r_q,c_q-1)-1});
    // left
    main_obstacles.push_back(vector<int>{r_q, 0});
    //left down
    main_obstacles.push_back(vector<int>{r_q-min(r_q-1,c_q-1)-1,c_q-min(r_q-1,c_q-1)-1});
    //down
    main_obstacles.push_back(vector<int>{0, c_q});
    //down right
    main_obstacles.push_back(vector<int>{r_q-min(r_q-1,n-c_q)-1,c_q+min(r_q-1,n-c_q)+1});
    //right
    main_obstacles.push_back(vector<int>{r_q, n+1});
    //right up
    main_obstacles.push_back(vector<int>{r_q+min(n-r_q,n-c_q)+1,c_q+min(n-r_q,n-c_q)+1});

    for(auto obs: obstacles){
        // up
        if (obs[0] > r_q && obs[1] == c_q && obs[0] < main_obstacles[0][0]) {
          main_obstacles[0] = obs;
        }
        // up left
        if(obs[0]>r_q && obs[1]<c_q && obs[0]-r_q==c_q-obs[1]&& obs[0] < main_obstacles[1][0]){
            main_obstacles[1] = obs;
        }       
        // left
        if (obs[0] == r_q && obs[1] < c_q && obs[1]>main_obstacles[2][1]) {
            main_obstacles[2] = obs;
        }
        //left down
        if (obs[0] < r_q && obs[1] < c_q && r_q - obs[0] == c_q - obs[1] &&
            obs[1] > main_obstacles[3][1]) {
          main_obstacles[3] = obs;
        }
        // down
        if (obs[0] < r_q && obs[1] == c_q && obs[0] > main_obstacles[4][0]) {
            main_obstacles[4] = obs;
        }
        //down right
        if (obs[0] < r_q && obs[1] > c_q && r_q - obs[0] == obs[1]-c_q&& obs[0] > main_obstacles[5][0]) {
            main_obstacles[5] = obs;
        }
        //right
        if (obs[0] == r_q && obs[1] > c_q && obs[1] < main_obstacles[6][1]) {
          main_obstacles[6] = obs;
        }
        //right up
        if (obs[0] > r_q && obs[1] > c_q && obs[0] - r_q == obs[1] - c_q &&
            obs[1] < main_obstacles[7][1]) {
          main_obstacles[7] = obs;
        }
    }

    for(int i=0;i<=7;++i){
        if(i%2==0){
            result += max(abs(r_q-main_obstacles[i][0]),abs(c_q-main_obstacles[i][1]));
        }
        else{
            result += min(abs(r_q-main_obstacles[i][0]),abs(c_q-main_obstacles[i][1]));
        }
    }

    return result-8;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
