#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {

    vector<int> freq(26,0);

    for (int i=0 ; i<a.length(); i++)
    {
        freq[((int)a[i] % 97)] ++ ;
    }

    for (int i=0 ; i<b.length(); i++)
    {
        freq[((int)b[i] % 97)] -- ;
    }

    int deletion = 0 ;
    for (int i=0; i< 26; i++)
    {
        deletion += abs(freq[i]);
    }
    return deletion;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
