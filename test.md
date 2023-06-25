# 소스정리

    #include <string>
    #include <vector>
    #include <regex>
    
    using namespace std;
    
    string ReturnResult(int nLength)
    {                                
        string strResult("");
        for(int i=0; i<nLength; i++)
        {
            strResult += "1";
        }
        
        return strResult;
    }
    
    int solution(vector<string> babbling) {
        int answer = 0;
        string strMatchList[4] = {"aya", "ye", "woo", "ma"};
        
        for(auto& i : babbling)
        {
            string strTest = i;
            for(auto j : strMatchList) 
            {
                /*regex re(j);
                if (std::regex_match(strTest, re))
                    answer++;*/
                
                strTest = regex_replace(strTest, regex(j), "1");
                
                if (strTest == ReturnResult(strTest.size())) 
                {
                    answer++;   
                    break;
                }
            }
            
        }
        return answer;
    }
