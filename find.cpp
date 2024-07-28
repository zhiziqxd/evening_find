#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
using namespace std;
struct website{
    string name;
    string url;
};
string word[1010];
int cnt;
void word_init(string str){//分解为单词
    string wflag="";
    for(int i=0;i<str.length();i++){
        if(str[i]!=' '){
            wflag+=str[i];
        }
        else{
            cnt++;
            word[cnt]=wflag;
            wflag="";
        }
    }
}
void find(vector<website> list,string str){
    bool flag=false;
    word_init(str);
    for(int i=0;i<list.size();i++){
        for(int j=1;j<=cnt;j++){
            if(list[i].name.find(word[j])<=list[i].name.length()){//如果有单词的话
                flag=true;
                cout<<list[i].name<<endl;
                cout<<list[i].url<<endl;
                cout<<endl;//美观
            }
        }
    }
    if(!flag){
        cout<<"error"<<endl;
    }
    return;
}
