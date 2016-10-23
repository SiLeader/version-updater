/*
MIT License

Copyright (c) 2016 SiLeader

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include<fstream>
#include<string>
#include<iostream>
#include<vector>

namespace {
    std::vector<std::string> params(int argc, char **argv) {
        std::vector<std::string> args;
        for(int i=0; i<argc; ++i) {
            args.push_back(argv[i]);
        }
        return args;
    }
} /* noname */

int main(int argc, char **argv) {
	auto args=params(argc, argv);

	if(args.size()<2) {
		std::cout<<"Arg count"<<std::endl;
		return 1;
	}else if(args[2]=="init") {
		if(args.size()>=3){
			std::ofstream fout(args[1]+"/version.txt");
			fout<<"0\n0\n0\n0"<<std::endl;

			std::cout<<"Initialized Version Updater File"<<std::endl;
			return 0;
		}else{
			std::cout<<"Arg count (init)"<<std::endl;
			return 1;
		}
	}
	std::ifstream fin(args[1]+"/version.txt");

   	std::size_t major, minor, rev, build;
	fin>>major>>minor>>rev>>build;

	std::ofstream fout(args[1]+"/version.txt");

	if(args.size()>2) {
		if(args[2]=="major") {
			++major;
			minor=0;
			rev=0;
			std::cout<<"Major Updated"<<std::endl;
			return 0;
		}else if(args[2]=="minor") {
			++minor;
			rev=0;
			std::cout<<"Minor Updated"<<std::endl;
			return 0;
		}else if(args[2]=="rev") {
			++rev;
			std::cout<<"Revision Updated"<<std::endl;
			return 0;
		}else{
        	++build;
        }
	}else{
	    ++build;
    }
	fout
		<<major<<"\n"
		<<minor<<"\n"
		<<rev<<"\n"
		<<build
		<<std::endl;

	fout.close();
	fout.open(args[1]+"/version_vu.hpp");
	fout
		<<"/*\n"
		<<"\tVersion auto Updater (Auto generated file)\n"
		<<"\t(C) 2016 SiLeader.\n"
		<<"*/\n"
		<<"\n"
		<<"#pragma once\n\n"
		<<"#include<cstddef>\n"
		<<"namespace vu {\n"
		<<"\tconstexpr std::size_t VERSION_VU_MAJOR="<<major<<";\n"
		<<"\tconstexpr std::size_t VERSION_VU_MINOR="<<minor<<";\n"
		<<"\tconstexpr std::size_t VERSION_VU_REV="<<rev<<";\n"
		<<"\tconstexpr std::size_t VERSION_VU_BUILD="<<build<<";\n"
		<<"}"
		<<std::endl;


}
