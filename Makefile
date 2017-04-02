build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c

build/deposit.o: src/deposit.c
	gcc -Wall -Werror -c src/deposic.c

bin/main: build/main.o build/deposit.o
	gcc -Wall -Werror -o build/main.o build/deposit.o

all: bin/main

clean:
	rm -rf build/*.o