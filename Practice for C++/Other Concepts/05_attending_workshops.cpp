//https://www.hackerrank.com/challenges/attending-workshops/problem

#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshops{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops{
    int n;
    vector<Workshops> ws;
};

Available_Workshops* initialize(int*start_time_list, int*duration_list,int n){
  Available_Workshops *result = new Available_Workshops();
  result->n = n;

  for (int i = 0; i < n; i++) {
    Workshops temp;
    temp.start_time = start_time_list[i];
    temp.duration = duration_list[i];
    temp.end_time = start_time_list[i] + duration_list[i];
    result->ws.push_back(temp);
    }
    return result;
}

bool compare(Workshops w1, Workshops w2) { 
    return (w1.end_time < w2.end_time);
}

int CalculateMaxWorkshops(Available_Workshops *ptr){
    sort(ptr->ws.begin(),ptr->ws.end(),compare);

    int result = 0;
    int temp_end_time=-1;
    for(auto i:ptr->ws){
        if(i.start_time>=temp_end_time){
            ++result;
            temp_end_time = i.end_time;
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
