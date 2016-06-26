# CalculousA

hahaha test commit 233

300 * 300, 10 sets, 3 terminals per set, 0 obstacles, 72.562s, 9 sets, 3490 grids

300 * 300, 10 sets, 3 terminals per set, 10000 obstacles, 95.673s, 9 sets, 3494 grids

300 * 300, 10 sets, 3 terminals per set, 20000 obstacles, 135.041s, 9 sets, 4060 grids

400 * 400, 10 sets, 3 terminals per set, 10000 obstacles, 323.812s, 10 sets, 6693 grids

300 * 300, 100 sets, 3 terminals per set, 10000 obstacles, 27m24.842s, 24 sets, 7385 grids

300 * 300, 10 sets, 5 terminals per set, 10000 obstacles, 90.156s, 5 sets, 2817 grids

300 * 300, 10 sets, 10 terminals per set, 10000 obstacles, 736.371s, 4 sets, 3735 grids

300 * 300, 30 sets, 3 terminals per set, 10000 obstacles, 25m8.331s, 19 sets, 6783 grids

350 * 350, 10 sets, 3 terminals per set, 10000 obstacles, 159.130s, 9 sets, 4481 grids

350 * 350, 10 sets, 5 terminals per set, 10000 obstacles, 258.372s, 7 sets, 5387 grids


Concrete information:

songshihongdeMacBook-Pro:calculousA songshihong$ time ./main.exe
Running test LargeTest2
solving subproblem 300 * 300
iteration 0
current time: 9 seconds
curAns 900000
column sizes:
1 1 1 1 1 1 1 1 1 1
successfully routed 0 sets of terminals with 0 grids
picture saved to 20160626143337_0009264702.bmp
iteration 1
current time: 31 seconds
curAns 540987
column sizes:
3 2 2 2 2 2 2 3 3 2
successfully routed 4 sets of terminals with 987 grids
picture saved to 20160626143346_0031083121.bmp
iteration 2
current time: 55 seconds
curAns 361729
column sizes:
5 4 3 3 3 3 4 5 4 3
successfully routed 6 sets of terminals with 1729 grids
picture saved to 20160626143356_0055790015.bmp
iteration 3
current time: 83 seconds
curAns 272205
column sizes:
6 5 6 4 4 4 6 7 6 4
successfully routed 7 sets of terminals with 2205 grids
picture saved to 20160626143407_0083928264.bmp
iteration 4
current time: 115 seconds
curAns 182738
column sizes:
8 5 8 7 6 5 9 7 7 5
successfully routed 8 sets of terminals with 2738 grids
picture saved to 20160626143419_0115210330.bmp
iteration 5
current time: 150 seconds
curAns 93490
column sizes:
9 5 9 10 7 6 9 7 9 8
successfully routed 9 sets of terminals with 3490 grids
picture saved to 20160626143433_0150161860.bmp
successfully routed 9 sets of terminals with 3490 grids
picture saved to 20160626143446_0183929151.bmp
Test LargeTest2 finished in 183.943 seconds.

