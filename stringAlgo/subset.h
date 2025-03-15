#include <string>
#include <iostream>
#include <math.h>

using namespace std;

void generateSubstringsBitmask(string s)
{
    int n = s.size();

    for (int mask = 0; mask < pow(2,n); mask++)
    {
        string subset = "";

        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                subset += s[i];
            }
        }
        subset.empty() ? cout << "phi" << "\n" : cout << subset << "\n";
    }
}

void generateSubstringsRecursive(string &s, int index, string curr){
    if(index == s.size()){
        curr.empty() ? cout << "phi" << "\n" : cout << curr << "\n";
        return;
    }
    generateSubstringsRecursive(s, index + 1, curr);

    generateSubstringsRecursive(s, index + 1, curr + s[index]);
}

void generateSubsets(vector<int>& vec, int index, vector<int> curr){
    if(index == vec.size()){
        cout << "{";
        for(auto i: curr){
            cout << i;
        }
        cout << "}" << endl;
        return;
    }

    generateSubsets(vec, index + 1, curr);

    curr.push_back(vec[index]);
    generateSubsets(vec, index + 1, curr);
}