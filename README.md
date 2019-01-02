# CMPE 320: Fundamentals of Software Development

# Initial Explanations
- `#include` is a preprocessor directive that is used to include external code into your program
- `iostream` is a library of I/O streams 
- `namespace` is a collection of name definitions
  - `using namespace std` says that your program is using names from the `std` (standard) namespace
  - `::` - scope resolution operator
- `int main()` is a function header
- `cout` is an object from the iostream library that represents the console output stream
- `<<` is the insertion operator and is used to insert the supplied string literal into the `cout` object
- `endl` stands for line feed character
- `return 0` is supposed to be optional in ISO C++, but some older compilers still require it
- `.h` is used for older style libraries, sometimes libraries don’t have the `.h` extension


# History of C++
## BCPL
- “Basic Computer Programming Language” (1960)
- Used to write compilers
- First language to create O-code before executable code
## B 
- Written by Bell Labs (1969)
- Single data type: word
- Gradually evolved to C in early 70’s
## C
- Dennis Ritchie (1972)
- Prodcedural language used for systems programming (aka compilers) and embedded systems
- Gives low level access to memory and efficient translation to machine code
- No need for assembly anymore
- Used on IBM-PC in 80’s
- ANSI-C (1983)
## C with Classes (aka C++)
- Bell Labs (1979)
- Added features to C:
  - Classes
  - Virtual Functions
  - Operator overloading
  - Multiple Inheritance
  - Templates
  - Exception Handling
## C++ Standards
- C++ ISO Standardized in 1998
- C++11 → 2011
- C++14 → 2014
- C++17 → 2017
- C++2a → In the works
- GCC, Visual Studio, Clang up to date with C++17
## Philosophy of C++
- Designed to be statically typed, general purpose language as efficient and portable as C
- Meant to support multiple programming styles:
  - Procedural programming,
  - Data Abstraction
  - Object Oriented
  - Generic Programming
- Meant to give programmer choice, even if it makes it possible for programmer to choose incorrectly
- Designed to be as compatible with C as possible → smooth transition from C
- Avoids features that are platform specific or not general purpose
- Zero-overhead principle: Does not incur overhead for features that are not used
- Designed to function without a sophisticated programming environment


## ISO C++ and C
- C++ Standard Library (std) incorporated the standard C library with a few optimizations
- C++ has “Standard Template Library” or `STL`  that contains many pre-defined data structures
  - `STL`: Set of classes and functions including containers, strings, diagnostics and algorithms
