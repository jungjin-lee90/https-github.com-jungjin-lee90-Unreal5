# 소스정리

    #include <string>
    #include <vector>
    
    using namespace std;
    
    int GetValue(vector<int> vCommon, bool& bMul)
    {
        int nResult[2]{0};
        int nValue = 0;
        bMul = false;
        for(int i=1; i<3; i++)
            nResult[i-1] = vCommon[i] - vCommon[i-1];
        
        nValue = nResult[0];
        for (int i=1; i<2; i++)
        {
            if (nValue == nResult[i]) // 등차
                return nValue;
            else // 등비
            {
                bMul = true;
                int j=2;
                while(true)
                {
                    if (nValue * j == nResult[i])    
                        return j;   
                    
                    j++;
                }
            }
        }
    }
    
    int solution(vector<int> common) {
        int answer = 0;
        bool bMulti;
        int nValue = GetValue(common, bMulti); 
        int nLastValue = common[common.size() - 1];
        if (bMulti)
            answer = nLastValue * nValue;         
        else
            answer = nLastValue + nValue;   
        
        return answer;
    }
