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
CX