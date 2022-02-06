CC = g++
CFLAGS = -Iinc -Idep -w -std=c++14

IDIR = inc
ODIR = obj
BDIR = bin
SDIR = src
DDIR = dep

PROGRAM = app

H_FILES := $(wildcard $(IDIR)/*.h)
DEPS := $(wildcard $(DDIR)/*.h)

SRC_FILES := $(wildcard $(SDIR)/*.cpp)
OBJ := $(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(SRC_FILES))

NEEDED_FILES := $(filter-out $(SDIR)/app.cpp, $(SRC_FILES))

$(ODIR)/%.o: $(SDIR)/%.cpp $(H_FILES) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(PROGRAM): $(OBJ) 
	$(CC) $^ -o $(BDIR)/$@ $(CFLAGS)

run:
	./bin/app

clean:
	$(RM) $(BDIR)/*
	$(RM) $(ODIR)/*.o
	$(RM) $(PDIR)/$(ODIR)/*.o
