# Code Heuristics / Smells
There is no single rule that classifies if source code is good, bad or worse.
In fact you should rely on your intention as a developer and consider the following code smells as a overly defined heuristic. 

Don't take everything by their literal meaning. But if you see some code that violates many rules it may be considered to be refactored.

Everything listed is extracted from [Clean Code](https://www.amazon.de/Clean-Code-Handbook-Software-Craftsmanship/dp/0132350882) by Robert C. Martin.
If something should be refered to a given indicator please do so in your git issue ticket ;)

**Table of Contents**
* [Comments](#Comments)
* [Environment](#Environment)
* [Functions](#Functions)
* [General](#General)
* [Names](#Names)
* [Tests](#Tests)

## Comments
C1 **Inapropriate Information**: Don't clutter the code with history from the past. We use git for that and this should be the only place to look for historical code.

C2 **Obsolete Comment**: One that has gotten old, irrelevant and incorrect is obsolete. Comments get old quite quickly. If you find a C2 get rid of it or update it. Those things will become floating islands of irrelevance and misdirection

C3 **Redundant Comment**: Don't phrase something very obvious as `i++`. Comments should say things taht the code cannot say itself

C4 **Poorly Written Comment**: Take the time you need to make shure the comment is the best one you can give. Choose your words carefully and use correct language. Don't ramble, be brief.

C5 **Commented-Out Code**: Is it meaningful? Yet not one will delete it because everyone assumes someone else needs it or has plans for it. When you see commented out code, *delete it*. Don't worry, git still remembers. If anyone really needs it they may go back in time and check out a previous version. Don't suffer commented-out code to survive

## Environment
E1 **Build Requires More Than One Step**: Build a project should be a single trivial operation. It should be as simple as that: 
```
git clone myProject
cd myProject
./build.sh // Linux/OSX
./build.bat
```

E2 **Tests Require More Than One Step**: You should be able to run *all* the tests with just one command. In the best case you can run all tests by a single click in your IDE. Worst case is a single simple command in a shell. Being able to run all the tests is so fundamental and so important that it should be quick, easy and obvious to do.

## Functions
F1 **Too Many Arguments**: Functions should have a small number of arguments. More than three is very questionable and should be avoided with prejudice.

F2 **Output Arguments**; Those things are counterintuitive. Reader expect arguments to be inputs, not outputs. If your function must change the state of something, have it change the state of the object it is called on.

F3 **Flag Arguments**: Boolean arguments are the best way to say that a function does clearly more than one thing. Separate into two functions and name meaningful.

F4 **Dead Function**: Methods that are never called should be discarded. Keeping dead code around is wasteful. Don't be afraid to delete the function. You don't have to remember it, git does.

## General

G1 **Multiple Languages in One Source File**: The ideal is one language for a source file. Don't put any fancy doxygen hacks into your source code. 

G2 **Obvious Behavior is Unimplemented**: Following "The Principle of Least Surprise" any function or class should implement the behaviours that another programmer could reasonably expect. When that is not given, readers and users of the code can no longer depend on their intuition about function names. They lose their trust in the original author and must fall back on reading the details of the code.

G3 **Incorrect Behaviour at the Boundaries**: Developers often write functions that they think will work and then trust theri intuition rather than going to the effort to prove that their code works in all the corner and boundary cases. Every boundary condition, every corner case, every quirk and exception represents something that can confound an elegant and intuitive algorithm. *Don't rely on your intuition*, write a test for every boundary condition.

G4 **Overridden Safeties**: Turning off certain compiler warnings (or worse: all!) may help your get the build to succeed but at the risk of endless debugging sessions. Turning off failing tests and telling yourself you'll get them to pass later is as bad as pretending your credit cards are free money.

G5 **Duplication**: Don't_Repeat_Yourself!!! Everytime you see a duplication in the code, it represents a missed opportunity for abstraction. That duplication could probably become a  subroutine or perhaps another class outright. By folder the duplicationinto such an abstraction you increase the vocabularity of the language of your design. Other can use it easily. Even subtle form with `switch/case` or `if/else` chains are duplication, replace with polymorphism.

G6 **Code at Wrong level of Abstraction**: It is important to create abstractions that separate higher level general concepts from lower level detailed concepts. Sometimes having abstract classes this does the trick. We want *all* the lower level concepts to be in the derivatives and *all* the higher level concepts to be in the base class. Isolating abstractions is one of the hardest things that software developers do, and there is no quick fix when you get it wrong.

G7 **Base Classes Depending on Their Derivatives**: The most common reason for partitioning concepts into base and derivative classes is so that the higher level base class concepts can be independent of the lower level derivative class concepts. Therefore, when we see base classes mentioning the names of their derivatives we suspect a problem. In general, base classes shoud know nothing about their derivatives.

G8 **Too Much Information**: A well-defined interface does not offer very many functions to depend upon, so coupling is low. A poorly defined interface provides lots of functions that you must call, so coupling is high. Good software limits the expose at their interface of their classes and modules. The fewer methods a class has, the better. The fewer variables a function knows about, the better. The fewer instance variables a class has, the better. Hide your data. Hide your utility functions. Hide your constants and your temporaries. Don't create classes with lots of methods or lots of instance variables. Don't create lots of protected variables and functions for your subclasses. Concentrate on keeping interfaces very tight and small. Help keep coupling low by limiting information.

G9 **Dead Code**: Dead code is one that is not executed. The problem with dead code is that after awhile it starts to smell. The older it is, the stronger and sourer the odor becomes. This is because dead code is not completely updated when designs change. It still *compiles* but it does not follow newer conventions or rules. It was written at a time when the system was *different*. When you find dead code, do the right thing. Give it a decent burial. Delete it from the system.

G10 **Vertical Separation**: Variables and functions should be defined close to where they are used. Everything close to each other resolved in great dependency of all. The inverse is also true. Huge gaps between methods suggest they don't rely on each other.

G11 **Inconsistency**: If you do something a certain way, do all similar things in the same way. Be careful with the conventions you choose, and once chosen be carefu to continue to follow them. 

G12 **Clutter**: Of what use is a default constructor with no implementation? All it serves is to clutter up the code with meaningless artifacts. VAriables that aren't used, functions that are never called and so forth. All that should be removed. Keep you source files clean, well organized and free of clutter.

G13 **Artificial Coupling**: In general an artificial coupling is a coupling between two modules that serves no direct purpose. It is a result of putting a variable constant of function in a temporarily convenient, though inappropriate, location. Take the time to figure out where functions, constants and variables ought to be declared. Don't just toss them in the most convenient place at hand and then leave them there.

G14 **Feature envy**: The methods of a class should be interested in the variables and functions of the class they belong to, and not the variables and functions of other classes. When a method uses accessors and mutators of some other object to manipulate the data within that object, then in *envies* the scope of the class of that other object.

G15 **Selector Arguments**: There is hardly anything more abominable than a dangling `false` argument at the end of a function call. What does it mean? What would it change if it were `true`? Split that function into smaller functions that do one thing only. Of course selectors don't need to be boolean.

G16 **Obscured intent**: We want code to be as expressive as possible. Run-on expressiont, Hungarian notation and magix numbers all obscure the author's intent. It's worth taking the time to make the intent of our code visible to our readers.

G17 **Misplaced Responsibility**: The principle of least surprise strikes again. Code should be placed where a reader would naturally expect it to be. E.g `PI` should be declared where trigonometric functions are declared.

G18 **Inappropriate Static**: In general you should prefer nonstatic methods to static methods. When in doubt, make the function nonstatic. If you really want a function to be static, make sure, that there is no chance that wou'll want to to be have polymorphically.

G19 **Use Explanatory Variables**: One of the more powerful ways to make a program readable is to break the calculations up into intermediate values taht are held in variables with meaningful names. More explanatory variables are generally better than fewer. 

G20 **Function Names Should Say What They Do**: If you have to look at the implementation (or documentation) of the function to know what it soed, then you should work to find a better name or rearrange the functionality so that it can be placed in functions with better names.

G21 **Understand the algorithm**: Before you consider yourself to be done with a function, make sure you *understand* how it works. It is not good enough that is passes all the tests. You must *know* that the solution is correct. There is a difference between knowing how the code works and knowing whether the algorithm will do the job required of it. Being unsure that an algorithm is appropriate is often a fact of life. Being unsure what your code does is just laziness.

G22 **Make Logical Dependencies Physical**: If you write a class that is dependent on another don't use macros or constants from the other file but use the methods of the dependent class.

G23 **Prefer Polymorphism to If/Else or Switch/Case**: First, most people use switch statments because it's the obvious brute force solution, not because it's the right solution for the situation. So this heuristic here is to remind us to consider polymorphism before using a swich. Robert C. Martin follows the "One Switch" rule: *There may be no more than one switch statement for a given type of selection. The cases in that switch statement must create polymorphic objects that take the place of other such switch statements in the rest of the system.*

G24 **Follow Standard Conventions**: Every team should follow a coding standard based on common industry norms. This coding standard should specify things where to declare instance variables; how to name classes, methods and variables; where to put braces and so on. The team should not need a document to describe these conventions because their code provides the examples. Anyway: here are our [Code Guidelines](CodingGuidelines.md) ;) Everyone on the team should follow these conventions. Doesn't matter where you do stuff but at least do it all the same way.

G25 **Replace Magic Numbers with Named Constants**: This does not only go for datasheet implementations. The term "magic number" does not apply only to numbers. It applies to any token that has a value that is not self-describing.

G26 *Be Precise**: When you make a decision in your code, make sure you make it *precisely*. Know why you have made it and how you will deal with any exceptions. Don't be lazy about the precision of your decisions. If you decide to call a function that might return `null` check for `null`! Ambiguities and imprecision in code are either a result of disagreements or laziness. In either case they should be eliminated.

G27 **Structure over COnvention**: Enforce design decisions with structure over convention. Naming conventions are good, but they are inferiour to structure that force compliance. E.g. switch/cases with nicely named enumarations are inferiour to base classes with abstract methods. No one is forced to implement the switch/case statement the same way each time; but the base classes do enforce that concrete classes have all abstract methods implemented.

G28 **Encapsulate Conditionals**: Boolean logic is hard enough to understand withour to see it in the context of an `if` or `while` statement. Extract functions that explain the intent of the conditional.
```
if(shouldBeDeleted(timer)) // good
if(timer.hasExpired() && !timer.isRecurrent()) // nah, not so good
```

G29 **Avoid Negative Conditionals**: That will result in removing double negatives that will lead to positives. Easier to read.

G30 **Functions Should Do One Thing**: It is often tempting to create functions that multiple sections that perform a series of operations. Functions of this kind do more than *one thing*, and should be converted into many smaller functions, each of which does *one thing*.

G31 **Hidden Temporal Couplings**: Temporal couplings are often neccessary, but you should not hide the coupling. Structure the arguments of your functions such that the order in which they should be called is obvious. Instead create the functions in a way that results are passed into the next function, so there won't be a way to call them out of order.

G32 **Don't Be Arbitrary**: Have a reason for the way you structure your code, and make sure that reason is communicated by the structure of the code. If a structure appear arbitrary other will feel empowered to change it. If a structure appears consistently throughout the system, others will use it and preserve the convention.

G33 **Encapsulate Boundary Conditions**: Boundary conditions are hard to keep track of. Put the processing for them in one place. Don't let them leak all over the code.

G34 **Functions Should Descend Only One Level Of Abstraction**: The statements within a function should all be written at the same level of abstraction, which should be one level below the operation described by the name of the function. This may be the hardest of there heuristics to interpret and follow. Though the idead is plain enough, humans are just far too good at seamlessly mixing levels of abstraction.

G35 **Keep Configurable Data at High Levels**: If you have a constant such as a default or configuration value that is known and expected at a high level of abstraction, do not bury it in a low-level function. Expose it as an argument taht low-level function called from the high-level function. The configuration constants reside at a very high level and are easy to change. They get passed down to the rest of the application. The lower levels of the application do not own the values of these constants.

G36 **Avoid Transitive Navigation**: In general we don't want a single module to know much about its collaborators. More specificially, if `A` collaborates with `B` and `B` collaborates with `C`, we don't want modules that use `A` to know about `C` - avoiding train wrecks like `a.getB().getC().doSomething();`. This is sometime called the *Law of Demeter**: Make sure that modules know only about their immediate collaborators and do not know the navigation map of the whole system. What would happen if you put `Q` between `B` and `C`? - You need to update every function call to `a.getB().getQ().getC().doSomething();`. Rather say: `myCollaborator.doSomething();`

## Names

N1 **Choose Descriptive Names**: Dont be too quick to choose a name and make sure it's descriptive. Remember that meanings tend to drift as software evolves. Frequently reevaluate the appropriateness of the names you choose. This is not a "feel-good" recommendation. Names in software are 90% of what makes software readable. Names are too important to treat carelessly.

N2 **Choose Names at the Appropriate Level of Abstraction**: Don't pick names that communicate implementation; choose names that reflect the level of abstraction of the class or function you are working in. This is hard to do.

N3 **Use Standard Nomenclature Where Possible**: Names are easier to understand if they are based on existing convention or usage. Teams will often invent their on standard system of names for a particular project. The more you can use names that are overloaded with special meanings that are relevant to your project, the easier it will be for readers to know what your code is talking about.

N4 **Unambigous Names**: Choose names that make the workings of a function or variable unambigous. Even a precise name outweighs its potential length.

N5 **Use Long Names for Long Scopes**: The length of a name should be related to the length of the scope. You can use very short variable names for tiny scopes, but for big scopes you should use longer names. 

N6 **Avoid Encodings**: Kepp your names free of hungarian pollution.

N7 **Names Should Describe Side Effects**: Names should describe everything that a function, variable of class is or does. DOn't use a simple verb to describe a function that does more than just a simple action.

## Tests

T1 **Insufficient Tests**: How many tests should be in a test suite? Unfortunately the metric many programmers use is "That seems like enough". A test suite should test everything that could possibly break. The tests are insufficient so long as there are conditions that have not been explored by the tests or calculations that have not been validated.

T2 **Use a Coverage Tool!** Coverage tools reports gaps in your testing strategy. Thay make it easy to find modules, classes and functions that are insufficiently testes. There is no other number that makes any sense at all except 100% code coverage. That to archieve is very hard but on the other hand you might suggest that x% of your code does not work properly. 

T3 **Don't Skip Trivial Tests**: They are easy to write and their documentary value is higher than the cost to produce them.

T4 **An Ignored Test Is A Question about an Ambiguity**: Sometimes we are uncertain about a behavioral detail because the requirements are unclear. We can express our question about the requirements as a test that is commented out, or as a test that is annotated with @Ignore. Which you choose dependts upon whether the ambiguity is about something that would compile or not.

T5 **Test Boundary Conditions**: Take special care to test boundary conditions. We often get the middle out of an algorithm but might misjudge the boundaties

T6 **Exhaustively Test Near Bugs**: Bugs tend to congregate. When you find a bug in a function, it is wise to do an exhaustive test of that function. You'll probably find that the bus was not alone.

T7 **Patterns of Failure Are Revealing**: Sometimse you can diagnose a problem by finding patterns in the way the test cases fail. This is another argument for making the test cases as complete as possible. Complete test cases, ordered in a reasonable way, expose patterns.

T8 **Test Coverage Patterns Can be Revealing**: Looking at the code that is or is not executed by the passing tests gives clues to why the tests fail.

T9 **Tests should be fast**: A slow test is a test that won't get run. When things get tight, it's the slow test that will be dropped from the suite. So *do what you must* to keep your tests fast.