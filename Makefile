CXX = g++
CXXFLAGS = -std=c++98 -Wall -O2
TARGET = code
SOURCE = solution.cpp

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)