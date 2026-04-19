CC = gcc
SRC = src/main.c src/scan.c src/execute.c src/rules.c src/utils.c
OUT = corganizer

PREFIX ?= /usr/local
BINDIR ?= $(PREFIX)/bin

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

install: release
	@echo "Installing $(OUT) to $(DESTDIR)$(BINDIR)"
	install -Dm755 $(OUT) "$(DESTDIR)$(BINDIR)/$(OUT)"

uninstall:
	@echo "Removing $(OUT) from $(DESTDIR)$(BINDIR)"
	rm -f "$(DESTDIR)$(BINDIR)/$(OUT)"

format:
	clang-format -i src/*.c src/*.h