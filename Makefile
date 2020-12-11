PROJECT=ngx

BINDIR=./bin
SRCDIR=./src
OBJDIR=./obj
INCDIR=./include
TSTDIR=./test

CNFLIBDIR=./config

CNFLIB=$(CNFLIBDIR)/lib/libngxcnf.a

NGXLIBS=$(CNFLIB)
NGXINCL=$(CNFLIBDIR)/include

CXX=gcc
CXXFLAGS=-g3 -std=gnu99 -I$(INCDIR) -I$(NGXINCL) -pedantic -Werror=implicit-function-declaration -Wno-overlength-strings
CXXLIBS=-lGL -lGLU -lX11 -lm

export

SOURCES=$(wildcard $(SRCDIR)/*.c)
OBJECTS=$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(patsubst %.c,%.o,$(SOURCES))) $(NGXLIBS)

.PHONY: clean run test conflib

all: $(BINDIR) $(OBJDIR) $(BINDIR)/$(PROJECT) $(BINDIR)/ngxfl $(BINDIR)/ngxData $(BINDIR)/ngxls $(BINDIR)/ngxTree $(BINDIR)/ngxar conflib
	@echo "Done!"

run: $(BIN