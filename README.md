# Algorithms Workbench

## Overview
This repo is a slate to various algorithm implementations.

## Build Instructions
* Create a new directory, **build**
* Cd into **build**, run **cmake ..**
* Run **make**, after the above command completes
* Targets are copied over to **{Project.Dir}/bin/{Target}/aw**
* Test target is copied to **{Project.Dir}/bin/test/aw_tests**

## Pre-requisites
* C++11 compiler. gcc/clang/vc++ later versions support C++11 features. To install one, either build from source or use a package manager for your platform
* CMake. Version 3.7.0 or greater. The project uses CMake to generate the build files  

## Tests
Tests are implemented with the help of the [Catch](https://github.com/philsquared/Catch) test framework.

## License
Free as in free speech.

## Contributions & Questions
Send me a mail on <raj@diskodev.com> or tweet me at <https://twitter.com/#!/rajkumar_p>