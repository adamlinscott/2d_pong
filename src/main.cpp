// tag::C++11check[]
#define STRING2(x) #x
#define STRING(x) STRING2(x)

#if __cplusplus < 201103L
	#pragma message("WARNING: the compiler may not be C++11 compliant. __cplusplus version is : " STRING(__cplusplus))
#endif
// end::C++11check[]


#include "Pong.hpp"

#include <iostream>
#include <algorithm>

// tag::main[]
int main( int argc, char* args[] )
{
	std::string exeName = args[0];
	//get executable name, and use as window title
	int beginIdxWindows = exeName.rfind("\\"); //find last occurrence of a backslash
	int beginIdxLinux = exeName.rfind("/"); //find last occurrence of a forward slash
	int beginIdx = std::max(beginIdxWindows, beginIdxLinux);
	std::string exeNameEnd = exeName.substr(beginIdx + 1);

	Pong pong = Pong(exeNameEnd);
	std::cout << argc;
	if (argc > 1)
	{
		pong.run_once();

		std::cout << "Press Enter";
		std::cin.get() ;
	}
	else
	{
		pong.run();
	}

	return 0;
}