- [++ has “Standard Template Library” or STL that contains many pre-defined data structures](https://paper.dropbox.com/doc/has-Standard-Template-Library-or-STL-that-contains-many-pre-defined-data-structures-J5OFQ5MYFz6svJBiHypzk) 
- Well-written C code with run in C++
- `new` and `class` are not keywords in C and may cause issues if used as variable names in C


# C++ Technicalities
## Running a C++ Program
![](https://d2mxuefqeaa7sj.cloudfront.net/s_4C330908B0D8F5A2FD3AD156EA450F679F8CA2E6AD2E4E4CF98671F537373624_1544559414739_Screen+Shot+2018-12-11+at+3.16.43+PM.png)

- “Building”: Compiling and linking
  - Creates a `*.o*` *file, then a* `.exe` file
- Build errors are reported by the compiler and are seen in the console window
- Run-time errors are reported by the OS, which is running the `*.exe` file
## Variable Types & Declaration
- Infinite number of variable types! (bc you can define them yourself)
- C++ is declarative and statically typed
- Unlike C, you can declare variables anywhere
- Initialization optional, but good practice
- Type categories:
  - Fundamental types (primitives)
    - Chars:
      - `char` (UTF8)
      - `wchar_t` (Wide Char → Depends on compiler)
      - `char16_t` (UTF16)
      - `char32_t` (UTF32)
    - Integer Types 
      - `short` (2 bytes)
      - `int` (4 bytes)
      - `long` (4 bytes?)
      - `long long` (8 bytes?)
      - `long long int` (8 bytes guaranteed)
    - Floating Types
      - `float` (4 bytes)
      - `double` (8 bytes)
      - `long double` (12 bytes)
  - Enumerated types
    - If you do not assign values, they are given incremental values starting from zero
  - `void` type
  - Point types (`int*`)
  - Array types (`int[]`)
  - Reference types(`int&`)
  - Data Structures and Classes (`vector`)
- Compiler will determine the amount of memory allocated to numeric types
- In C++11, instead of stating a type during declaration, can use `auto` instead
  - Type of variable is inferred from the rest of the declaration
  - Return type deduction → using `auto` as return type in function header
  - `decl()type` → supply an argument typed with `auto` and the return from this function can be used to type another variable
- Literal Suffixes: suffixes can be appended to literals to modify their type
  - `auto aTime = 60s;` → aTime will be of type `chrono::seconds`
## Constants
- By convention all capital letters for name
  - `const double CM_IN_INCH (2.54)`
- Must assign value at time of declaration
## Casting Numeric Types
- C-style:
  - `(type) expression`
  - `type (expression)`
  - Removes `const` property
  - Does not check to see if cast if even possible
- C++ style:
  - `static_cast<type> (expression)`
    - Bes, general purpose technique for atomic types
  - `dynamic_cast<type> (expression)`
  - `const_cast<type> (expression)`
  - `reinterpret_cast<type> (expression`
## Declarations
- `int x, y, z` is fine
- `int* x, y` → x is a pointer, y is an int
- `auto` does not work with multiple declarations
- `typedef` can be used to create synonyms for types
  - `typedef long double dprecision`
# References and Pointers

Pointers are not references, and references are not pointers!

## Operators

LHS:

- &: gives you a reference to a type
- *: gives you a pointer to a variable of that type

RHS:

- &: “address of” operator yielding the memory address of a variable
- *: “de-referencing” → used with a pointer, yields the value of the variable being pointed to
## Pointers
- Pointer is a variable that stores a memory address
- Occupies memory (reference may not occupy memory)
- If the memory address was obtained using the & operator (“address of”) on another variables, then the pointer indirectly references the value contained by the other variable. Accessing this value through the pointer (using de-referencing is called indirection)
  - `cout << *ptr << endl;`
- To get the pointer value (address pointer is pointing to)
  - `cout << ptr << endl;`
- How much memory does a pointer occupy?
- To get the address of where the pointer is stored:
  - `cout << &ptr << endl;`
- `const int* ptr`
  - `ptr` points to an `int*` variable that is constant
- `int* const ptr`
  - `ptr` is a constant pointing to an `int*` variable that is not constant
- `const int* const ptr`
  - `ptr` is a constant pointing to an `int*` variable that is also constant
# Arrays
- To declare a variable to hold 5 integers:
  - `int anArray[5];`
  - `int anArray[] = {2, 7, 3, 0, 1};`
  - `int anArray[5] = {2, 7, 3, 0, 1};`
- Accessing one element before the array → `0`
- Accessing one element after the array → Garbage
    ```cpp
    cout << "\nMessing with array dimensions:" << endl;
    int bArray[] = {1, 2};
    bArray[0] = 100;
    bArray[1] = 200;
    bArray[2] = 300;
    for (i = 0; i < 3; i++)
        cout << bArray[i] << endl;
    cout << sizeof(bArray) << endl;
    -------------------------------
    output: 3
    ```

## C-Strings and Strings
- C-string:
  - `char oldString[] =` `"``Hello there!``"``;`
- C++ `string` class:
  - Uses `std` namespace
    ```cpp
    string s2 = "Hello";
    string s3 = s2;
    cout << "s3 is " + s3 << endl;
    s2[1] = 'A';
    // or s2.at(1) = 'A';
    cout << "now s2 is " + s2 << endl;
    cout << "now s3 is " + s3 << endl;
    --------------------------
    output: 
    now s2 is HAllo
    now s3 is Hello
    ```

## Structs
- Dot operator:
  - `object.member`
- De-referencing and membership:
  - `object→member`


## Boolean operators
- “Short circuit evaluation”
  - For `&&` if LHS is `false`, then RHS not evaluated
  - For `||` if LHS is `true`, then RHS not evaluated
- Legal Syntax:
  - `if (x = 10)`
  - Setting x equal to 10, therefore not 0, therefore true.
- -1 is true
- C-strings are not equal to strings

# I/O
- File I/O: `fstream`
  - Inherits all functionality from `iostream` (console logging), and adds additional functions like `open()` and `close()`
- Use `fail()` function to determine if file has opened OK
- To read `char` from file: `fileIn.get(aChar);`
- To read `string` from file: 
    string line;
    getline(fileIn, line);
- `getline()` returns flase when there is nothing to read in
# Classes
- `const` keyword in member function declarations
  - `vector<string> readFile const;`
    - Promises that the member function will not change member variables (attributes)
    - Good practice for accessors
- Member functions can access `private` members, even if in a different file
  - Non-member function cannot
- Default constructors → invoked without parameters
  - `TextFileIO test;`
  - NOT `TextFileIO test();`
## Constructors
- `MyString(); // Default constructor`
- `MyString(const char[]); // Simple constructor`
- `MyString(const MyString&); // Copy constructor`
- `MyString(int); // Conversion constructor`
# Exceptions
- Can throw anything except a pointer
- Doesn’t need to be part of the exception hierarchy
    TextFileIO testBad(badFile);
    try {
      vector<string> testData(testBad.readFile());
    } catch (TextFileException& e) {
      cerr << e.what() << endl;
    }
- Always catch exception by reference
- Can use ellipsis `…` to catch anything
# Requirements & User Stories
- Functional Requirement: A feature
- Non-functional Requirement: How well the feature needs to be implemented
- User stories:
  - As a [stakeholder], I want to [goal] so that [motivation]
# Initializer List Parameters & Lambda Functions
- Initializer List:
  - `std::initializer_list<type>` as parameter type to allow you to pass an initializer into a function
  - Initializer is a list of items of `type` contained in `{ }`
  - Already used by standard container classes like `vector`
  - `vector<int> vInt{3, 4, 7, 9, -10, 1};`
- Lambda Functions:
  - `[capture]{parameters} → returnType {function_body}`
  - `auto comparatorLambda( [] (int i, int k) → int {return i < j;});`
# Operator Overloading
- Cannot make a an unary operator a binary one, and vice versa
- `operator=` provided by the compiler automatically
    MyComplex::MyComplex() : real(0), imag(0) { }
    MyComplex::MyComplex(double r) : real(r), imag(0) { }
    MyComplex::MyComplex(double r, double im) : real(r), imag(im) { }
- Non-member
  - Accessors
  - Need LHS and RHS
  - Used for Binary Operators with potential for mixed type expressions 
    - `complex 
- Member
  - No Accessors
  - Only need RHS (LHS is object itself!)
  - Assignment Operators
  - Boolean Operators
- Friend
  - No Accessors 
  - Need LHS and RHS
  - Function prototype must be inside the class definition
  - No access to `this` pointer
  - Break privacy rules of stringent OOP language
  - **Use sparingly**
- **Examples:**
    ```cpp
    #pragma once
    #include <iostream>
    using namespace std;
    class MyComplex {
    public:
        MyComplex();                // Default Constructor
        MyComplex(double);          // Constructor, Conversion Constructor
        MyComplex(double, double);  // Constructor
        double abs() const;         // Accessor
        // Member Function (no need for accessors)
         // Binary Operator
        // MyComplex operator+(const MyComplex& right); 
        // Unary Operator (negation)
        // MyComplex operator-();
    private:
        double real;
        double imag;
        
    // Friend Functions
    // Binary Operator
    // friend MyComplex operator+(const MyComplex& left, const MyComplex& right);
    // Unary Operator
    // friend MyComplex operator-(const MyComplex& left);
    friend ostream& operator<<(ostream& out, const MyComplex& value);
    };
    
    // Non-member (needs accessors)
    // Binary Operator
    MyComplex operator+(const MyComplex& left, const MyComplex& right);
    // Unary Operator
    // MyComplex operator-(const MyComplex& left);
    ```

## Overloading Conversion Operators
- Used to cast to different types
    ```cpp
    Fraction:: operator double() const {
      return static_cast<double> (top/bottom);
    }
    --------------
    // Returns a double from a Fraction object
    double aNum = static_cast<double> (Frac)
    ```
- Public functions
- No return type!


## Conversion Constructors
- Similar to overloading conversion operators
- If you don’t want constructors to be used for implicit type conversions, declare constructors with `explicit` keyword
    ```cpp
    class Fraction {
      // etc.
      explicit Fraction(int);
      //etc.
    }
    ```
## Overloading the Subscript `[]` Operator
- Used when:
  - You’re building a data structure that requires access using an index
  - You’re building a data structure that wants to make sure index values are legal
- LHS of `=`:
  - `int& operator[] (int index)`
- RHS of `=`:
  - `int operator[] (int index) const`
## Overloading the Function Call Operator
- Allows an object to behave as if it is a function
  - Called a function object
- Only operator where number of arguments is not limited to one or two
## Inline Functions
- Used when function bodies are short
- Must be in declaration `.h` file
- A copy is made every time the function is invoked so it should be short
## Function Modifiers
- `=delete` disables the use of whatever function it is applied to
  - `MyComplex
- `=default` can be used with the default constructor to state that the compiler generated constructor is still to be used, even when you have other explicit constructors
# Repositories
![](https://d2mxuefqeaa7sj.cloudfront.net/s_4C330908B0D8F5A2FD3AD156EA450F679F8CA2E6AD2E4E4CF98671F537373624_1544721062473_Screen+Shot+2018-12-13+at+12.10.54+PM.png)



- Local repository consists of 3 “trees”
  - Working directory: Files you’re working on
  - Index: Staging Area
  - Local repository: contains links to your last commit
- Terms:
  - Clone: Create repository
  - Add: Put files in staging area
  - Commit: Snapshot of your repository
  - Push: Sends snapshot to remote repository
  - Fetch: Updates local repo with information for log files and version records (harmless)
  - Pull: Fetch, followed by merge of the Head branch. Updates files in working directory


# Stack
- Fixed size (default 2MB) consisting of sequential addresses
# Heap
- May not want to use a global, but need to have a variable that persists beyond a function’s completion
- Memory allocated with the `new` keyword
  - When creating an array, size does not have to be known until run-time
  - If memory allocation fails → `std::bad_alloc` exception will be thrown instead of `nullptr`
  - Conditional tests of a pointer to check that the memory has been allocated in heap will not work
    - Use a try/catch block!
- Must use a pointer to refer to something on the heap. 
  - Pointer will be on the stack
  - If you create an object on the heap within a function then you can return a pointer to that object and it will persist
- To delete:
  - `delete` operator
    - Will not get a compile error if you try to use this instead of `delete[]` → `delete` is just pointing to first element of the array!
  - `delete[]` operator for arrays
## Default Constructor
- No parameters, Any explicit constructor will remove the availability of this supplied constructor
## Copy Constructor
- Takes an argument of the current class type and copies it into the current object
- If you are using heap memory you need to allocate and initialize each value
- Example:
    ```cpp
    MyString::MyString (const MyString& right) {
      len = right.length();
      buffer = new char[len + 1]; // Using heap
      for (auto i = 0; i < len; i++) {
        buffer[i] = right[i];
      }
      buffer[len] = '\0';
    }
    ```
## Assignment Operator (operator= Overload)
- Copies the RHS to the LHS. If not replaced by an explicit version, member by member assignment is done.
- Check to make sure you’re not assigning yourself
  - If yes, do nothing
- Copy values of argument supplied
- Free up heap memory that is no longer needed. 
- Return `*this`
- Example:
    ```cpp
    MyString& MyString::operator=(const MyString& rhs) {
      if (this != &rhs) {
        delete[] buffer;
        len = rhs.length();
        buffer = new char*[len + 1]
        for (auto i = 0; i < len; i++) {
          buffer[i] = rhs[i];
        }
        buffer[len] = '\0';
      }
      return *this;
    }
    ```
## Destructor
- Member by member destruction of attributes
  - Frees all memory from heap
- Distinguished by `~` before the class name
- Never invoke destructor directly, system will invoke it instead
- Example:
    ```cpp
    MyString::~MyString() {
      delete[] buffer;
      buffer = nullptr;
    }
    ```
    
# Common Memory Errors
- Using variable that has not been initialized
- Using pointer to reference a memory location that is no longer valid
- Forgetting to delete something on the heap
- Deleting a memory value that was never allocated
- Deleting something on the heap more than once
- Object Slicing
  - de-referencing a pointer then assigning it to a different object type
# Polymorphism
- Dynamic cast can be used to determine what kind of object you actually have
  - `nullptr` is returned if cast fails
  - `Child *``*c = dynamic_cast<Child*>*` `(object);`
- Only works with pointers and references, not actual objects
  - Invoking a function from actual objects only gives you static binding
# Inheritance
- Encapsulation helps to maintain the integrity of an object’s data
- Inheritance avoids code repetition and allows you to lessen the impact that making changes in one class has on other classes
- Inheritance is the only way to get polymorphism, which allows you to ensure common behaviour at runtime to any object that is part of the hierarchy (late binding)
- The child class must invoke the constructor of the parent class
  - Can do this with an initializer list
    Child::Child(const double aNum, const int aVal) : Parent(aNum), myNum (aVal) {}
## Base Class Access Specifier
    class Child : public Parent {
    ...
    }
- `public` means no change to inherited access
- `protected` changes access of `public` parent members to `protected` in child class
- `private` changes both `protected` and `public` parent members to `private` in child class
  - `private` in parent is never accessible to child
## `virtual` Prototypes
- To allow polymorphic process of dynamic binding, function to be shared between parent and child classes must be `virtual`
  - Note that once a function is declared `virtual` in a parent class all child class versions of the same function are automatically `virtual` → but it is good practice to still name them `virtual`
- If a child class does not override the PArent’s `virtual` function, it just inherits it.
- Don’t use in the implementation `.cpp` file
- You don’t have to override a virtual function, but then you don’t have polymorphism, you just have inheritance
## Pure Virtual Member Functions (Abstract)
- `virtual` prototype in the parent class but cannot be implemented in parent class
  - EX) `getArea()` might be in `Shape` parent class, but cannot calculate an area of abstract shape
- If a class has at least one pure virtual member then it is termed an abstract class
- Cannot instantiate an abstract class
  - But can be used to enable polymorphism
- Child class of abstract class must implement pure virtual function in order to not be abstract itself
## Shadowing/Hiding
- Happens when you don’t specify `virtual` for the function that is in both parent and child
- Child class shadows the parent class version
- At run-time you get static binding instead of dynamic binding
## Overriding
- `override` keyword can be used at the end of a function prototype that is overriding a virtual parent prototype
  - Compiler checks to make sure overriding was done correctly
## Overloading vs. Overriding
- Overloading: Changing the parameters, return type, etc. of a function in the child class that is the same as the parent class
- Overriding: Function redefined in child class with exact same return type, parameters, name, as parent class
  - Early Binding!
  - If you want late binding (aka run-time binding) you need `virtual` keyword
## `final` keyword
- Used at the end of a prototype to prevent a virtual function from being overridden in a child class
- Class can also be declared `final`, in which case it can’t be used as a parent class
# Templated Functions


# Smart Pointers
# C++/CLI
- Common Language Infrastructure
- CLR
  - Common Language Runtime
  - Allows you to include C, ISO/C++ and C++/CLI code
- CIL
  - Common Intermediate Language
  - Looks like Assembly
  - CLR generates CIL as part of an Assembly
## Differences: ISO/C++ → C++/CLI
- Use handles instead of pointers
- Use `ref class` instead of just `class`
- Remove destructor
- Use `namespace System` instead of `namespace std`
- Remove `delete[]` statement from the `operator=`  overload
- Use `array<int>` or `vector<int>` instead of array 
- Use `gcnew` instead of `new`

