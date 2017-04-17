all: main deposit_test

main: build/src/main.o build/src/deposit.o
	gcc -Wall -Werror -o bin/main build/src/main.o build/src/deposit.o

build/src/main.o: src/main.c
	gcc -Wall -Werror -o build/src/main.o -c src/main.c

build/src/deposit.o: src/deposit.c
	gcc -Wall -Werror -o build/src/deposit.o -c src/deposit.c

deposit_test:

deposit_test: build/test/deposit_test.o build/test/main.o build/src/deposit.o
	gcc build/test/deposit_test.o build/test/main.o build/src/deposit.o -o bin/deposit_test

build/test/deposit_test.o: test/deposit_test.c
	gcc -Wall -Werror -I src -I thirdparty -c test/deposit_test.c -o build/test/deposit_test.o

build/test/main.o: test/main.c
	gcc -Wall -Werror -I src -I thirdparty -c test/main.c -o build/test/main.o

.PHONY: clean

clean:
	rm -rf build/src/*.o build/test/*.o bin/*
