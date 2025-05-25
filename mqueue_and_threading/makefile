CXX = gcc
CFLAGS = -I. -lrt

prog1:
	$(CXX) prog1.c -o $@ $(CFLAGS)

prog2:
	$(CXX) prog2.c -o $@ $(CFLAGS)

.PHONY: clean
clean:
	rm -rf $(OBJS) prog1 prog2
