//https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int var_int;
    long var_long;
    char var_char;
    float var_float;
    double var_double;
    scanf("%d %ld %c %f %lf",&var_int,&var_long,&var_char,&var_float,&var_double);
    printf("%d\n%ld\n%c\n%f\n%lf",var_int,var_long,var_char,var_float,var_double);
    return 0;
}
