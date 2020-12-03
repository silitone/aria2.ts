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
CXXLIBS=-lGL -lGLU -lX