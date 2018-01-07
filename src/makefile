scriptTestTriangulation: triangulation.h triangulation.cpp scriptTestTriangulation.cpp
	g++ -I /usr/local/include/eigen triangulation.cpp scriptTestTriangulation.cpp -o scriptTestTriangulation

scriptTestUtils: utils.hpp scriptTestUtils.cpp
	g++ -I /usr/local/include/eigen scriptTestUtils.cpp -o scriptTestUtils

scriptTestMatrix: scriptTestMatrix.cpp matrix.hpp
	g++ scriptTestMatrix.cpp -o scriptTestMatrix

scriptTestTableQuadTri: tableQuadTri.hpp scriptTestTableQuadTri.cpp
	g++ -I /usr/local/include/eigen -L /usr/lib scriptTestTableQuadTri.cpp -o scriptTestTableQuadTri



