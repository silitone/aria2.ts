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
OBJECTS=$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(patsubst %.c,%.o,$(SOURCES)))

CNFTST=./test/cnf
TSTTRR=./test/testct

.PHONY: clean test

all: $(LIBDIR) $(OBJDIR) $(LIBDIR)/$(NGXCNF)
	@echo "Done with $(NGXCNF)"

clean:
	rm -rfv $(OBJDIR)
	rm -rfv $(LIBDIR)
	rm -rfv $(CNFTST)
	rm -rvf $(SRCDIR)/config.tab.c
	rm -rvf $(INCDIR)/config.tab.h
	rm -rvf $(SRCDIR)/config.c
	rm -rvf $(INCDIR)/config.h

test: $(CNFTST) $(TSTTRR)
#	cat ./test/config.txt | $(CNFTST)
	$(TSTTRR)

$(CNFTST): $(CNFTST).c $(LIBDIR)/$(NGXCNF)
	$(CXX) $(CXXFLAGS) -o $@ $^