real	1m12.562s
user	3m1.582s
sys	0m2.373s
songshihongdeMacBook-Pro:calculousA songshihong$ make
g++ -Wall -std=c++11 -O3 src/tests.cpp -c -o build/tests.obj
g++ -Wall -std=c++11 -O3 build/BitMatrix.obj build/Board.obj build/CleverOptimizie.obj build/ColumnGenSolve.obj build/DACSolve.obj build/GRBFactory.obj build/Solution.obj build/SolveStrategy.obj build/Solver.obj build/StupidStrategy.obj build/TerminalSet.obj build/Tree.obj build/global.obj build/main.obj build/test.obj build/tests.obj build/thread.obj libgurobi_c++.a -lgurobi65 -o main.exe
songshihongdeMacBook-Pro:calculousA songshihong$ time ./main.exe
Running test LargeTest2
solving subproblem 300 * 300
iteration 0
current time: 11 seconds
curAns 900000
column sizes:
1 1 1 1 1 1 1 1 1 1
successfully routed 0 sets of terminals with 0 grids
picture saved to 20160626143712_0011457631.bmp
iteration 1
current time: 32 seconds
curAns 540894
column sizes:
4 4 2 2 4 2 2 2 4 2
successfully routed 4 sets of terminals with 894 grids
picture saved to 20160626143721_0032903115.bmp
iteration 2
current time: 58 seconds
curAns 451219
column sizes:
7 7 3 3 7 3 3 5 7 3
successfully routed 5 sets of terminals with 1219 grids
picture saved to 20160626143731_0058121666.bmp
iteration 3
current time: 86 seconds
curAns 361680
column sizes:
10 10 4 4 10 4 6 8 10 4
successfully routed 6 sets of terminals with 1680 grids
picture saved to 20160626143743_0086933274.bmp
iteration 4
current time: 119 seconds
curAns 272172
column sizes:
13 12 7 5 13 5 8 11 12 5
successfully routed 7 sets of terminals with 2172 grids
picture saved to 20160626143756_0119819402.bmp
iteration 5
current time: 156 seconds
curAns 182718
column sizes:
15 14 10 8 16 6 10 14 15 6
successfully routed 8 sets of terminals with 2718 grids
picture saved to 20160626143811_0157026564.bmp
iteration 6
current time: 198 seconds
curAns 93494
column sizes:
18 15 13 9 19 7 12 16 17 9
successfully routed 9 sets of terminals with 3494 grids
picture saved to 20160626143827_0198479288.bmp
successfully routed 9 sets of terminals with 3494 grids
picture saved to 20160626143843_0238039806.bmp
Test LargeTest2 finished in 238.056 seconds.

real	1m35.673s
user	3m55.272s
sys	0m2.799s
songshihongdeMacBook-Pro:calculousA songshihong$ make
g++ -Wall -std=c++11 -O3 src/tests.cpp -c -o build/tests.obj
g++ -Wall -std=c++11 -O3 build/BitMatrix.obj build/Board.obj build/CleverOptimizie.obj build/ColumnGenSolve.obj build/DACSolve.obj build/GRBFactory.obj build/Solution.obj build/SolveStrategy.obj build/Solver.obj build/StupidStrategy.obj build/TerminalSet.obj build/Tree.obj build/global.obj build/main.obj build/test.obj build/tests.obj build/thread.obj libgurobi_c++.a -lgurobi65 -o main.exe
songshihongdeMacBook-Pro:calculousA songshihong$ time ./main.exe
Running test LargeTest2
solving subproblem 300 * 300
iteration 0
current time: 11 seconds
curAns 900000
column sizes:
1 1 1 1 1 1 1 1 1 1
successfully routed 0 sets of terminals with 0 grids
picture saved to 20160626143926_0011916806.bmp
iteration 1
current time: 33 seconds
curAns 540955
column sizes:
4 4 2 2 4 2 2 2 4 2
successfully routed 4 sets of terminals with 955 grids
picture saved to 20160626143935_0034025333.bmp
iteration 2
current time: 58 seconds
curAns 451301
column sizes:
7 7 3 3 7 3 3 5 7 3
successfully routed 5 sets of terminals with 1301 grids
picture saved to 20160626143945_0058657796.bmp
iteration 3
current time: 88 seconds
curAns 361701
column sizes:
10 10 6 4 9 4 4 8 10 4
successfully routed 6 sets of terminals with 1701 grids
picture saved to 20160626143957_0088953992.bmp
iteration 4
current time: 124 seconds
curAns 272260
column sizes:
12 13 7 5 12 5 7 9 13 5
successfully routed 7 sets of terminals with 2260 grids
picture saved to 20160626144012_0124573574.bmp
iteration 5
current time: 162 seconds
curAns 182834
column sizes:
15 16 10 8 14 6 10 11 15 6
successfully routed 8 sets of terminals with 2834 grids
picture saved to 20160626144027_0163052241.bmp
iteration 6
current time: 206 seconds
curAns 94074
column sizes:
18 17 13 11 17 7 13 13 18 9
successfully routed 9 sets of terminals with 4074 grids
picture saved to 20160626144045_0206962233.bmp
iteration 7
current time: 248 seconds
curAns 94065
column sizes:
21 19 15 14 18 8 15 13 20 12
successfully routed 9 sets of terminals with 4065 grids
picture saved to 20160626144102_0248760902.bmp
iteration 8
current time: 289 seconds
curAns 94060
column sizes:
24 22 17 17 19 9 17 15 22 15
successfully routed 9 sets of terminals with 4060 grids
picture saved to 20160626144118_0290132873.bmp
successfully routed 9 sets of terminals with 4060 grids
picture saved to 20160626144136_0334192524.bmp
Test LargeTest2 finished in 334.218 seconds.

