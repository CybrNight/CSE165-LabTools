CC = g++
CFLAGS = -I inc -std=c++17 -o bin/lab_tools
CFLAGSD = -I inc -std=c++17 -g -o bin/debug -static-libgcc -static-libstdc++
CFLAGS_WIN = -std=c++17 -o /mnt/c/users/naest/Desktop/appwin.exe -I inc -static-libgcc -static-libstdc++

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
	$(CC) $(NEEDED_FILES) $(CFLAGSD) 

release:
	$(CC) $(NEEDED_FILES) $(CFLAGS) 

win:
	x86_64-w64-mingw32-g++ $(NEEDED_FILES) $(CFLAGS_WIN)

run:
	./bin/app

clean:
	$(RM) $(BDIR)/*
	$(RM) $(ODIR)/*.o
	$(RM) $(PDIR)/$(ODIR)/*.o
