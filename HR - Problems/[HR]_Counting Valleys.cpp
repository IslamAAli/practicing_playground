#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {

    int valleyCount = 0 ;
    bool valley = false;
    bool mountain = false;
    int stepsInObject = 0 ;

    for (int i=0; i<n; i++)
    {
        if (s[i] == 'U')
        {
            if (!mountain && !valley)
                mountain = true;

            stepsInObject ++;
        }
        else 
        {
            if (!mountain && !valley)
                valley =  true;
            
            stepsInObject --;
        }

        if (stepsInObject == 0)
        {
            if(mountain)
            {
                mountain = false;
            }
            else if(valley) 
            {
                valley = false;
                valleyCount ++ ;
            }
        }
    }
    
    return valleyCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
