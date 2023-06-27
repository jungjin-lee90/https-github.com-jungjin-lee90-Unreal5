# 소스정리

    #include <string>
    #include <vector>
    
    using namespace std;
    
    int solution(string str1, string str2) {
        int answer = 0;
        return (str1.find(str2, 0) != string::npos) ? 1 : 2;
    }