real	2m15.041s
user	5m30.649s
sys	0m3.585s
songshihongdeMacBook-Pro:calculousA songshihong$ make
g++ -Wall -std=c++11 -O3 src/tests.cpp -c -o build/tests.obj
g++ -Wall -std=c++11 -O3 build/BitMatrix.obj build/Board.obj build/CleverOptimizie.obj build/ColumnGenSolve.obj build/DACSolve.obj build/GRBFactory.obj build/Solution.obj build/SolveStrategy.obj build/Solver.obj build/StupidStrategy.obj build/TerminalSet.obj build/Tree.obj build/global.obj build/main.obj build/test.obj build/tests.obj build/thread.obj libgurobi_c++.a -lgurobi65 -o main.exe
songshihongdeMacBook-Pro:calculousA songshihong$ time ./main.exe
Running test LargeTest2
solving subproblem 400 * 400
iteration 0
current time: 22 seconds
curAns 1.6e+06
column sizes:
1 1 1 1 1 1 1 1 1 1
successfully routed 0 sets of terminals with 0 grids
picture saved to 20160626144238_0022637244.bmp
iteration 1
current time: 68 seconds
curAns 961786
column sizes:
2 2 4 2 4 4 4 2 2 2
successfully routed 4 sets of terminals with 1786 grids
picture saved to 20160626144256_0068755157.bmp
iteration 2
current time: 137 seconds
curAns 483572
column sizes:
5 3 7 5 7 7 7 3 5 3
successfully routed 7 sets of terminals with 3572 grids
picture saved to 20160626144325_0137376754.bmp
iteration 3
current time: 210 seconds
curAns 324566
column sizes:
6 6 10 8 9 8 9 6 8 6
successfully routed 8 sets of terminals with 4566 grids
picture saved to 20160626144354_0210128915.bmp
iteration 4
current time: 289 seconds
curAns 165732
column sizes:
7 9 13 11 12 11 12 9 11 8
successfully routed 9 sets of terminals with 5732 grids
picture saved to 20160626144425_0289914974.bmp
iteration 5
current time: 369 seconds
curAns 165417
column sizes:
10 12 16 12 15 12 15 12 14 11
successfully routed 9 sets of terminals with 5417 grids
picture saved to 20160626144457_0370038996.bmp
iteration 6
current time: 453 seconds
curAns 165133
column sizes:
13 14 19 14 18 13 18 15 16 13
successfully routed 9 sets of terminals with 5133 grids
picture saved to 20160626144530_0453847278.bmp
iteration 7
current time: 536 seconds
curAns 165102
column sizes:
16 16 21 15 21 14 20 17 19 16
successfully routed 9 sets of terminals with 5102 grids
picture saved to 20160626144603_0536742807.bmp
iteration 8
current time: 625 seconds
curAns 6695
column sizes:
19 18 23 16 23 17 22 19 21 19
successfully routed 10 sets of terminals with 6695 grids
picture saved to 20160626144639_0625872254.bmp
iteration 9
current time: 718 seconds
curAns 6693
column sizes:
22 19 25 17 26 20 24 22 24 22
successfully routed 10 sets of terminals with 6693 grids
picture saved to 20160626144715_0718602966.bmp
successfully routed 10 sets of terminals with 6693 grids
picture saved to 20160626144752_0812228223.bmp
Test LargeTest2 finished in 812.261 seconds.

