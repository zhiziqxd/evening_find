#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;
struct website{
    string name;
    string url;
};
vector<website> list;
map<string,bool> mapp;
void init(){
    freopen("\text\list.in","r",stdin);
    string str,str2;
    while(cin>>str>>str2){
        website flag;
        flag.name=str;
        flag.url=str;//保证可以存入网站列表
        list.push_back(flag);
    }
    freopen("CON","r",stdin);
    return;
}
void map_init(){//提取搜索关键信息
  mapp["the"]=true;
  mapp["be"]=true;
  mapp["to"]=true;
  mapp["of"]=true;
  mapp["and"]=true;
  mapp["do"]=true;
  mapp["at"]=true;
  mapp["?"]=true;
  mapp["!"]=true;
  mapp["."]=true;
  mapp[","]=true;//本列表欢迎补充!
}
int main(){
    init();
    map_init();
    string str;
    getline(cin,str);
    string word="",find_str="";
    for(int i=0;i<str.length();i++){//提取关键
        if(str[i]!=' '){
            word+=str[i];
        }
        else{
            if(mapp[word]==false){
                find_str+=word+" ";
                word="";//清零
            }
        }
    }
    find(list,find_str);//在另一个文件,find.cpp中
    return 0;
}