#include <memory>

using namespace std;

// Optimized move semantics
https://www.internalpointers.com/post/c-rvalue-references-and-move-semantics-beginners
// for temporary objecst better to move allocated data 
// than make expensive copies
// Older c++ didn't allow optimizating of returning values

class Holder
{
public:
    Holder(int size)
    {
        m_data = new int[size];
        m_size = size;
    }

    ~Holder()
    {
        delete[] m_data;
    }

    // copy
    Holder(const Holder& other)
    {
        m_data = new int[other.size];
        copy(other.m_data, other.m_data + other.m_size, m_data);
        m_size = other.m_size;
    }

    // assignment
    Holder& operator=(const Holder& other)
    {
        if(this == &other) return *this; // if same pointer
        delete[] m_data;
        m_data = new int[other.m_size];
        copy(other.m_data, other.m_data + other.m_size, m_data);
        m_size = other.m_size;
        return *this;
    }

    // typical move constructor
    // avoids deep copies
    // set copied fields to prevent deletion
    Holder(Holder&& other) // rvalue reference input
    {
        m_data = other.m_data;
        m_size = other.m_size;
        other.m_data = nullptr; // important
        other.m_size = 0; // important
    }

    // move assignment
    Holder& operator=(Holder&& other)
    {
        if (this == &other) return *this;
        delete[] m_data;
        m_data = other.m_data;
        m_size = other.m_size;
        other.m_data =  nullptr;
        other.m_size = 0;
        return *this;
    }

private:
    int * m_data;
    size_t m_size;
};

void move()
{
    Holder h1(1000); // init
    Holder h2 = h1; // copy
    Holder h3(h1); // copy
    Holder h4(10); // init
    h4 = h1; // assign
}

void const_ptr()
{
    int* a; // pointer to int
    const int* a; // pointer to const int
    int* const a; // const pointer to int
    const int* const a; // const pointer to const int
}

template <int, n>
int sum(array<int, n> values)
{
    int result = 0;
    for (int value: values)
        result += value;
    return result;
}

void initialization()
{
    int x(0);
    int y = 0; // init not assignment
    int z{0};
    int w = {0};
}

void functions()
{
    // arguments by reference don't require copy. 'const' means read only
    string concate(const string& a, const string& b) 
    {
        return a+b;
    }

    // overloading
    template <T>
    T sum(T a, T b) { return a+b; }

    // returning multiple types
    std::tuple<int, int> foo(int a, int b) {
        return std::make_tuple(a, b);
    }

    auto mrvs = foo(5, 12);
    auto a = std::get<0>(mrvs);
    auto b = std::get<1>(mrvs);
    int a, b;
    std::tie(a, b) = foo(5, 12); // unpack variables
    std::tie(a, std::ignore) = foo(5, 12);
}

void enumeration()
{
    // occupies namespace
    enum Color
    {
        Red,
        Blue,
        Green
    };

    // better version
    enum class GameState
    {
        Win,
        Lose
    };
}

// Virtual Function
// dynamic linkage or late binding calls the function at a given point based on the object it is called

void oop()
{
    class Person
    {
        static int lifeExp; // default private
    public:
        const static int female = 0;
        const static int male = 1;
        int age;
        string name;
        int sex;

        virtual greet();

        static int getLifeExp();
        Person();
        ~Person();
    };

    // copy constructor
    Person::Person(Person const& p)
    : age(p.age), name(p.name), sex(p.sex)
    {
        auto* a = p.address;
        address = new Address(
            a->house_number,
            a->street_name);
        )
    }

    int Person::lifeExp = 80; // how to init static

    class Employee : public Person
    {
        friend class EmpFactory; // lets access private members
        int taxId;
    public:
        Employee(int age, string const& name, int sex, string deparment = string())
        : Person(age, name, sex),
        department(department)
        {}

        string department;
    };


}

// modern C++
// avoid memory management
// use lamdbas c++11
// use standard containers
// use standard algorithms
// embrace move semantics c++11
// style rules
// consier the PIMPL idiom

// Rule of Three
// need copy, constructor, destructor

// make explicit decisions about ownership and
// lifetime before coding
//raw pointer in modern c++ says just observe

// list
// avoids copying all data over
// https://github.com/rigtorp/awesome-modern-cpp