real	5m23.812s
user	13m22.477s
sys	0m9.806s
songshihongdeMacBook-Pro:calculousA songshihong$ make
g++ -Wall -std=c++11 -O3 src/tests.cpp -c -o build/tests.obj
g++ -Wall -std=c++11 -O3 build/BitMatrix.obj build/Board.obj build/CleverOptimizie.obj build/ColumnGenSolve.obj build/DACSolve.obj build/GRBFactory.obj build/Solution.obj build/SolveStrategy.obj build/Solver.obj build/StupidStrategy.obj build/TerminalSet.obj build/Tree.obj build/global.obj build/main.obj build/test.obj build/tests.obj build/thread.obj libgurobi_c++.a -lgurobi65 -o main.exe
songshihongdeMacBook-Pro:calculousA songshihong$ time ./main.exe
Running test LargeTest2
solving subproblem 300 * 300
iteration 0
current time: 107 seconds
curAns 9e+06
column sizes:
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
successfully routed 0 sets of terminals with 0 grids
picture saved to 20160626144857_0107827644.bmp
iteration 1
current time: 260 seconds
curAns 8.10184e+06
column sizes:
2 2 2 2 4 2 2 2 2 2 2 2 2 2 2 2 2 4 2 2 2 2 2 4 2 2 2 2 2 2 2 4 2 2 4 2 2 2 2 2 2 2 2 2 4 2 2 2 2 2 2 2 2 2 2 2 4 2 2 2 4 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 4 2 2 2 2 2 2 2 2 2 2 2 2 4 2 2 2 2 2 2 2
successfully routed 10 sets of terminals with 1835 grids
picture saved to 20160626144958_0260763841.bmp
iteration 2
current time: 503 seconds
curAns 7.56373e+06
column sizes:
3 5 3 3 5 3 3 3 3 3 5 3 3 3 3 3 3 7 3 3 3 3 3 7 3 3 3 3 3 5 3 7 3 3 5 3 3 3 3 3 3 3 3 3 7 3 3 3 3 3 3 3 3 3 3 3 7 3 3 3 6 3 3 3 3 3 3 3 3 3 3 3 5 3 5 3 3 3 3 7 3 3 3 3 3 3 3 3 3 3 3 3 5 3 3 3 3 3 3 5
successfully routed 16 sets of terminals with 3734 grids
picture saved to 20160626145132_0503671077.bmp
iteration 3
current time: 1071 seconds
curAns 7.29473e+06
column sizes:
4 8 4 4 8 4 4 4 4 4 7 4 4 4 4 4 4 10 4 4 4 4 4 10 4 6 4 4 4 8 4 9 4 4 8 4 4 4 4 4 4 6 4 4 9 4 4 4 4 4 4 4 4 4 4 4 10 4 4 4 9 4 6 4 4 4 4 4 4 4 4 4 8 4 8 4 4 4 4 10 4 4 4 4 4 4 4 4 4 4 4 4 8 4 4 4 4 4 4 8
successfully routed 19 sets of terminals with 4734 grids
picture saved to 20160626145505_1071931749.bmp
iteration 4
current time: 2089 seconds
curAns 7.02625e+06
column sizes:
5 11 5 5 11 5 5 5 5 5 10 5 5 5 5 5 5 13 5 5 5 5 5 13 5 9 5 5 5 10 5 12 5 5 11 5 5 5 5 5 5 9 5 5 12 5 5 5 5 5 5 5 5 5 5 5 13 5 7 5 12 5 9 5 5 5 5 5 5 5 5 5 11 5 11 5 5 5 7 13 5 5 5 5 5 5 5 5 5 7 5 5 10 5 5 5 5 5 5 11
successfully routed 22 sets of terminals with 6254 grids
picture saved to 20160626150113_2089295103.bmp
iteration 5
current time: 4463 seconds
curAns 6.84738e+06
column sizes:
8 12 6 6 14 6 6 6 6 6 11 7 6 6 6 6 6 16 6 6 6 6 6 15 6 12 6 8 6 13 6 15 6 6 13 6 6 6 6 6 6 12 6 6 15 6 6 6 6 6 6 6 6 6 6 6 16 6 8 6 14 6 12 6 6 6 6 6 6 6 6 8 14 6 14 6 6 6 8 16 6 8 6 6 6 6 6 6 6 10 6 6 12 6 6 6 6 6 6 14
successfully routed 24 sets of terminals with 7385 grids
picture saved to 20160626151531_0168345710.bmp
^C

