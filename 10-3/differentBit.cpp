#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]%2==0)answer.push_back(numbers[i]+1);
        else{
            long long temp =1;
            while(1){
                if((numbers[i] & temp) == 0) break;
                temp<<=1;
            }
            temp>>=1;
            answer.push_back(numbers[i]+temp);
        }
    }
    
    return answer;
}