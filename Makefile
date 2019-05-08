prog:chrono.o main.o 
	gcc chrono.o main.o -o prog -g
main.o:main.c
	gcc -c main.c -g
enemy.o:chrono.c
	gcc -c chrono.c  -g
