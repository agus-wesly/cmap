RAYLIB_PATH = third_party/raylib

CFLAGS = -L$(RAYLIB_PATH) \
         -Wl,-rpath,'$$ORIGIN/../$(RAYLIB_PATH)' \
         -Wall \
		 -std=c++17

# TODO: when not in development, should just link and compile into one executable

.PHONY: build

all: main

build:
	mkdir -p build
	cp -r styles build/

main: build main.cpp plug.so
	clang++-21 $(CFLAGS) -ggdb main.cpp -lm -l:libraylib.so.600 -o build/main

plug.so: build plug.cpp
	clang++-21 $(CFLAGS) -ggdb plug.cpp -lm -l:libraylib.so.600 -shared -fPIC -o build/plug.so
