prog:vie.o main.o
	gcc vie.o main.o -o prog -lSDL -lSDL_image -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -g
vie.o:vie.c
	gcc -c vie.c -lSDL -lSDL_image -g
