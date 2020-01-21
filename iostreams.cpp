#include <iostream>

using namespace std;

void iostream()
{
    for(string x; cin>>x;) {
        // do something with x
    }

    int i;
    if (cin>>i) {
        // use i
    } else if (cin.fail()) { // possible format error
        cin.clear();
        string s;
        if (cin>>s){ // maybe recover using string
            // use s
        }
    }
}