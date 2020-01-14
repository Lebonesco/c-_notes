#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iostream>

using namespace std;

void containers()
{
    // array
    // old way, static allocation
    array<int, 5> numbers = {{1,2,3,4,5}};

    // vector 
    // new way, dynamica allocation
    vector<float> values{1, 2, 3, 4};
    values.push_back(4.5f);
    values.pop_back();
    values.size();

    try {
        float u = values.at(5); // safe way to check index value
    } catch (const out_of_range& e)
    {
        cout << e.what() << endl;
    }

    // set
    set<char> letters;
    letters.insert('c');
    letters.size();

    // stack
    stack<int> s;
    s.push(4);
    s.pop();
    s.top();

    // queue
    queue<int> q;
    q.push(val);
    q.front();
    q.back();
    q.pop();

    // maps
    map<string, string> m;
    m.insert(pair<string, string>("key", "value"));
    m.at("key");
    m.size();
    m.erase("key");
    m.clear();
    (m.find("key") != m.end());
}
