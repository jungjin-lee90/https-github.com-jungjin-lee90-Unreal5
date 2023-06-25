# 소스정리

    #include <string>
    #include <vector>
    
    using namespace std;
    
    int solution(vector<int> array) {
        int answer = 0;
        for(auto i : array)
        {
            string strValue = to_string(i);
            for(auto j : strValue)
            {
                if (j == '7')
                    answer++;   
            }
        }
        return answer;
    }
