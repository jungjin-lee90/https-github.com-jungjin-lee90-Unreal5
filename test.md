# 소스정리

    #include <string>
    #include <vector>
    #include <cstring>
    #include <string>
    
    using namespace std;
    
    vector<string> split(string str, string div)
    {
        vector<string> vStr;
        int nStart = 0;
        int nEnd = str.find(div);
        while(nEnd != -1)
        {
            vStr.push_back(str.substr(nStart, nEnd - nStart));
            nStart = nEnd + 1;
            nEnd = str.find(div, nStart);
        }
        vStr.push_back(str.substr(nStart, nEnd - nStart));
        return vStr;
    }
    
    vector<string> solution(vector<string> quiz) {
        vector<string> answer, strResultList;
        for(auto i : quiz)
        {
            bool bPlus = false;
            int nA, nB, nResult;
            strResultList = split(i, " ");
            for(int j = 0; j < strResultList.size(); j++)          
            {
                switch(j)
                {
                    case 0: 
                        nA = stoi(strResultList[j]);
                        break;
                        
                    case 1:
                        bPlus = strResultList[j] == "+";
                        break;
                        
                    case 2:
                        nB = stoi(strResultList[j]);
                        break;
                        
                    case 4:
                        nResult = stoi(strResultList[j]);
                        break;  
                }
            }
            
            if (bPlus)
            {
                if (nA + nB == nResult)
                    answer.push_back("O");    
                else
                    answer.push_back("X");    
            }
            else
            {
                if (nA - nB == nResult)
                    answer.push_back("O");    
                else
                    answer.push_back("X");    
            }
        }
        return answer;
    }
