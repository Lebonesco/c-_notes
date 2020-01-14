#include <string>
#include <vector>

// class signatures

class X {
    X(int); // contructor
    X(); // default contructor
    X(const X&); // copy constructor
    X(X&&); // move constructor
    X& operator=(const X&); // copy assign: clean up target and copy
    X& operator=(X&&); // move assign: clean up target and move
    ~X(); // destructor
};

// construct and destruct
class Vector {
public:
    Vector(int s) :elem{new double[s]}, sz{s} {};
    ~Vector() { delete[] elem; }
private:
    double* elem;
    int sz;
};

Vector* f(int s)
{
    Vector v1(s); // will trigger own delete
    return new Vector(s+s);
}

void g(int ss)
{
    Vector* p = f(ss);
    delete p; // manual delete
}

// virtual destructors
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape();
};

class Circle {
public:
    void draw();
    ~Circle(); // overrides ~Shape()
};

// member init
class Club {
    std::string name;
    std::vector<std::string> members;
    std::vector<std::string> officers;
    
    Club(const std::string& n);
};

Club::Club(const std::string& n)
    : name{n}, members{}, officers{}
{
    //...
}

template<class T>
void swap(T& a, T& b)
{
    const T tmp = a; // put copy of a into tmp
    a = b; // put copy of b into a
    b = tmp; // put copy of tmp into b
};

// Matrix class
template<class T>
class Matrix {
    std::array<int,2> dim;
    T* elem; // pointer to sz elements of type T

    Matrix(int d1, int d2) :dim{d1,d2}, elem{new T[d1*d2]} {}
    int size() const { return dim[0]*dim[1]; }

    Matrix(const Matrix&); // copy constructor
    Matrix(Matrix&&); // move constructor

    Matrix& operator=(const Matrix&); // copy assignment
    Matrix& operator=(Matrix&&); // move assigment

    ~Matrix();
    // ...
};

template<class T>
Matrix<T>::Matrix(Matrix&& a) // move constructor
    : dim{a.dim}, elem{a.elem} // grab a's representation
{
    a.dim = {0,0}; // clear values
    a.elem = nullptr;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix&& a) // move assignment
{
    swap(dim,a.dim);
    swap(elem,a.elem);
    return *this;
}