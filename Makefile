prog:scrolTest.o scroll.o getpixel.o animate.o collision.o
	gcc   scrolTest.o scroll.o getpixel.o animate.o collision.o -o teste -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
scrolTest.o:scrolTest.c
	gcc -c scrolTest.c

scroll.o:scroll.c
	gcc -c scroll.c

getpixel.o:getpixel.c
	gcc -c getpixel.c

animate.o:animate.c
	gcc -c animate.c

collision.o:collision.c
	gcc -c collision.c

