//https://www.hackerrank.com/challenges/classes-objects/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
#include <numeric>

class Student{
    private:
        vector<int> score;
    
    public:
        void input(){
            int eval;
            while(score.size()<5){
                cin>>eval;
                score.push_back(eval);
            }
        }

    
        int calculateTotalScore(){
            int sum=accumulate(score.begin(),score.end(),0);
            return sum;
    }
};

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
