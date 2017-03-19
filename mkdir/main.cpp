#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void split(vector<string>&, string);
int counts(vector<string>&);

int main(int argc, char *argv[])
{
    string str;
    vector<string> input;
    while(cin >> str)
        input.push_back(str);
    cout << counts(input) << endl;

    return 0;
}

void split(vector<string> &splitvec, string str)
{
    string::size_type pos1 = 0;
    string::size_type pos2 = 0;
    while(pos2 != string::npos)
    {
        pos1 = str.find('/', pos1);
        pos2 = str.find('/', pos1+1);
        splitvec.push_back(str.substr(pos1+1, pos2-pos1-1)); // 此处是pos2-pos1-1
        pos1 = pos2;
    }
}

int counts(vector<string>& input)
{
    map<string, int> mp;
    int num = 0;
    for (auto &str : input)
    {
        vector<string> splitvec;
        split(splitvec, str);
        for (int i = 0; i < splitvec.size(); ++i)
        {
            cout << splitvec[i] << endl;
            if (mp[splitvec[i]] == 0)
            {
                // 如果该目录第一次建立，之后的所有子目录都需要建立
                for (int j = i; j < splitvec.size(); ++j)
                    ++mp[splitvec[j]];
                break;
            }
        }

    }
    for (auto &c : mp)
        num += c.second;
    return num;
}