real	27m24.842s
user	74m16.732s
sys	0m25.009s
songshihongdeMacBook-Pro:calculousA songshihong$ make
g++ -Wall -std=c++11 -O3 src/tests.cpp -c -o build/tests.obj
g++ -Wall -std=c++11 -O3 build/BitMatrix.obj build/Board.obj build/CleverOptimizie.obj build/ColumnGenSolve.obj build/DACSolve.obj build/GRBFactory.obj build/Solution.obj build/SolveStrategy.obj build/Solver.obj build/StupidStrategy.obj build/TerminalSet.obj build/Tree.obj build/global.obj build/main.obj build/test.obj build/tests.obj build/thread.obj libgurobi_c++.a -lgurobi65 -o main.exe
songshihongdeMacBook-Pro:calculousA songshihong$ time ./main.exe
Running test LargeTest2
solving subproblem 300 * 300
iteration 0
current time: 25 seconds
curAns 900000
column sizes:
1 1 1 1 1 1 1 1 1 1
successfully routed 0 sets of terminals with 0 grids
picture saved to 20160626151716_0025194423.bmp
iteration 1
current time: 55 seconds
curAns 720811
column sizes:
2 4 2 2 2 2 3 2 2 2
successfully routed 2 sets of terminals with 811 grids
picture saved to 20160626151730_0056024997.bmp
iteration 2
current time: 103 seconds
curAns 542004
column sizes:
5 7 4 3 3 3 6 3 3 3
successfully routed 4 sets of terminals with 2004 grids
picture saved to 20160626151751_0103794237.bmp
iteration 3
current time: 152 seconds
curAns 452817
column sizes:
8 10 6 4 4 6 8 4 4 4
successfully routed 5 sets of terminals with 2817 grids
picture saved to 20160626151812_0152479807.bmp
successfully routed 5 sets of terminals with 2817 grids
picture saved to 20160626151835_0204092109.bmp
Test LargeTest2 finished in 204.116 seconds.

real	1m30.156s
user	3m20.703s
sys	0m3.429s
songshihongdeMacBook-Pro:calculousA songshihong$ make
g++ -Wall -std=c++11 -O3 src/tests.cpp -c -o build/tests.obj
g++ -Wall -std=c++11 -O3 build/BitMatrix.obj build/Board.obj build/CleverOptimizie.obj build/ColumnGenSolve.obj build/DACSolve.obj build/GRBFactory.obj build/Solution.obj build/SolveStrategy.obj build/Solver.obj build/StupidStrategy.obj build/TerminalSet.obj build/Tree.obj build/global.obj build/main.obj build/test.obj build/tests.obj build/thread.obj libgurobi_c++.a -lgurobi65 -o main.exe
songshihongdeMacBook-Pro:calculousA songshihong$ time ./main.exe
Running test LargeTest2
solving subproblem 300 * 300
iteration 0
current time: 148 seconds
curAns 900000
column sizes:
1 1 1 1 1 1 1 1 1 1
successfully routed 0 sets of terminals with 0 grids
picture saved to 20160626152036_0149051571.bmp
iteration 1
current time: 293 seconds
curAns 810669
column sizes:
2 2 2 2 2 4 2 2 2 2
successfully routed 1 sets of terminals with 669 grids
picture saved to 20160626152146_0293734102.bmp
iteration 2
current time: 461 seconds
curAns 721499
column sizes:
3 5 3 3 3 7 3 3 3 3
successfully routed 2 sets of terminals with 1499 grids
picture saved to 20160626152306_0461349728.bmp
iteration 3
current time: 611 seconds
curAns 632499
column sizes:
4 8 4 4 4 10 6 4 4 4
successfully routed 3 sets of terminals with 2499 grids
picture saved to 20160626152417_0611373759.bmp
iteration 4
current time: 772 seconds
curAns 632498
column sizes:
4 10 5 5 5 13 9 5 5 5
successfully routed 3 sets of terminals with 2498 grids
picture saved to 20160626152534_0772769440.bmp
iteration 5
current time: 967 seconds
curAns 543746
column sizes:
5 13 6 6 6 16 12 6 6 8
successfully routed 4 sets of terminals with 3746 grids
picture saved to 20160626152707_0967441030.bmp
iteration 6
current time: 1163 seconds
curAns 543741
column sizes:
6 16 7 7 7 19 15 7 7 11
successfully routed 4 sets of terminals with 3741 grids
picture saved to 20160626152840_1163644297.bmp
iteration 7
current time: 1357 seconds
curAns 543735
column sizes:
7 19 8 8 8 22 18 8 8 14
successfully routed 4 sets of terminals with 3735 grids
picture saved to 20160626153013_1357602309.bmp
successfully routed 4 sets of terminals with 3735 grids
picture saved to 20160626153140_1542249649.bmp
Test LargeTest2 finished in 1542.29 seconds.

