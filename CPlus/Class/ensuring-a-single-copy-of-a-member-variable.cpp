// Static.h
class OneStatic {
public:
    int getCount() {return count;}
    OneStatic();
protected:
    static int count;
};

// Static.cpp
#include "Static.h"

int OneStatic::count = 0;

OneStatic::OneStatic() {
    count++;
}

// StaticMain.cpp
#include <iostream>
#include "static.h"

using namespace std;

int main() {
    OneStatic a;
    OneStatic b;
    OneStatic c;

    cout << a.getCount() << endl;
    cout << b.getCount() << endl;
    cout << c.getCount() << endl;
}