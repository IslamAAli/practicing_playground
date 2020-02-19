#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main() {

    int begin, end;
    cin >> begin >>end;

    map<int, string> letters;
    letters[1] = "one";
    letters[2] = "two";
    letters[3] = "three";
    letters[4] = "four";
    letters[5] = "five";
    letters[6] = "six";
    letters[7] = "seven";
    letters[8] = "eight";
    letters[9] = "nine";

    for(int i=begin; i<=end; i++)
    {
        if (i<=9)
        {
            cout <<letters[i]<<endl;
        }
        else
        {
            i%2? cout<<"odd"<<endl :cout <<"even"<<endl;
        }
    }

    // Complete the code.
    return 0;
}

