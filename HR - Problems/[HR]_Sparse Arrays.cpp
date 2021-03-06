#include <bits/stdc++.h>
#include <map>

using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    map<string, int> occ_map; 
    vector<int> res;
    // create the map to handle count the occurances
    for(int i = 0; i< strings.size(); i++)
    {
        if (occ_map.find(strings[i]) != occ_map.end())
        {
            // key found
            occ_map[strings[i]] ++;    
        }
        else
        {
            occ_map.insert(pair<string, int>(strings[i], 1));
        }
    }
    
    for(int i=0; i<queries.size(); i++)
    {
        if(occ_map.find(queries[i]) != occ_map.end())
        {
            res.push_back(occ_map[queries[i]]);   
        }
        else
        {
            res.push_back(0);
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int strings_count;
    cin >> strings_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(strings, queries);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
