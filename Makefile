CC = g++
CFLAGS = -I inc -std=c++17 -static-libgcc -static-libstdc++
CFLAGSD = -I inc -std=c++17 -g -o appdebug -static-libgcc -static-libstdc++
CFLAGS_WIN = -std=c++17 -o /mnt/c/users/naest/Desktop -I inc -static-libgcc -static-libstdc++

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
CC = g++
CC_WIN = x86_64-w64-mingw32-g++

$(ODIR)/%.o: $(SDIR)/%.cpp $(H_FILES) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(PROGRAM): $(OBJ) 
	$(CC) $^ -o $(BDIR)/$@ $(CFLAGS)

debug:
	$(CC) src/app.cpp src/lab_gen.cpp $(CFLAGSD) 

win:
	x86_64-w64-mingw32-g++ src/app.cpp src/lab_gen.cpp $(CFLAGS_WIN)

run:
	./bin/app

clean:
	$(RM) $(BDIR)/*
	$(RM) $(ODIR)/*.o
	$(RM) $(PDIR)/$(ODIR)/*.o