real	12m16.371s
user	25m20.124s
sys	0m22.192s
songshihongdeMacBook-Pro:calculousA songshihong$ make
g++ -Wall -std=c++11 -O3 src/tests.cpp -c -o build/tests.obj
g++ -Wall -std=c++11 -O3 build/BitMatrix.obj build/Board.obj build/CleverOptimizie.obj build/ColumnGenSolve.obj build/DACSolve.obj build/GRBFactory.obj build/Solution.obj build/SolveStrategy.obj build/Solver.obj build/StupidStrategy.obj build/TerminalSet.obj build/Tree.obj build/global.obj build/main.obj build/test.obj build/tests.obj build/thread.obj libgurobi_c++.a -lgurobi65 -o main.exe
songshihongdeMacBook-Pro:calculousA songshihong$ time ./main.exe
Running test LargeTest2
solving subproblem 300 * 300
iteration 0
current time: 31 seconds
curAns 2.7e+06
column sizes:
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
successfully routed 0 sets of terminals with 0 grids
picture saved to 20160626153404_0031532654.bmp
iteration 1
current time: 82 seconds
curAns 2.07153e+06
column sizes:
2 2 2 2 4 2 2 2 2 2 3 2 4 2 2 2 4 4 2 2 2 2 2 4 2 2 2 2 2 4
successfully routed 7 sets of terminals with 1528 grids
picture saved to 20160626153424_0082876123.bmp
iteration 2
current time: 149 seconds
curAns 1.71288e+06
column sizes:
5 5 3 3 7 3 3 5 4 3 4 3 7 3 3 3 7 6 3 3 3 3 3 7 3 3 3 3 3 7
successfully routed 11 sets of terminals with 2883 grids
picture saved to 20160626153451_0149317820.bmp
iteration 3
current time: 224 seconds
curAns 1.53375e+06
column sizes:
8 8 4 4 10 4 6 8 7 4 6 4 10 4 4 4 10 9 4 4 4 4 4 10 4 4 4 6 4 10
successfully routed 13 sets of terminals with 3748 grids
picture saved to 20160626153521_0224850227.bmp
iteration 4
current time: 329 seconds
curAns 1.26508e+06
column sizes:
11 11 5 5 12 5 9 10 9 5 8 5 12 5 7 5 12 12 7 5 7 5 5 13 5 7 5 7 5 13
successfully routed 16 sets of terminals with 5082 grids
picture saved to 20160626153602_0329430758.bmp
iteration 5
current time: 440 seconds
curAns 1.26494e+06
column sizes:
14 13 6 6 15 6 12 13 12 6 9 6 13 6 9 6 14 13 10 6 10 6 6 14 6 10 6 8 6 15
successfully routed 16 sets of terminals with 4939 grids
picture saved to 20160626153646_0440539050.bmp
iteration 6
current time: 557 seconds
curAns 1.26494e+06
column sizes:
17 15 7 7 17 7 15 15 14 7 10 7 15 7 10 7 16 14 13 7 13 7 7 15 7 13 7 9 6 18
successfully routed 16 sets of terminals with 4938 grids
picture saved to 20160626153731_0557535992.bmp
iteration 7
current time: 686 seconds
curAns 1.26494e+06
column sizes:
19 18 8 8 19 8 18 18 16 8 11 8 18 8 12 8 19 15 16 8 16 8 8 16 8 16 8 10 7 20
successfully routed 16 sets of terminals with 4935 grids
picture saved to 20160626153820_0686623203.bmp
iteration 8
current time: 830 seconds
curAns 1.17557e+06
column sizes:
22 20 9 9 21 9 21 21 19 9 12 9 19 11 12 9 22 16 17 9 19 9 9 17 9 19 9 13 8 23
successfully routed 17 sets of terminals with 5573 grids
picture saved to 20160626153915_0830702573.bmp
iteration 9
current time: 982 seconds
curAns 1.08606e+06
column sizes:
25 20 10 10 23 10 24 24 22 10 13 10 22 14 13 10 24 17 20 10 22 10 10 17 10 22 10 16 9 25
successfully routed 18 sets of terminals with 6063 grids
picture saved to 20160626154013_0983036537.bmp
iteration 10
current time: 1165 seconds
curAns 996884
column sizes:
28 22 11 11 24 11 27 27 25 11 15 11 23 17 13 11 26 20 22 11 24 11 11 19 12 25 11 19 10 28
successfully routed 19 sets of terminals with 6884 grids
picture saved to 20160626154122_1165279762.bmp
iteration 11
current time: 1364 seconds
curAns 996882
column sizes:
31 25 11 12 25 12 30 28 28 12 16 12 26 20 15 12 28 20 25 12 27 12 12 22 15 27 12 21 11 31
successfully routed 19 sets of terminals with 6882 grids
picture saved to 20160626154236_1364928554.bmp
iteration 12
current time: 1576 seconds
curAns 996880
column sizes:
34 25 11 13 28 13 33 28 31 13 18 13 26 23 16 13 30 22 28 13 30 12 13 24 17 30 13 24 12 34
successfully routed 19 sets of terminals with 6880 grids
picture saved to 20160626154356_1576818538.bmp
iteration 13
current time: 1802 seconds
curAns 996865
column sizes:
37 27 12 14 30 14 36 30 33 14 20 14 28 25 17 14 32 23 30 14 33 13 14 26 19 33 14 27 13 37
successfully routed 19 sets of terminals with 6865 grids
picture saved to 20160626154520_1802930463.bmp
iteration 14
current time: 2058 seconds
curAns 996875
column sizes:
40 29 12 15 32 15 39 31 35 15 22 15 30 27 18 15 34 25 32 15 35 14 15 28 22 36 15 29 14 40
successfully routed 19 sets of terminals with 6875 grids
picture saved to 20160626154655_2059028839.bmp
iteration 15
current time: 2348 seconds
curAns 996801
column sizes:
43 31 13 16 34 16 42 34 38 16 23 16 32 30 21 16 37 27 35 16 37 17 16 29 25 39 16 32 15 42
successfully routed 19 sets of terminals with 6801 grids
picture saved to 20160626154842_-1946536364.bmp
iteration 16
current time: 2670 seconds
curAns 996793
column sizes:
46 31 14 17 35 17 45 35 41 17 24 17 34 33 23 17 39 30 37 17 40 20 16 30 28 40 17 35 16 44
successfully routed 19 sets of terminals with 6793 grids
picture saved to 20160626155039_-1624086993.bmp
iteration 17
current time: 3035 seconds
curAns 996787
column sizes:
49 31 15 18 35 18 48 36 44 18 25 18 34 36 24 18 41 32 40 18 42 23 17 31 31 43 18 37 17 47
successfully routed 19 sets of terminals with 6787 grids
picture saved to 20160626155253_-1258872162.bmp
iteration 18
current time: 3457 seconds
curAns 996783
column sizes:
52 34 16 19 36 19 51 38 47 19 26 19 36 39 25 19 44 34 42 19 45 26 18 32 33 45 19 39 18 49
successfully routed 19 sets of terminals with 6783 grids
picture saved to 20160626155527_-836911299.bmp
successfully routed 19 sets of terminals with 6783 grids
picture saved to 20160626155859_-241722347.bmp
Test LargeTest2 finished in 4053.28 seconds.

