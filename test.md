# 소스정리

    #include <string>
    #include <vector>
    
    using namespace std;
    
    int solution(vector<int> array) {
        int answer = 1, nMax = 0;
        int nCount[1000]{ 0 };
        if (array.size() == 1)
            return array[0];
        else
        {
            for (int i = 0; i < array.size(); i++)
            {
                nCount[array[i]]++;
                if (nMax < nCount[array[i]]) 
                {
                    nMax = nCount[array[i]]; // 몇번 나왔나
                    answer = array[i]; // 최빈값
                }
                else if(nMax == nCount[array[i]])
                    answer = -1;
            }
                
        }
    
        return answer;
    }
