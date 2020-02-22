#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int input, inputSize; 
    vector<int> vals; 
    cin >> inputSize;

    for(int i=0; i<inputSize; i++)
    {
        cin >> input; 
        vals.push_back(input);
    }

    sort(vals.begin(),vals.end());

    for (int i=0; i<vals.size(); i++)
    {
        cout << vals[i] << " "; 
    }

    return 0;
}
