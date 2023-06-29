# 소스정리

    #include <string>
    #include <vector>
    #include <cstring>
    #include <string>
    #include <sstream> // stringstream 사용하기 위해 추가
    
    using namespace std;
    
    void ExampleStringStream()
    {
        stringstream ss;
        vector<string> vStr, vResult;
        vStr.push_back("1 + 2 = 3");
        vStr.push_back("2+7=2");
        int nA, nB, nResult, nRealResult = 0;
        char strOP, strOP2;
    
        for (auto i : vStr)
        {
            ss.str(i);
            ss >> nA;
            ss >> strOP;
            ss >> nB;
            ss >> strOP2;
            ss >> nResult;
    
            switch (strOP)
            {
            case '+':
                nRealResult = nA + nB;
                break;
    
            case '-':
                nRealResult = nA - nB;
                break;
            }
    
            if (nRealResult == nResult)
                cout << i << " result = " << "O" << endl;
            else
                cout << i << " result = " << "X" << endl;
    
            ss.clear();
        }
    }

