#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {

    string s_sel;
    string s_big;
    if (s1.length() > s2.length())
    {
        s_sel = s2;
        s_big = s1;
    }
    else 
    {
        s_sel = s1;
        s_big = s2;
    }

    for (int i=0; i<s_sel.length(); i++)
    {
        std::size_t found = s_big.find(s_sel[i]);

        if (found!=std::string::npos)
            return "YES";
    }

    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
