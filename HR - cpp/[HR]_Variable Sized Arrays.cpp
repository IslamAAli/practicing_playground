#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int vertSize, querySize ;
    cin >> vertSize >> querySize;

    int** arr = new int*[vertSize];

    for (int i=0 ; i< vertSize; i++)
    {
        int horzSize;
        cin>> horzSize;
        arr[i] = new int[horzSize];

        for (int j=0; j<horzSize; j++)
        {
            cin>> arr[i][j];
        }
    }

    for (int i=0;i<querySize; i++)
    {
        int x,y;
        cin >> x >> y; 
        cout << arr[x][y]<<endl;
    }

    return 0;
}

