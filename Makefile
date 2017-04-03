all: main

main: main.o deposit.o
	gcc -Wall -Werror -MP -MMD -o bin/main build/main.o build/deposit.o

main.o: src/main.c
	gcc -Wall -Werror -MP -MMD -o build/main.o -c src/main.c

deposit.o: src/deposit.c
	gcc -Wall -Werror -MP -MMD -o build/deposit.o -c src/deposit.c

clean:
	rm -rf build/* bin/*
