# this needs to be written it seems...
scriptTestTriangulation: CTriangulation.hpp CTriangulation.cpp scriptTestTriangulation.cpp
	g++ -I /usr/local/include/eigen CTriangulation.cpp scriptTestTriangulation.cpp -o scriptTestTriangulation

# also missing...
scriptTestUtils: utils.hpp scriptTestUtils.cpp
	g++ -I /usr/local/include/eigen scriptTestUtils.cpp -o scriptTestUtils

# this works
scriptTestMatrix: scriptTestMatrix.cpp CMatrix.hpp
	g++ scriptTestMatrix.cpp -o scriptTestMatrix

# no good ...
scriptTestTableQuadTri: tableQuadTri.hpp scriptTestTableQuadTri.cpp
	g++ -I /usr/local/include/eigen -L /usr/lib scriptTestTableQuadTri.cpp -o scriptTestTableQuadTri

# no good either
scriptTestMassMatrix:  CMassMatrix.cpp tableQuadTri.hpp CTriangulation.hpp CTriangulation.cpp scriptTestMassMatrix.cpp
	g++ -std=c++11 -I /usr/local/include/eigen -L /usr/lib CMassMatrix.cpp tableQuadTri.hpp CTriangulation.hpp CTriangulation.cpp scriptTestMassMatrix.cpp -o scriptTestMassMatrix