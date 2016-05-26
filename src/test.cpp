#include "../include/test.h"

Vector<Test *> Test::tests;

void Test::runTests()
{
	for(auto test: tests)
	{
		cout << "Running test " << test->name << "\n";
		test->run();
	}
}
