CXX = g++
CXXFLAGS = -Wall -O2
TARGET = code
SOURCE = solution.cpp

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)