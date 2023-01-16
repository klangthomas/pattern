# Test Driven Development TDD
[Test driven development](https://en.wikipedia.org/wiki/Test-driven_development) is a whole domain of implementation strategies and test coverage of your written source code. It relies on the following steps:

* **First law** You may not write production code until you have written a failing unit test
* **Second law** You may not write more of a unit test than is sufficient to fail, and not compiling is failing
* **Third law** You may not write more production code than is sufficient to pass the currently failing test.

If you stick to those rules there will be no written line of code that is not tested.

Please note that the production code itself should not be written only that it is testable.

## BDD 
[Behavior driven development](https://en.wikipedia.org/wiki/Behavior-driven_development) may also be used with our Toolchain.
In comparison to TDD this approach will include the stakeholder into the test environment. 
Creating a narrative for a given set of tests.

# Coverage
The test suite will use code coverage to check if all lines of your production code are executed and check for potential overlooked risks. 
Whenever you commit your work onto the remote repository an automated test will be done.

There is no other number that makes any sense except 100% code coverage.
*Compare test coverage to a parachute on a sky dive: How much of the parachute do you trust?*