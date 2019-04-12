prog: main1.o enemy.o 
	gcc main1.o enemy.o -o prog -lSDL -lSDL_image -lSDL_mixer
main1.o: main1.c
	gcc -c main1.c
ennemy.o: enemy.c
	gcc -c enemy.c