real	25m8.331s
user	66m59.943s
sys	0m33.361s
songshihongdeMacBook-Pro:calculousA songshihong$ make
g++ -Wall -std=c++11 -O3 src/tests.cpp -c -o build/tests.obj
g++ -Wall -std=c++11 -O3 build/BitMatrix.obj build/Board.obj build/CleverOptimizie.obj build/ColumnGenSolve.obj build/DACSolve.obj build/GRBFactory.obj build/Solution.obj build/SolveStrategy.obj build/Solver.obj build/StupidStrategy.obj build/TerminalSet.obj build/Tree.obj build/global.obj build/main.obj build/test.obj build/tests.obj build/thread.obj libgurobi_c++.a -lgurobi65 -o main.exe
songshihongdeMacBook-Pro:calculousA songshihong$ time ./main.exe
Running test LargeTest2
solving subproblem 350 * 350
iteration 0
current time: 16 seconds
curAns 1.225e+06
column sizes:
1 1 1 1 1 1 1 1 1 1
successfully routed 0 sets of terminals with 0 grids
picture saved to 20160626160002_0016336090.bmp
iteration 1
current time: 44 seconds
curAns 858635
column sizes:
4 2 2 2 2 2 2 2 4 2
successfully routed 3 sets of terminals with 1135 grids
picture saved to 20160626160014_0044819750.bmp
iteration 2
current time: 82 seconds
curAns 614822
column sizes:
7 3 5 3 5 3 3 3 7 5
successfully routed 5 sets of terminals with 2322 grids
picture saved to 20160626160029_0082871063.bmp
iteration 3
current time: 124 seconds
curAns 492798
column sizes:
10 5 8 4 8 4 4 4 10 8
successfully routed 6 sets of terminals with 2798 grids
picture saved to 20160626160045_0124509510.bmp
iteration 4
current time: 171 seconds
curAns 370900
column sizes:
13 8 11 5 9 5 7 6 11 11
successfully routed 7 sets of terminals with 3400 grids
picture saved to 20160626160104_0171612497.bmp
iteration 5
current time: 223 seconds
curAns 248752
column sizes:
16 11 14 6 12 8 9 9 12 14
successfully routed 8 sets of terminals with 3752 grids
picture saved to 20160626160125_0223658092.bmp
iteration 6
current time: 280 seconds
curAns 126995
column sizes:
19 14 17 7 13 11 12 11 15 16
successfully routed 9 sets of terminals with 4495 grids
picture saved to 20160626160147_0280626360.bmp
iteration 7
current time: 341 seconds
curAns 126981
column sizes:
22 17 20 8 15 14 14 13 18 18
successfully routed 9 sets of terminals with 4481 grids
picture saved to 20160626160211_0341782037.bmp
successfully routed 9 sets of terminals with 4481 grids
picture saved to 20160626160235_0402490794.bmp
Test LargeTest2 finished in 402.541 seconds.

