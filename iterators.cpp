#include <vector>

using namespace std;

void iterators()
{
    vector<int>::iterator first;
    vector<int> foo;
    first = foo.begin();
    ++first;
    advance(first, 1); // forward 1
    first = std::next(first); // forward 1
    advance(first, -1); // back 1
    first = prev(first, 3); // back 3
    auto dist = distance(foo.begin(), first); // length between
}