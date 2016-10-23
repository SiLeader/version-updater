# Version Updater
Copyright &copy; 2016 SiLeader. All rights reserved.  
Licensed under [MIT License](https://opensource.org/licenses/MIT).

## Dependent Libraries
C++ Standard Library (C++14 or more)

## Introduction
Version Updater is Auto version update tool for C++  
features
* Include one header file to use. (version_vu.hpp)
* Easy to update major version, minor version and revision.
* Auto increment build counter.

## Usage
Command list  
1. vu PATH init  
2. vu PATH  
3. vu PATH major  
4. vu PATH minor  
5. vu PATH rev  

Command description  
1. Generate Version Updater header and preference to PATH.  
2. Increment build count and generate files.  
3. Increment major version, clear minor version and revision and generate files.  
4. Increment minor version, clear revision and generate files.  
5. Increment revision and generate files.  

## Generated Files
Generate to PATH directory
### version_vu.hpp
Version Interface to C++
```c++
/*
	Version auto Updater (Auto generated file)
	(C) 2016 SiLeader.
*/

#pragma once

#include<cstddef>
namespace vu {
	constexpr std::size_t VERSION_VU_MAJOR=1;
	constexpr std::size_t VERSION_VU_MINOR=0;
	constexpr std::size_t VERSION_VU_REV=0;
	constexpr std::size_t VERSION_VU_BUILD=10;
}
```

### version.txt
preference
```
1
0
0
10
```