real	2m39.130s
user	6m37.532s
sys	0m5.017s
songshihongdeMacBook-Pro:calculousA songshihong$ make
g++ -Wall -std=c++11 -O3 src/tests.cpp -c -o build/tests.obj
g++ -Wall -std=c++11 -O3 build/BitMatrix.obj build/Board.obj build/CleverOptimizie.obj build/ColumnGenSolve.obj build/DACSolve.obj build/GRBFactory.obj build/Solution.obj build/SolveStrategy.obj build/Solver.obj build/StupidStrategy.obj build/TerminalSet.obj build/Tree.obj build/global.obj build/main.obj build/test.obj build/tests.obj build/thread.obj libgurobi_c++.a -lgurobi65 -o main.exe
songshihongdeMacBook-Pro:calculousA songshihong$ time ./main.exe
Running test LargeTest2
solving subproblem 350 * 350
iteration 0
current time: 41 seconds
curAns 1.225e+06
column sizes:
1 1 1 1 1 1 1 1 1 1
successfully routed 0 sets of terminals with 0 grids
picture saved to 20160626160513_0042056409.bmp
iteration 1
current time: 92 seconds
curAns 980855
column sizes:
4 2 2 2 2 2 2 4 2 2
successfully routed 2 sets of terminals with 855 grids
picture saved to 20160626160535_0092118816.bmp
iteration 2
current time: 150 seconds
curAns 737133
column sizes:
6 3 5 3 3 5 3 7 3 3
successfully routed 4 sets of terminals with 2133 grids
picture saved to 20160626160601_0150907847.bmp
iteration 3
current time: 222 seconds
curAns 615687
column sizes:
8 6 8 4 4 8 4 10 4 4
successfully routed 5 sets of terminals with 3187 grids
picture saved to 20160626160632_0222220957.bmp
iteration 4
current time: 306 seconds
curAns 494217
column sizes:
11 9 11 5 7 11 5 13 5 5
successfully routed 6 sets of terminals with 4217 grids
picture saved to 20160626160709_0306801837.bmp
iteration 5
current time: 394 seconds
curAns 494096
column sizes:
13 11 14 6 10 13 6 16 6 6
successfully routed 6 sets of terminals with 4096 grids
picture saved to 20160626160748_0395050334.bmp
iteration 6
current time: 488 seconds
curAns 372887
column sizes:
14 12 16 7 13 16 7 19 9 7
successfully routed 7 sets of terminals with 5387 grids
picture saved to 20160626160829_0489059875.bmp
successfully routed 7 sets of terminals with 5387 grids
picture saved to 20160626160912_0585926302.bmp
Test LargeTest2 finished in 585.966 seconds.

real	4m18.372s
user	9m35.854s
sys	0m10.130s