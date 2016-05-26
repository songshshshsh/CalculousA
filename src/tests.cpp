#include "../include/test.h"

#define TEST(testname)                      \
	class testname: public Test             \
	{                                       \
	private:                                \
		static Test *instance;              \
	protected:                              \
		testname(): Test(#testname){}       \
		virtual void run() const;           \
	};                                      \
	Test *testname::instance = new testname;\
	void testname::run() const

TEST(PlusTest)
{
	assert(1 + 1 == 2);
	assert(1 + 2 != 4);
}

#include "../include/BitMatrix.h"
TEST(BitMatrixTest)
{
	BitMatrix bmx(2, 3);
	cout << bmx;
	bmx.set(1, 2);
	cout << bmx;
	bmx.set(1, 0);
	cout << bmx;
	bmx.reset(1, 0);
	cout << bmx;
}

#include "../include/Board.h"
TEST(BoardIOTest)
{
	String ins =
		"3 4\n"
		"0 -1 1 2 \n"
		"2 0 -1 2 \n"
		"3 4 2 2 \n"
	;
	StringStream inf(ins);
	StringStream ouf, ouf1, ouf2;
	Board board;
	board.input(0, inf);
	board.output(0, ouf);
	assert(ins == ouf.str());
	board.output(1, ouf1);
	Board board1;
	board1.input(1, ouf1);
	board1.output(1,ouf2);
	assert(ouf1.str() == ouf2.str());
}
