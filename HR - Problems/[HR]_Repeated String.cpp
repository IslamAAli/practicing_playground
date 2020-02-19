#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    // compute how many a's do we have in the string s
    int a_count = 0 ;
    long long int a_total = 0 ;
    for (int i=0; i<s.length(); i++)
    {
        if (s[i] == 'a')
            a_count ++;
    }

    // get how many complete s is there and the reminder
    a_total = (n/s.length())*a_count;
    
    int s_reminder = n%s.length();

    for(int i=0; i<s_reminder; i++)
    {
        if (s[i] == 'a')
        {
            a_total ++ ;
        }
    }

    return a_total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
