#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    set<int> s;
    int N;
    cin >> N;
    while (N > 0)
    {
        int temp, temp1;
        cin >> temp >> temp1;

        if (temp == 1) {
            s.insert(temp1);
        } else if (temp == 2) {
            set<int>::iterator itr = s.find(temp1);
            if (itr != s.end())
                s.erase(temp1);

        } else if (temp == 3) {
            set<int>::iterator itr = s.find(temp1);
            if (itr != s.end())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        N--;
    }

    return 0;
}




