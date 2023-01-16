# TestSuite environment
Various metrics show that [test driven development](https://en.wikipedia.org/wiki/Test-driven_development) will speed up your coding and you have the confidence that nothing is broken. 
Otherwise your code will rod and you may not want to make any changes to the system at all. 
**When you are too afraid of changing code you have successfully reinvented hardware.**

Hence, we have to trust in our test environment to be confident about changes we do.

Whenever you discover a new bug the appropriate way to fix it is to write a failing test first and the fix afterwards. 

## Easy getting started
### cmake
The library uses [cmake](https://cmake.org/) to handle multiple toolchains or compiler settings.
You need to be *a bit* familiar with the workflow on your OS. 
It's not a mysterial _thing_ that we use but a very helpful tool to cover various cross compiler toolchains.

### TestSuite
This is a CMake project that runs all defined and linked tests provided in the modules directory.

On Mac OSX the clang compiler does not support lcov code coverage.
Make sure to disable code coverage with CMake to pass this issue.

### Writing Tests
We use [Catch2](https://github.com/catchorg/Catch2) for our test assertions and framework.
A [getting started page](https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#top) should give you all information you need to get familiar with the usage.

This project uses interfaces a lot so we are sure that responsibilities are defined by those interfaces and we may test software more easily.
For that we use mocking/stubbing with [FakeIt](https://github.com/eranpeer/FakeIt) as a standard framework.
We have that fakeIt version available in the klang_base module.

You will see various tags on the testlines such as [learningTests] or [vector]. 
If you add your own domain of tests please extend the tag list of your tests. Please add the architecture layer of the tests such as [base] or [fdsp].

# Errata
This is very similar to the [DiGiCo DMI Library](https://github.com/DigicoUK/di_con_dmi_library) test scenario and should be kept as close as possible to the library made in Chessington to maintain a similar workflow.