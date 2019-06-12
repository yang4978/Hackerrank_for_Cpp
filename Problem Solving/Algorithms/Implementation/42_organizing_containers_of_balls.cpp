//https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    vector<int> container_capacity;
    vector<int> ball_num;
    for(auto i:container){
        container_capacity.push_back(accumulate(i.begin(),i.end(),0));
    }
    for(int j=0;j<container[0].size();++j){
        int temp = 0;
        for(int i=0;i<container.size();++i){
            temp += container[i][j];
        }
        ball_num.push_back(temp);
    }
    sort(container_capacity.begin(), container_capacity.end());
    sort(ball_num.begin(),ball_num.end());
    return container_capacity == ball_num ? "Possible" : "Impossible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
