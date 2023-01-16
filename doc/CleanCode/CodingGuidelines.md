# Klang Coding Guidelines

You are an author and responsible for the expressiveness of your code and the readability.
If every developer sticks to the code conventions you can tell immediately if this is business logic or a 3rd party code.
Let us strike any reader with intense code consistency and clarity.
This document should help you with that.

1. [Layout](#Layout)
2. [Naming](#Naming)
3. [Types](#Types)
4. [Functions](#Functions)
5. [Classes](#Classes)
6. [Comments](#Comments)
7. [Namespaces](#Namespaces)
8. [Error Handling](#Error Handling)
8. [Miscellaneous](#Miscellaneous)

We build our conventions upon the [JUCE soding standards](https://juce.com/discover/stories/coding-standards) and the [Clean Code](https://www.amazon.de/Clean-Code-Handbook-Software-Craftsmanship/dp/0132350882) book.
The book is available at the office and I urge you to read it (don't have to read cover to cover but extract chapters of your interest).


## The most important rule by all is the **boy scout rule**

    Leave the campground cleaner than you found it

## General rules
Be polite in your code and allow the reader to exit at any state of your code and increase the level of detail with each abstraction. 
Being polite is about getting more and more specific with each lower level method or function call. Don't implement details in the top layers.

**Avoid code duplication at all costs.**

We shold write our code **S.O.L.I.D.**

**S**ingle responsibility (*SRP*) 

**O**pen-Closed Principle (*OCP*)

**L**iskov Substitution Principle (*LSP*)

**I**nterface Segregation Principle (*ISP*)

**D**ependency Inversion Principle (*DIP*)


## Layout
* No tab characters
* Tabs are 4 spaces!
* Braces are indented in the [Allman/BSD](https://en.wikipedia.org/wiki/Indentation_style#Allman_style) style
```
if (x == 0) {      // No!
    foobar();
    return "zero";
}

if (x == 0)        // Yes!
{
    foobar();
    return "zero";
}
```
* Always put a space before and after all binary operators (except declaring an operator e.g. bool operator== (foo))
* Group expressions based on their relation and use brackets to clearify and avoid compiler interpretations.
* The `!` operator should be followed by a space `if (! foo)`
* The `~` should be preceeded by a space but not followed by one
* Operators such as `++` or `--` are directly bounded to the operand
* Commas are followed by a space but not preceeded by one.
* Don't put a space before an open square bracket when used as an arary index - e.g. `foo[1]`
* In general, leave a blank line after a closing brace `}` - unless followed by other close-braces
* Don't write if statements all in one line. Use human readable variables instead
```
if ( (obj->hasNoSignal() && obj->isNotConnected()) || system->setupRoutine() ) 
{
    ...
    // A clutter to read

// refactor to 
bool initializeObj = (obj->hasNoSignal() && obj->isNotConnected()) || system->setupRoutine();
if ( initializeObj )
{
    ...
    // Now you know when the if clause is executed w/o "thinking"
```
* **Don't use** C++15 notation with `boolValue ? execWhenTrue() : execWhenFalse;`
* Pointers are a quality, that belongs to the type, not the variable. Hence, a variable should be `*`-free
```
SomeObject* myObject = getAPointer();
SomeObject& myObject = getAReference();
```
* Multiple lines for multiple pointers/references, initialize with `nullptr`
```
SomeObject* myObjectPointer1(nullptr);
SomeObject* myObjectPointer2(nullptr);
// or
typedef SomeObjectPtr SomeObject*;
SomeObjectPtr myObjectPointer1(nullptr);
```
* A programming language is a *language*, hence stick to grammar and write `const` before types and not variable names.
```
const Thing& aThing; // -> OK
Thing const& aThing; // -> read that out loudly
```
* Templare parameters should follow their type w/o a space `vector<int>` or `map<string, int>`
* Separate `>>` when closing template arguments to avoid compiler confustion
```
std::vector<std::vector<int>> // Wrong
std::vector<std::vector<int> > // OK

typedef intVector std::vector<int>
std::vector<intVector> // even better
```
* Hexadecimal is written in lower-case
* Floating point literals must have at least one digit before and after the dot, concatenate with `f`
```
float myFloat = 10.0f;
```
* Prevent train wrecks
```
someObj->getSubObjPtr()->doMoreStuff()->setSomethingNew()->validate();
```

## Naming
* Use pronounceable names. You don't talk about code if you can't speak it.
* We use CamelCase for our naming
    * Variables and methods start with a lower-case letter `myVariableName`
    * Classes start with a capital letter `MyClassName`
    * use CamelCase in enums too
    * Avoid underscores in naming except to make it more readable
* Classes are a noun
* Methods or functions are a verb
* Be consistent with naming, have a shared lexicon of words and stick to that.
* Don't add gratitutious context, simple names are sufficient
* Avoid disinformation => similar naming shapes = similar behaviour
```
void doSomethingWithAnABCValueOfOurStruct();
void doSomethinnWithAnABDValueOfOurStruct(); // where is the first typo? its not D...
```
* Avoid noise words such as *do*, *make*
* Don't use [hungarian notation](https://en.wikipedia.org/wiki/Hungarian_notation), it's forbidden for good reasons.
* If you write macros it *should* be `ALL_CAPS_WITH_UNDERSCORES`
    * As macros don't have a namespace make sure those names are unique in the complete system.
* When you write a template class or function avoid using `T` or one-character template parameters. Go with a more meaningful name to prevent clash with macros of some 3rd party headers
* Don't be cute. Don't write funny function names but meaningful ones. What the heck is `obj->HolyHandGrenade()` supposed to do? 
* Don't pun. As this requires a common cultural background to understand something this may be clutter for your head
* Avoid mental mapping and don't show off your smartness. Hence, use meaningful variable names and focus on comprehension for others.
* Choose clarity over entertainment value. Say what you mean, mean what you say.

## Types
* If a method can (and should!) be const, make it const! There are some [reasons](https://isocpp.org/blog/2012/12/you-dont-know-const-and-mutable-herb-sutter) for that!
* Testing if a pointer is null, don't to `if(myPointer)` but `if(myPointer == nullptr)`
* Dealing with a possible null pointer in a restricted scope could be achieved like
```
if (auto* f = getFoo())
{
    f->doSomething();
}
// f is out of scope here and a null pointer reference is impossible.
```
* If you need to reinterpret data use `reinterpret_cast` or `dynamic_cast`. No more C-style `newType myTypeVariable = (newType) myVariable`
* Using the std library versions of old C equivalents will result in polymorphic functions and hence, more readable code, for functions such as `fabs` -> use `std::abs` instead.

## Functions
* Functions should be small
* Functions should be smaller than that!
* Use a verb-ish or phrase as a descriptive name
* A function should do one thing and do it well!
    * If there are multiple if cases the function does clearly more than one thing.
* Use the the least amount of arguments
    * Rule of thumb: If the number of arguments exceed 3 make an object to group some arguments
    * Don't use `bool` flags, create a separate function as you now do 2 things
    * If you can extract a subset of calculations or else from a function then it clearly does more than one thing. Consider refactoring.
* Each function should provide one layer of abstraction
    * There should be only one `if`-clause in a function 
    * Avoid `switch` or `if-elseif-else` trains
* Don't you never ever return `nullptr`. If you do I'll find you!
* If you pass `nullptr` or `NULL` to a function/method (except lowest-level C API) I'll get really annoying and ask you yet firmly to rewrite the code. Don't let me ever discover something of that!
* Do not use output arguments that will change the argument's value.
```
// Wrong
void doSomethingWithFoo(fooType &f, operatorType op)
{
    f = ...
}

// OK
fooType doSomethingWithFoo(const fooType &f, operatorType op)
{
    fooType tmpFoo = f;
    tmpFoo 
        ...
    return tmpFoo;
}
```
* If you use `try catch` blocks make the lines within the braces `{}` a single line.
* Extract code duplication. Don't repeat yourself (D.R.Y.)


## Classes
* Classes should be small
* Classes should be smaller than that
    * No repetition, but a defined scope of responsibility
* Make your class unique in behaviour and meaningful in its method names
    * Don't write getter/setter for all your private/protected variables
    * Hide internal variable usage, don't make others dependent on your design
* Not a single method should do any [side effects](https://stackoverflow.com/questions/9563600/what-exactly-is-a-side-effect-in-c)
* Divide methods into two groups
    * Getting a value/object from a class have return values
    * Modifying internals of the class are `void`
* If you override a virtual method in a sub-class mark it with the `override` specifier and *never* give it a redundant `virtual` keyword.
    * Use `virtual` for the *base class* function declaration. This is technically necessary.
    * Use `override` (only) for a *derived class' override*. This helps maintenance.

## Comments
* Comments are good when they add valuable information to the code
    * e.g. if the code itself can't achieve something as it turns out to be massively tedious or impossible
    * use them in rare cases makes them important. Pro Tip: use signal-red for comments
    * They provide a good starting point into the code structure if this is needed
* Comments are the worst if they are just put there 
    * Do not use clutter comments
    * Lines of comments do not increase code quality!
    * What happens if dependencies changed?
    * If you comment whole sections of code other developers think it's important and won't delete the code. By that the SNR of your own code decreases.
* A good comment is either a `todo` or `fixme` or and the ones you don't have to write
* Food for thoughts should be placed somewhere else. Your VCS is not a notepad
    * If you leave those comments in the code you are responsible for cleaning them up or they will be cleaned up.
* Comments are no leaking valve for a bad day or a pun-tended source code.
* If you need to put something descriptive after a closed brace such as ` }; // for loop` consider refactoring. Because your function/method is too damn long.

## Object lifetime and ownership
* Absolutely do **not** use `delete, deleteAndZero`. Tehere are a very few situations where you can't use a smart pointer or some other automatic lifetime management class
* Do not use `new` unless there's no alternative. Whenever you type `new`, always treat it as a failure to find a better solution. If a local variable can be allocated on the stack rather than the heap, then always do so.
* Never use `new` or `malloc` to allocate a C++ array. Always prefer a sustainable container class from Boost or Juce.
* Obviously avoid static and global variables. Stometimes there's no alternative, but if there is one, use it, regardless how much effort it involves.
* Avoid `memset(), zeromem(), zerostruct()` functions and init with `= {};` initializer.

## Namespaces
* For business logic we use the `Klang::` namespace which is divided into the different layers or our software architecture. 
    * By that we may have multiple functions named the same but as they are in different namespaces they are in fact different. This approach is used by [Boost](https://www.boost.org/)

## Error Handling

## Miscellaneous
* Never put an `else` statment after a `return` as described by [LLVM](http://llvm.org/docs/CodingStandards.html#don-t-use-else-after-a-return)
* Write top-down. First the caller and then the definition of a function/method.
    * Of course this is only valid for source files where the function declaration is already done.