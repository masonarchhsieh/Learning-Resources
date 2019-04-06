/*
 * =====================================================================================
 *
 *       Filename:  template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/23/2019 03:49:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <stdlib.h>

template <class T>
class MyTemplate {
    T element;
    public:
    MyTemplate (T arg) {element=arg;}
    T divideBy2 () {return element/2;}
};

// class template specializationtemplate <>class MyTemplate <char> {char element;public:MyTemplate (char arg) {element=arg;}char printElement (){return element;}}:

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*Write the class AddElements here*/
template <class T>
class AddElements {
    T element;
public:
    AddElements (T arg) {element=arg;}
    T add(T arg) { return (element += arg); }

};

// class template specialization:
template <>
class AddElements <string> {
string element;
public:
    AddElements (string arg) {element=arg;}
    string concatenate(string arg) { return (element += arg); }
};


int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}


