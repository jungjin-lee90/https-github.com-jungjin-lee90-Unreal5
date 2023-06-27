# 소스정리

    #include <string>
    #include <vector>
    #include <cmath> // pow 써도됨..
    
    using namespace std;
    
    int solution(int n, int t) {
        int answer = n;
        for(int i=0; i<t; i++)
            answer = answer * 2;
        
        return answer;
    }
