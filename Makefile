CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g -fsanitize=address
SRC = src/main.c src/utils.c src/scan.c
OUT = corganizer

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
format:
	clang-format -i src/*.c src/*.h