CC=gcc

IDIR =inc
CFLAGS=-I./${IDIR}

ODIR = obj
SDIR = src
LDIR = lib
BDIR = bin

_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hellofunc.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_SRC = hellofunc.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

static:
	ar rcs $(LDIR)/static/libhello.a $(OBJ)

shared:
	gcc -shared -o $(LDIR)/shared/libhello.so $(OBJ)

link_static: 
	gcc -o $(BDIR)/static hellomake.o -L$(LDIR)/static/ -lhello 

link_shared:
	gcc -o $(BDIR)/shared hellomake.o -L$(LDIR)/shared -lhello

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@echo "==== 2 ===="
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: hellomake.c $(OBJ)
	@echo "==== 1 ===="
	$(CC) -c -o $@.o $< $(CFLAGS)

.PHONY: static link clean

clean:
	rm -rf hellomake $(ODIR)/*.o
