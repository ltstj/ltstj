IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -std=c++11 -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Practice_Activity_2.cpp
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Practice_Activity_2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f Practice_Activity_2
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append         
