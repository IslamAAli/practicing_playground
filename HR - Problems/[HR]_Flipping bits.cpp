#include <bits/stdc++.h>

using namespace std;

// Complete the flippingBits function below.
long flippingBits(long n) {

    string s = bitset<32>(n).to_string();
    for (int i=0; i<s.length(); i++)
    {
        if (s[i]=='0')
            s[i] = '1';
        else
            s[i] = '0';
    }

    bitset<32> s_casted(s);

    return s_casted.to_ulong();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = flippingBits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
