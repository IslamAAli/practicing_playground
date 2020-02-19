#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

struct tagStruct {
    string name;
    map<string, string> attr;
    map<string, tagStruct*> insideTags;
};

tagStruct* getFirstTime(map<string, tagStruct*> m_topLevelTags, string m_tag)
{
    map<string, tagStruct*>::iterator it;
    it = m_topLevelTags.find(m_tag);
    if (it != m_topLevelTags.end())
    {
        return it->second;
    }
    else
    {
        return NULL;
    }
}

int main() {

    int N, Q;
    scanf("%d %d\n", &N, &Q);
    stack<tagStruct*> tags;

    map<string, tagStruct*> topLevelTags;

    bool tagOpened = false;
    // generating the structure
    for (int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line);

        if (line[1] == '/') // closing tag
        {
            tagStruct* tmp = tags.top();
            tags.pop();
            if (tags.empty())
            {
                topLevelTags[tmp->name] = tmp;
            }
        }
        else //opening tag
        {
            string tmp;
            tagStruct* ts = new tagStruct();
            stringstream ss(line);
            ss >> tmp;
            if (tmp[tmp.length() - 1] == '>')
            {
                ts->name = tmp.substr(1, tmp.length() - 2);
            }
            else
            {
                ts->name = tmp.substr(1, tmp.length() - 1);
            }
            

            // parse attributes
            while (!ss.eof())
            {
                ss >> tmp;
                if (tmp[tmp.length() - 1] != '>')
                {
                    // attribute
                    char tmp2;
                    ss >> tmp2; // reading =
                    string tmp3;
                    ss >> tmp3; // reading value 

                    if (tmp3[tmp3.length() - 1] == '>') // last attribute
                        ts->attr[tmp] = tmp3.substr(1, tmp3.length() - 3);
                    else // still other attributes to come
                        ts->attr[tmp] = tmp3.substr(1, tmp3.length() - 2);
                }
            }

            // add to parents list 
            if (!tags.empty())
            {
                tags.top()->insideTags[ts->name] = ts;
            }

            // push to stack
            tags.push(ts);
        }
    }

    // reading queries 
    for (int i = 0; i < Q; i++)
    {
        string line;
        getline(cin, line);

        bool firstTag = true;
        int lastStop = 0;
        tagStruct* tagSelected = NULL;
        for (int j = 0; j < line.length(); j++)
        {
            if (line[j] == '.' || line[j] == '~')
            {
                if (firstTag)
                {
                    tagSelected = getFirstTime(topLevelTags, line.substr(lastStop, j - lastStop));
                    if (tagSelected == NULL)
                    {
                        cout << "Not Found!" << endl;
                        break;
                    }
                    lastStop = j + 1;

                    if (line[j] == '~')
                    {
                        // get attribute;
                        string attrName = line.substr(lastStop, line.length() - j);

                        map<string, string>::iterator itr2;
                        itr2 = tagSelected->attr.find(attrName);
                        if (itr2 != tagSelected->attr.end())
                        {
                            cout << tagSelected->attr[attrName] << endl;
                        }
                        else
                        {
                            cout << "Not Found!" << endl;
                            break;
                        }
                    }
                    firstTag = false;
                }
                else
                {
                    if (line[j] == '.')
                    {
                        map<string, tagStruct*>::iterator it;
                        it = tagSelected->insideTags.find(line.substr(lastStop, j - lastStop));
                        if (it != tagSelected->insideTags.end())
                        {
                            tagSelected = it->second;
                        }
                        else
                        {
                            cout << "Not Found!" << endl;
                            break;
                        }
                        lastStop = j + 1;
                    }
                    else
                    {
                        map<string, tagStruct*>::iterator it;
                        it = tagSelected->insideTags.find(line.substr(lastStop, j - lastStop));
                        if (it != tagSelected->insideTags.end())
                        {
                            tagSelected = it->second;
                        }
                        else
                        {
                            cout << "Not Found!" << endl;
                            break;
                        }
                        lastStop = j + 1;

                        // get attribute;
                        string attrName = line.substr(lastStop, line.length() - j);

                        map<string, string>::iterator itr2;
                        itr2 = tagSelected->attr.find(attrName);
                        if (itr2 != tagSelected->attr.end())
                        {
                            cout << tagSelected->attr[attrName] << endl;
                        }
                        else
                        {
                            cout << "Not Found!" << endl;
                            break;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
