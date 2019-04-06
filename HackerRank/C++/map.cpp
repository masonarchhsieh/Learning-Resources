#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    map<string, int> m;

    cin >> N;
    while (N > 0)
    {   
        int type, temp;
        string name; 
        cin >> type;
        if (type == 1)
        {
            cin >> name >> temp;
            map<string,int>::iterator itr = m.find(name);
            if (itr == m.end())
                m.insert(make_pair(name, temp));
            else
                m.at(name) =  (int)m.at(name) + temp;
        } 
        else if (type == 2)
        {
            cin >> name;
            map<string,int>::iterator itr = m.find(name);
            if (itr != m.end())
                m.erase(itr);

        } 
        else if (type == 3)
        {
            cin >> name;
            map<string,int>::iterator itr = m.find(name);
            if (itr != m.end())
                cout << m.at(name) << endl;
            else
                cout << 0 << endl;
        }

        N--;
    }


    return 0;
}




