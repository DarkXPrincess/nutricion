CXX = g++
CXXFLAGS = -Wall -std=c++17 -I/usr/include/nlohmann
LDFLAGS = -lcurl

SRCS = main.cpp api.cpp json_handler.cpp nutrition_displayer.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = programa

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)