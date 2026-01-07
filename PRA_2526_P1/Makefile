CXX = g++
CXXFLAGS = -std=c++11

bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testListArray testListArray.cpp

bin/testListLinked: testListLinked.cpp ListLinked.h List.h Node.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testListLinked testListLinked.cpp

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testNode testNode.cpp

Point2D.o: Point2D.cpp Point2D.h
	$(CXX) $(CXXFLAGS) -c Point2D.cpp

Shape.o: Shape.cpp Shape.h
	$(CXX) $(CXXFLAGS) -c Shape.cpp

Circle.o: Circle.cpp Circle.h
	$(CXX) $(CXXFLAGS) -c Circle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	$(CXX) $(CXXFLAGS) -c Rectangle.cpp

Square.o: Square.cpp Square.h
	$(CXX) $(CXXFLAGS) -c Square.cpp

Drawing.o: Drawing.cpp Drawing.h
	$(CXX) $(CXXFLAGS) -c Drawing.cpp

bin/testPoint2D: testPoint2D.cpp Point2D.o
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testPoint2D testPoint2D.cpp Point2D.o

bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testCircle testCircle.cpp Circle.o Shape.o Point2D.o

bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testRectangle testRectangle.cpp Rectangle.o Shape.o Point2D.o

bin/testSquare: testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testSquare testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o

bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testDrawing testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o

clean:
	rm -rf bin *.o *.gch