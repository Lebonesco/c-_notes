# C++ Notes
## Problems
* Has no Garbage Collection
* Verbose
    * Getting better
* Lack of metadata
    * lack of attributes
    * has something called Run Time Type Information (RTTI)
    * template metaprogramming provides some of the same benefits
* Has a preprocessor
    * possible source of bugs and ambiguities
* Unreadable compiler messages
* compilation is slow
    * cluster builds
* poor unicode support
* backward compatibility with C
    * code bloat
* template metaprogramming
* Testing is more difficult
    * no metadata
* third-party libraries often shipped as source code

## lvalues and rvalues
* lvalue - something that points to a specific memory location.
can access address operator
can become rvalues
* rvalue - something that doesn't point anywhere.
temporary and short.
* The ability to return lvalues from functions is useful when doing advanced things like implementing overloaded operators.

## Strings
Arrays of characters terminated by a zero '\0'
Existed before unicode
ascii stored in a char
1 byte
char c = 'z';
'Wide' character stored in a wchar_t
width compiler-specific
unicode standard not recommend
```
char *text = "hello";
wchar_t *text = L"hello";
```

a universal reference.
neither a pointer nor a reference.

## Quirks
* can't use _alloc in exception handlers. Compiles fine, but causes runtime memory problems if the exception handler is executed.


## Notes
* #ifndef namespace checks if namespace is already defined
* dynamic_cast - casting from a base class to derived cast. actually checks if class type is derived
* static_Cast - performed at compile time
* move - more efficient for moving variables
smart pointers use these semantics

## Compilation
* After preprocessing, all #include statements are implemented
* each .cpp file has all includes recursively
* each .cpp becomes very big (translation unit)
* Each translation unit is compiled into an object file
### Linking
* joins all the object files into an executable library
* might link to other libraries
* external libraries can be
* static - included in the program
* dynamic - exists as separate file

## OOP

Constructors, copy and move assignment operations, and destructors support view of lifetime and resource management.


Five situations when an object is copied or moved:
* As the source of an assignment
* As an object init
* As a function argument
* As a function return value
* As an exception

If a class has a destructor you must decide if the object can be copied or moved.

### Virtual Destructors
* It's needed because on object manipulated through the a class interface is often deleted through that interface
* https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors

```
Base *b = new Derived();
delete b; // if not virtual destructor base will be called possibly leaking data in Derived.
```

#### Init-List Constructor
```c++
void f(std::initializer_list<int>);
f({1,2,3});
```

### Static Members
* Usually declared for a definition outside of the class.
```c++
class Node {
    static int node_count;
};

int Node::node_count = 0;
```

### Copy
Copy for x is defined by two operations
* Copy constructor: ```X(const X&)```
    * initializes uninitialized memory.
    * remember to copy every member over
* Copy assignment: ```X& operator=(const X&)```
    * Deals with an object that has already been constructed and may own resources.

A pointer to a derived class implicitly converts to a pointer to its public class when applied to a copy operation. This can cause slicing. There are ways to protect this.

### Move
* ```&&``` indicates rvalue reference
* move assignment handles lvalues separately from rvalues: copy assignment and constructors take lvalues whereas move assignment and constructors take rvalues.
* The move constructor is used for returns.
* How does the compiler know to use move or copy?
    * language rules.
    * tell it by passing rvalue reference.
        * ```move()``` returns rvalue reference.

### History
* Needed support for progam organization like in Simula but needed something fast like BCPL.
* Struggled with PHd in Cambridge
* create C with classes at Bell Labs 

#### Why C?
* C was the best systems program available at the time. 
* Flexible, efficient, portable, and well known.
* 2nd order flaws not critical

### Exception Handling pg343
* Only meant for synchronous execeptions.
* Mechanisms for asynchronous events are signals.
* use to communciate some part of the system couldn't do what it was asked to.
* don't use to just return values.
* don't use for time-critial programs or large old.
* important to have an overall strategy to communicate exceptions between different parts of the program.


### Strings
```<cctype>``` provides
```c++
isspace(c);
isalpha(c);
isidigit(c);
isupper(c);
islower(c);
isalnum(c);
toupper(c);
tolower(c);
s2 = s.substr(pos, n);
s2 = s.substr(pos);
s2 = s.subtr();
n = s.compare(s2); // n==0 is equal, n<0 is s<s2
n = s.compare(pos, n, s2);
```

#### String I/O
```c++
in >> s;
out << s;
getline(in, s, d); // read characters in into s until d encountered
getline(in,s); // d is \n
```

#### Numeric Conversion
```c++
x = stoi(s,p,b); // x is int, p set to num of char, b is base
x = stoi(s,p);
x = stoi(s); // base 10 
x = stl(s,p,b);
s = to_string(x);
```

### I/O Streams
An iostream can be in one of four states:
* good() - prev operation succeeded
* eof() - hit end of input
* fail() - something unexpected happened
* bad() - something unexpected and serious happened (disk read error)