

#include <bits/stdc++.h>

using namespace std;

// Complete the steadyGene function below.
int steadyGene(string gene) {
    int len = gene.size();
    map<char,int> letter_dic;
    for(auto i:gene){
        ++letter_dic[i];
    }
    int G_num = letter_dic['G'] - len/4;
    int A_num = letter_dic['A'] - len/4;
    int C_num = letter_dic['C'] - len/4;
    int T_num = letter_dic['T'] - len/4;

    if(G_num==0 && A_num==0 &&C_num==0 &&T_num==0){
        return 0;
    }

    int l = 0;
    int r = (abs(G_num)+abs(A_num)+abs(C_num)+abs(T_num))/2-1;
    int result = len;

    letter_dic['G']=letter_dic['A']=letter_dic['C']=letter_dic['T']=0;

    for(auto i:gene.substr(l,r-l+1)){
        ++letter_dic[i];
    }

    while(l<=r && r<len){
        if( letter_dic['G']>=G_num && letter_dic['A']>=A_num && 
            letter_dic['C']>=C_num && letter_dic['T']>=T_num){
                result = min(result,r-l+1);
                --letter_dic[gene[l]];
                ++l;
            }

        else{
                ++r;
                ++letter_dic[gene[r]];
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

    fout << result << "\n";

    fout.close();

    return 0;
}
