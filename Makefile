CC = g++
CFLAGS = -I inc -std=c++17 -o bin/lab_tools
CFLAGSD = -I inc -std=c++17 -g -o appdebug -static-libgcc -static-libstdc++
CFLAGS_WIN = -std=c++17 -o /mnt/c/users/naest/Desktop -I inc -static-libgcc -static-libstdc++

IDIR = inc
BDIR = bin
SDIR = src
DDIR = dep

PROGRAM = lab_tools
H_FILES := $(wildcard $(IDIR)/*.h)
DEPS := $(wildcard $(DDIR)/*.h)

SRC_FILES := $(wildcard $(SDIR)/*.cpp)

NEEDED_FILES := $(filter-out $(SDIR)/app.cpp, $(SRC_FILES))
CC = g++
CC_WIN = x86_64-w64-mingw32-g++

all:
	$(CC) $(NEEDED_FILES) $(CFLAGS) 

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
