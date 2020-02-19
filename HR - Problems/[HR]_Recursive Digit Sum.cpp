#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the superDigit function below.
int superDigit(string n, int k) {
    
    int superDigitReturn = 0 ;

    if (n.length() == 1)
    {
        return stoi(n);
    }
    else
    {
        long long strSum = 0 ;
        // get the sum of integers
        for(int i=0; i<n.length(); i++)
        {
            strSum += ((int)n[i] - 48);
        }
        strSum *= k ;

        superDigitReturn = superDigit(to_string(strSum), 1);
    }
    return superDigitReturn; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    string n = nk[0];

    int k = stoi(nk[1]);

    int result = superDigit(n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
