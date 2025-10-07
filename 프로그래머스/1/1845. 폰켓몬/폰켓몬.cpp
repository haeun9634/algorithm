#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    map<int, int> p;
    for(int i=0; i<nums.size(); i++){
        p[nums[i]] += 1;
    }
    int answer = 0;
    if(p.size()> nums.size()/2){
        answer = nums.size()/2;
    }
    else answer = p.size();
    
    return answer;
}