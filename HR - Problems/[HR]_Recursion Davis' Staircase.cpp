#include <bits/stdc++.h>

using namespace std;

// Complete the stepPerms function below.
int stepPerms(int n, map<int, int> *results) {
    
    long long  totalPerms = 0 ;

    if (n==1)
    {
        return 1;
    }
    else if (n==2)
    {
        return 2;
    }
    else if (n==3)
    {
        return 4;
    }
    else if (n >= 3)
    {
        map<int,int>::iterator it =  results->find(n);
        if (it != results->end())
        {
            totalPerms = results->find(n)->second;
        }
        else
        {
            totalPerms += (stepPerms(n-1, results) + stepPerms(n-2, results)+ stepPerms(n-3, results));
        }
    }
    else
    {
        return 0; 
    }
    
    totalPerms = totalPerms %  10000000007  ;
    results->insert(pair<int,int>(n, totalPerms));

    return totalPerms;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        map<int, int>* results = new map<int,int>;
        int res = stepPerms(n, results);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
