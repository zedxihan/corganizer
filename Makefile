CC = gcc
SRC = src/main.c src/scan.c src/execute.c src/rules.c src/utils.c
OUT = corganizer

WARN = -Wall -Wextra -Wpedantic
STD = -std=c99

DEBUG_FLAGS = $(STD) $(WARN) -g -fsanitize=address
RELEASE_FLAGS = $(STD) $(WARN) -O2

all: release

release:
	$(CC) $(RELEASE_FLAGS) $(SRC) -o $(OUT)

debug:
	$(CC) $(DEBUG_FLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)

format:
	clang-format -i src/*.c src/*.h