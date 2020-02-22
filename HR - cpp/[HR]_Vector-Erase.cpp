#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> vals;
    int tmpInput;
    cin >> tmpInput;
    for (int i=0; i<tmpInput; i++)
    {
        int input; 
        cin >> input; 
        vals.push_back(input);
    } 

    cin >> tmpInput;
    vals.erase(vals.begin()+tmpInput-1);

    int erB, erE;
    cin >> erB >> erE;
    for (int i=0; i<erE-erB; i++)
    {
        vals.erase(vals.begin()+erB-1);
    }

    cout << vals.size()<<endl;

    for(int i=0; i<vals.size(); i++)
    {
        cout << vals[i] << " ";
    }

    return 0;
}
