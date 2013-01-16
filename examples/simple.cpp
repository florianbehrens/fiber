#include <cstdlib>
#include <iostream>
#include <string>

#include <boost/bind.hpp>

#include <boost/fiber/all.hpp>

inline
void fn( std::string const& str, int n)
{
	for ( int i = 0; i < n; ++i)
	{
		std::cout << i << ": " << str << std::endl;
		boost::this_fiber::yield();
	}
}

int main()
{
    boost::fibers::round_robin ds;
    boost::fibers::scheduling_algorithm( & ds);

	try
	{
        boost::fibers::fiber s1( boost::bind( fn, "abc", 5) );
        boost::fibers::fiber s2( boost::bind( fn, "xyz", 7) );

		while ( s1 || s2 ) boost::fibers::run();

		std::cout << "done." << std::endl;

		return EXIT_SUCCESS;
	}
	catch ( std::exception const& e)
	{ std::cerr << "exception: " << e.what() << std::endl; }
	catch (...)
	{ std::cerr << "unhandled exception" << std::endl; }
	return EXIT_FAILURE;
}