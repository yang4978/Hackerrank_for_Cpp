//https://www.hackerrank.com/challenges/attribute-parser/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


int main() {
    map<string, string> tag_map;
    
    int n,q;
    cin>>n>>q;
    string tag_temp="";

    for(int i=0;i<n;i++){
        string line="";
        while (line == ""){
        getline(cin, line);}
        string tag="",attri="",value="";
        if(line[1]=='/'){
            int i = 2;
            while(line[i]!='>'){
                i++;
            }
            tag = line.substr(2,i-1);
            if(tag_temp.size()>tag.size()){
                tag_temp = tag_temp.substr(0,tag_temp.size()-tag.size());
            }
            else{
                tag_temp = "";
            }
        }
        else{
            int i = 1;
            while (line[i] != ' ' & line[i] !='>') {
                i++;
            }
            int tag_pos = i;
            tag = line.substr(1,tag_pos-1);
            if(tag_temp!=""){
                tag_temp += ("."+tag);
            }
            else{
                tag_temp = tag;
            }

            int value_pos_end = tag_pos;
            int value_pos_begin;
            int attri_pos;

            while(line[i]!='>'){
                if(line[i]==' '){
                    value_pos_end = i;
                    i++;
                }
                while(line[i]!=' '){
                    i++;
                }
                attri = line.substr(value_pos_end+1,i-value_pos_end-1);
                while(line[i]!='"'){
                    i++;
                }
                i++;
                value_pos_begin = i;
                while(line[i]!='"'){
                    i++;
                }
                value_pos_end = i;
                value = line.substr(value_pos_begin,value_pos_end-value_pos_begin);
                tag_map[tag_temp+'~'+attri] = value;
                i++;
            }
        }
    }

    // output the entire map
    // map<string,string>::iterator iter=tag_map.begin();
    // while(iter!=tag_map.end()){
    //     cout<<iter->first<<":"<<iter->second<<endl;
    //     iter++;
    // }

    
    for(int query=0;query<q;query++){
        string key;
        cin>>key;
        if(tag_map.count(key)){
            cout<<tag_map[key]<<endl;
        }
        else{
            cout<<"Not Found!"<<endl;
        }
    }
    

    return 0;
}
