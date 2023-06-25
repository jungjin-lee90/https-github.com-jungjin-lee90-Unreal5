# 소스정리

    #include <string>
    #include <vector>
    
    using namespace std;
    
    int ShiftData(string strA, string strB)
    {
        string strResult{ "" };
    
        if (strA == strB)
            return 0;
    
        int j = 1;
        while (j < strA.size())
        {
            for (int i = 0; i < strA.size(); i++)
            {
                if (strA.size() - 1 == i)
                    strResult = strA[i] + strResult;
                else
                    strResult += strA[i];
            }
    
            if (strResult == strB)
                return j;
    
            strA = strResult;
            strResult = "";
    
            j++;
        }
        
        return -1;
    }
    
    int solution(string A, string B) {
        int answer = ShiftData(A, B);
        return answer;
    }
