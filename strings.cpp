#include <string>

using namespace std;

void strings()
{
    // string literals are arrays containing null-terminated character sequence
    const char *foo = "hello";
    *(foo+4) == foo[4];

    string str;
    str.push_back('s');
    str.pop_back();
    string::iterator it;
    for (it=str.begin(); it != str.end(); it++)

    char *s = "string";
    while (*s)
    {
        // do something
        s++;
    }
}