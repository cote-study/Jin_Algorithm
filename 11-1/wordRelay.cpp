#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


bool relay(string a, string b){
    char aLast = a[a.length()-1];
    char bFirst = b[0];
    return (aLast==bFirst);
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string,bool> m;
    
    int index=0;
    int wrongNum=-1;
    int wrongNumCnt=-1;
    m[words[0]] = true;
    string temp=words[0];
    
    for(int i=1;i<words.size();i++){
        string f = words[i];
        
        if(relay(temp,f) && m[f] == false){
            temp = f;
            m[temp] = true;
        }
        else{
            wrongNum = i%n;
            wrongNumCnt = i/n;
            break;
        }
    }
    if(wrongNum==-1 && wrongNumCnt==-1){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(wrongNum+1);
        answer.push_back(wrongNumCnt+1);
    }

    return answer;
}