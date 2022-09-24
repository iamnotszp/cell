build/gui:
	g++  -c gui.cpp -lSDL2 -g -o build/gui.o

main:build/gui
	g++  build/gui.o main.cpp -g -I./ -lSDL2 -o main

run:main
	./main

debug:main
	gdb main