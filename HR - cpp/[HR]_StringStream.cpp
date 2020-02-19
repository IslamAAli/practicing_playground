#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    stringstream ss(str);
    vector<int> res; 

    bool intRead = false; 
    while (!ss.eof())
    {
        if (!intRead)
        {
            int x; 
            ss >> x; 
            res.push_back(x);
        }
        else
        {
            char c; 
            ss >> c; 
        }
        intRead = !intRead;
    }

    return res;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

