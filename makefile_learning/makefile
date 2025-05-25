CXX = g++
CXXFLAGS = -I.
DEPS = hello.h
OBJS = hello.o main.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

prog1: $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY: clean
clean:
	rm -rf $(OBJS) prog1
	