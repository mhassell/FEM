.PHONY: hello 

gxx=g++ -std=c++11
eigenDir=/usr/local/include/eigen
libDir=/usr/lib
srcDir=/home/kernelpanic/Desktop/FEM/src
testDir=/home/kernelpanic/Desktop/FEM/tests
utilsDir=/home/kernelpanic/Desktop/FEM/utils

triangulationDeps=CTriangulation.hpp CTriangulation.cpp
massMatDeps=CMassMatrix.cpp CMatrix.hpp \
	tableQuadTri.hpp CTriangulation.cpp CTriangulation.hpp
utilsDeps=utils.hpp
matrixDeps=CMatrix.hpp
quadDeps=tableQuadTri.hpp

# rebuild the commands to make them more flexible
scriptTestTriangulation: $(triangulationDeps) tests/scriptTestTriangulation.cpp
	$(gxx) -I $(eigenDir) -I $(srcDir) $(triangulationDeps) tests/scriptTestTriangulation.cpp -o testBin/scriptTestTriangulation

scriptTestUtils: $(utilsDeps) tests/scriptTestUtils.cpp
	$(gxx) -I $(eigenDir) -I $(srcDir) tests/scriptTestUtils.cpp -o testBin/scriptTestUtils

scriptTestMatrix: $(matrixDeps) tests/scriptTestMatrix.cpp
	$(gxx) -I $(srcDir) tests/scriptTestMatrix.cpp -o testBin/scriptTestMatrix

scriptTestTableQuadTri: $(quadDeps) tests/scriptTestTableQuadTri.cpp
	$(gxx) -I $(eigenDir) -I $(srcDir) -L $(libDir) tests/scriptTestTableQuadTri.cpp -o testBin/scriptTestTableQuadTri

scriptTestMassMatrix: $(massMatDeps)
	$(gxx) -I $(eigenDir) -I $(srcDir) -L $(libDir) $(massMatDeps) tests/scriptTestMassMatrix.cpp -o testBin/scriptTestMassMatrix

scriptTestTriangulationOld: CTriangulation.hpp CTriangulation.cpp scriptTestTriangulation.cpp
	g++ -std=c++11 -I /usr/local/include/eigen CTriangulation.cpp scriptTestTriangulation.cpp -o scriptTestTriangulation

scriptTestUtilsOld: utils.hpp scriptTestUtils.cpp
	g++ -std=c++11 -I /usr/local/include/eigen scriptTestUtils.cpp -o scriptTestUtils

scriptTestMatrixOld: scriptTestMatrix.cpp CMatrix.hpp
	g++ -std=c++11 scriptTestMatrix.cpp -o scriptTestMatrix

scriptTestTableQuadTriOld: tableQuadTri.hpp scriptTestTableQuadTri.cpp
	g++ -std=c++11 -I /usr/local/include/eigen -L /usr/lib scriptTestTableQuadTri.cpp -o scriptTestTableQuadTri

# no good either
scriptTestMassMatrixOld:  CMassMatrix.cpp tableQuadTri.hpp CTriangulation.hpp CTriangulation.cpp scriptTestMassMatrix.cpp
	g++ -std=c++11 -I /usr/local/include/eigen -L /usr/lib CMassMatrix.cpp tableQuadTri.hpp CTriangulation.hpp CTriangulation.cpp scriptTestMassMatrix.cpp -o scriptTestMassMatrix

hello:
	echo hello