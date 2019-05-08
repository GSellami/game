prog:score.o main.o
	gcc score.o main.o -o prog -lSDL -lSDL_image -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -g
score.o:score.c
	gcc -c score.c -lSDL -lSDL_image -g
