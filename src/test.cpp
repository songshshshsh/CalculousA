#include "../include/test.h"

int doAssert(bool x, const char *file, int line)
{
	if(x)
		return 0;
	cout << "Assertion failed at file " << file << " line " << line << "\n";
	exit(1);
}

Vector<Test *> Test::tests;

void Test::runTests()
{
	for(auto test: tests)
	{
		cout << "Running test " << test->name << "\n";
		test->run();
	}
}
