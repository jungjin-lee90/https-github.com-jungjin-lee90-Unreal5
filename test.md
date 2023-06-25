# 소스정리

    #include <string>
    #include <vector>
    
    using namespace std;
    
    int CalcTotal(int num, int nValue, int nCount, int nSum)
    {
        if (nCount == num)
            return nSum;
        else
        {
            nCount++;
            nSum += nValue;
            return CalcTotal(num, nValue + 1, nCount, nSum);
        }
    }
    
    vector<int> solution(int num, int total) {
        vector<int> answer;
        int nAnswer, nFindValue;
        int i = -100;
        while(true)
        {
            nFindValue = CalcTotal(num, i, 0, 0);
            nAnswer = i;
            if (total == nFindValue)
            {
                for (int i = nAnswer; i < nAnswer + num; i++)
                    answer.push_back(i);
    
                break;
            } 
            i++;
        }
    
        return answer;
    }
