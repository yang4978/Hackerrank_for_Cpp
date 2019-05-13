https://www.hackerrank.com/challenges/attribute-parser/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>

using namespace std;


int main() {
    map<string, string> tag_map;

    int n,q;
    cin>>n>>q;
    cin.ignore();
    string tag_temp="";

    for(int i=0;i<n;i++){
        string line;
        getline(cin, line);
        string word,tag="",attri="",value="";
        stringstream ss(line);
        int pos;

        while(getline(ss,word,' ')){
            if(word[0]=='<'){
                if(word[1]!='/'){
                  tag = word.substr(1);
                    if (word[word.size() - 1] == '>') {
                        tag = tag.substr(0,tag.size()-1);
                    }
                    
                    if(tag_temp==""){
                        tag_temp = tag;
                    }
                    else{
                        tag_temp += "."+tag;
                    }
                }
                else{
                    tag = word.substr(2,word.size()-3);
                    pos = tag_temp.find(tag);
                    if(pos){
                        tag_temp = tag_temp.substr(0,pos-1);
                    }
                    else{
                        tag_temp = "";
                    }
                }
            }

            else if(word[0]!='=' & word[0]!='"'){
                attri = word;
            }

            else if(word[0]=='"'){
                pos = word.find_last_of('"');
                value = word.substr(1,pos-1);
                tag_map[tag_temp + '~' + attri] = value;
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
