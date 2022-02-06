#LOOK AT HOW DUMB WINDOWS IS
CC = g++
CC_WIN = x86_64-w64-mingw32-g++

#DAMN THAT'S A LOT OF ARGUMENTS
CFLAGS_LINUX = -I inc -std=c++17 -o lab_tools
CFLAGS_DEBUG = -I inc -std=c++17 -g -o debug -static-libgcc -static-libstdc++
CFLAGS_WIN = -std=c++17 -o lab_tools.exe -I inc -lstdc++fs

IDIR = inc
BDIR = bin
SDIR = src
DDIR = dep

PROGRAM = lab_tools
H_FILES := $(wildcard $(IDIR)/*.h)

SRC_FILES := $(wildcard $(SDIR)/*.cpp)

NEEDED_FILES := $(filter-out $(SDIR)/app.cpp, $(SRC_FILES))
CC = g++
CC_WIN = x86_64-w64-mingw32-g++

all:
	$(CC) $(NEEDED_FILES) $(CFLAGS_DEBUG) 

release:
	$(CC) $(NEEDED_FILES) $(CFLAGS_LINUX) 

win:
	x86_64-w64-mingw32-g++ $(NEEDED_FILES) $(CFLAGS_WIN)

run:
	./debug

clean:
	$(RM) $(BDIR)/*
	$(RM) $(ODIR)/*.o
	$(RM) $(PDIR)/$(ODIR)/*.o
