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

#include "../include/Solver.h"
#include "../include/StupidStrategy.h"
#include "../include/ColumnGenSolve.h"
TEST(StupidStrategyTest)
{
	String ins =
		"10	10\n"
		"	1	3	0	0	0	0	0	0	0	0	\n"
		"	0	2	4	0	0	0	0	0	4	0	\n"
		"	0	0	0	3	0	0	0	0	0	3	\n"
		"	0	0	0	0	0	0	0	0	0	4	\n"
		"	0	0	0	0	0	0	0	0	0	0	\n"
		"	0	0	0	0	0	0	0	0	0	0	\n"
		"	0	0	0	0	0	0	0	0	0	0	\n"
		"	0	0	0	0	0	0	0	0	0	0	\n"
		"	1	0	0	0	0	0	0	0	0	0	\n"
		"	2	0	0	0	0	0	0	0	0	0	\n"
	;
	StringStream inf(ins);
	Board board;
	board.input(0, inf);
	Solver solver(&board);
	solver.setSolveStrategy(new ColumnGenSolve(&solver));
	solver.setCheckStrategy(new StupidCheck(&solver));
	solver.setOptimizeStrategy(new StupidOptimize(&solver));
	Solution solution = solver.run();
	cout << solution;
}

#include "../include/GRBFactory.h"
TEST(GurobiTest)
{
  try {
    GRBModel &model = GRBFactory::createModel();

    // Create variables

    GRBVar x1 = model.addVar(0, GRB_INFINITY, 0, GRB_CONTINUOUS, "x1");
    GRBVar x2 = model.addVar(0, GRB_INFINITY, 0, GRB_CONTINUOUS, "x2");
    // GRBVar x3 = model.addVar(0, GRB_INFINITY, 0, GRB_INTEGER, "x3");

    // Integrate new variables

    model.update();

    // Set objective: maximize x + y + 2 z

    model.setObjective(5 * x1 + 4 * x2, GRB_MAXIMIZE);

    // Add constraint: x + 2 y + 3 z <= 4

    GRBConstr c0 = model.addConstr(x1 + 3 * x2 <= 90, "c0");
    GRBConstr c1 = model.addConstr(2 * x1 + x2 <= 80, "c1");
    GRBConstr c2 = model.addConstr(x1 + x2 <= 45, "c2");

    // Optimize model

    model.optimize();

    cout << x1.get(GRB_StringAttr_VarName) << " "
         << x1.get(GRB_DoubleAttr_X) << endl;
    cout << x2.get(GRB_StringAttr_VarName) << " "
         << x2.get(GRB_DoubleAttr_X) << endl;

    cout << c0.get(GRB_StringAttr_ConstrName) << " "
         << c0.get(GRB_DoubleAttr_Pi) << endl;

    cout << c1.get(GRB_StringAttr_ConstrName) << " "
         << c1.get(GRB_DoubleAttr_Pi) << endl;

    cout << c2.get(GRB_StringAttr_ConstrName) << " "
         << c2.get(GRB_DoubleAttr_Pi) << endl;

    cout << "Obj: " << model.get(GRB_DoubleAttr_ObjVal) << endl;

  } catch(GRBException e) {
    cout << "Error code = " << e.getErrorCode() << endl;
    cout << e.getMessage() << endl;
  } catch(...) {
    cout << "Exception during optimization" << endl;
  }
}
