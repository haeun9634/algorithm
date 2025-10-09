#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> result;//점수

int solution(string dartResult) {
    int answer = 0;
    
    int temp=-1;
    for(int i=0; i<dartResult.size(); i++){
        if(temp==-1 && dartResult[i]>='0' && dartResult[i]<='9'){
            if(dartResult[i]=='1' && dartResult[i+1]=='0'){
                temp = 10;
                i++;
                continue;
            }
            temp = dartResult[i]-'0'; //int로 변경
                                    // cout << "i: "<<i <<"temp: "<< temp << "\n";
            continue;
        }
        switch(dartResult[i]){
            case 'D':
                temp = pow(temp,2);
                break;
            case 'T':
                temp = pow(temp,3);
                break;
            case 'S': break;
        }
        if(temp != -1){
            result.push_back(temp);
            temp = -1;
        }
        
        switch(dartResult[i]){
            case '*':
                //해당 점수와 바로 전 점수 2배
                if(result.size()!=0){
                    result[result.size()-1] *= 2;
                    if(result.size()-2>=0)
                        result[result.size()-2] *=2;
                }
                break;
            case '#':
                  if(result.size()!=0)
                    result[result.size()-1] *= -1;
                break;
        }
            
    }
    
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
        answer += result[i];
    }
    
   
    return answer;
}