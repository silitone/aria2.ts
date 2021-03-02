LIBDIR=./lib

NGXCNF=libngxcnf.a
OBJDIR=./obj
SRCDIR=./src
INCDIR=./include

FLEX=flex
BISON=bison

SRCYCC=$(SRCDIR)/config.y
SRCLEX=$(SRCDIR)/config.lex

SOURCES=$(wildcard $(SRCDIR)/*.c) $(SRCDIR)/config.tab.c $(SRCDIR)/config.c
OBJECTS=$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(patsubst %.c,%.o,$