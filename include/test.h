#ifndef TEST_H
#define TEST_H

#include "global.h"

int doAssert(bool, const char *file, int line);
#ifdef ENABLE_ASSERT
#define assert(x) doAssert((x), __FILE__, __LINE__)
#else
#define assert(x) 0
#endif // ENABLE_ASSERT

class Test
{
private:
	static Vector<Test *> tests;
	Test &operator =(const Test &);
protected:
	Test(const char *name_): name(name_)
	{
		tests.push_back(this);
	}
	const char *const name;
	virtual void run() const = 0;
public:
	virtual ~Test(){}
	static void runTests();
};

#endif // TEST_H
