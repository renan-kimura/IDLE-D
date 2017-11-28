BINDIR = ./bin
SRCDIR = ./src
INCLUDEDIR = ./include
APPDIR = ./application
OBJDIR = ./build
TESTDIR = ./test

CC = g++
CFLAGS = -std=c++11 -I $(INCLUDEDIR)
LDFLAGS =

BIN = ${BINDIR}/main
APP = ${APPDIR}/main.cpp

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC))
APPOBJ = $(patsubst $(APPDIR)/%.cpp,$(OBJDIR)/%.o,$(APP))

_TESTS = $(wildcard $(TESTDIR)/*.cpp)
TESTS = $(patsubst %.cpp,%,$(_TESTS))

$(BIN): $(OBJS) $(APPOBJ)
	$(CC) -o $(BIN) $(APPOBJ) $(OBJS) $(CFLAGS) $(LDFLAGS)

$(APPOBJ): $(APP)
	$(CC) -c -o $@ $< $(CFLAGS)

${OBJDIR}/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(TESTS) 
	$(info ************  Testes concluídos com sucesso! ************)

$(TESTDIR)/t_%: $(TESTDIR)/t_%.cpp $(OBJS)
	$(CC) -o $@ $< $(OBJS) $(CFLAGS) $(LDFLAGS)
	$@
run: 
	$(BINDIR)/main
all:
	make
	$(BINDIR)/main
clean:
	rm -f $(BINDIR)/* $(OBJDIR)/* $(APPOBJ)/*
	rm -f $(TESTDIR)/*

