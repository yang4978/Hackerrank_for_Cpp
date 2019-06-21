//大数组要在main外声明
//全局变量在静态存储区分配内存，局部变量是在栈上分配内存空间的
//c语言程序在运行时会动态创建一个堆栈段，里面存放着调用栈，保存着函数的调用关系和局部变量
//如果数组太大，可能会造成栈溢出
//https://www.hackerrank.com/challenges/common-child/copy-from/111541300

#include <bits/stdc++.h>

using namespace std;

int num_table[5001][5001];

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    int n = s1.size();

    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j){
            if(i==0 || j==0){
                num_table[i][j] = 0;
            }
            else{
                if(s1[i-1]==s2[j-1]){
                    num_table[i][j] = 1 + num_table[i-1][j-1];
                }
                else{
                    num_table[i][j] = max(num_table[i-1][j],num_table[i][j-1]);
                }
            }
        }
    }

    return num_table[n][n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;    
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
