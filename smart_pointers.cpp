#include <memory>
using namespace std;

void smart_pointers()
{
    // std::unique_ptr
    // 1 copy to prevent multiple deletions
    unique_ptr<int> p1(new int);
    // builtin constructor (always prefer)
    unique_ptr<int> p2 = make_unique<int>();
    // unique_ptr<int> pc = p1; not allowed to copy!

    // std::shared_ptr
    // allows multiple references
    shared_ptr<int> p3(new int);
    shared_ptr<int> p4 = make_shared<int>();
    shared_ptr<int> pc = p3; // allowed copy

    // std::weak_ptr
    // prevents circular dependencies
    // can only create out of a shared_ptr or weak_ptr
    weak_ptr<int> p5(p3);
    weak_ptr<int> p6(p5);
    p6.expired(); // checks if data deleted
}