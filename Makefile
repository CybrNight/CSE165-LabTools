CC = g++
CFLAGS = -Iinc -w -std=c++17 -static-libgcc -static-libstdc++

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

win:
	x86_64-w64-mingw32-g++ -std=c++17 src/app.cpp src/lab_gen.cpp -o bin/appwin -I inc -static-libgcc -static-libstdc++

run:
	./bin/app

clean:
	$(RM) $(BDIR)/*
	$(RM) $(ODIR)/*.o
	$(RM) $(PDIR)/$(ODIR)/*.o
