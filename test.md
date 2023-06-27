# 소스정리

    #include <string>
    #include <vector>
    #include <cmath>
    
    using namespace std;
    
    int solution(int n) {
        int answer = 0;
        int temp = sqrt(n);
        return (temp * temp == n) ? 1 : 2;
    }
