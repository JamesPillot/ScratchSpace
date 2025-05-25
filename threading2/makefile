C = g++
CFLAGS = -I.
OBJS = main.o

prog: $(OBJS)
	$(C) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -rf $(OBJS) prog
