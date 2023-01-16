# Klang Library

Containing all business rules and logic for the software layer that is completely bounded to Klang.

## Setup
The repository itself should contain everything that is needed. Simply call the corresponding file inside the `setup/` directory after your initial checkout.

Feel free to add any other functionality to the repository such as fancy git-hooks. You got the skeleton already.

### CMake
CMake is kind of a compiler wrapping toolchain that handles the creation of makefiles and will take care of cross compiler settings.

Personal preference is to start [with a youtube video](https://www.youtube.com/watch?v=HPMvU64RUTY&vl=zh). 
Juce now supports CMake too and there are some [examples](https://github.com/juce-framework/JUCE/tree/master/examples/CMake). 
Everything else is gathered from [DiGiCo's DMI library](https://github.com/DigicoUK/di_con_dmi_library).

## Contributing to the library
If you stick to the following rules whenever you work with the Klang library we should be able to create a good software design as a side effect on the long run:
1. [Run all the tests](#Tests)
2. [Contains no duplication](#Duplication)
3. [Expresses the intent of the programmer](#Intention)
4. [Minimizes the number of classes and methods](#Refactoring)

### Tests
Modifying or adding code to the library should result into [writing tests](doc/CleanCode/TestSuite.md).
Do you want to deploy something untested and hence, a risk that something is a crucial bug?

Having a good test coverage will make you more confident in changing code. 
Don't let your tests rot or your complete code will rot too.

Writing tests is hard and getting the system to work is hard. Here are some few tips for getting started:
* Small classes are easy to test
* Try out [test driven development](doc/TestDrivenDevelopment.md) as a behaviour for writing testable code.

### Duplication
Our system is divided into separate chunks of layers all described by the [architecture](lib/README.md).
Derivation of abstract classes is a good method to keep a clean software layer on top.

Don't repeat yourself (D.R.Y.) as this increases potential bugs whenever possible. A good way to get rid of that is behavioural code that relies on templates and classes. It may be hard to read in the first place but will definately pay off.

### Intention
If you deliver some [tests](#Tests) to your code it describes the intentional usage and makes it easier for other developers to use/modify.

The next developer going through your code is most likely you. 
Keep your stuff clean and always think about others looking at the code and don't understand anything.

Write your code in a way that it would make you proud if you need to read it out loudly.

### Refactoring
We agreed onto a specified set of [Code Conventions](doc/CleanCode/CodingGuidelines.md)

Everytime you work with the library leave it cleaner than you found it. Don't be too intense on all changes but it will pay off on the long run.
# Praktikum Palenda

This repository contains the code that was writttend durin the internship of Pascal Palenda.
It contains an assortment of JUCE modules and the applications __unit_tester__ and __KLANGmeasure__.

## Build process

This project uses [CMake](https://cmake.org/) in conjunction with [CPM](https://github.com/cpm-cmake/CPM.cmake) to build its components.
As such, if your IDE supports opening CMakeLists, it is suggested to open the CMakeLists as a project and build it this way.
In case your IDE does not support this, run CMake beforehand to create a corresponding project file for your IDE.
If you intend on building the project via the command line, create a build folder, run CMake with the according generator and run `cmake --build` to build.

Note, that all required dependencies should be downloaded via CPM. Only doxygen and dot must be installed separately if the documentation should be build.

The applications can be build on their own via their corresponding CMakeLists.
However, it is suggested, to build the entire project via the main CMakeLists.

## unit_tester

This application runs all unit tests that are supplied by the JUCE modules.
Additionally, a category can be supplied via the command line interface to run only a subset of all unit tests.


