# Flags
CFLAGS += -std=c99 -Wall -Wextra -D_POSIX_C_SOURCE=199309L
CC := gcc

all: generate impl static

generate: clean
	@mkdir -p bin

clean:
	@rm -rf bin

static: generate
	$(CC) $(CFLAGS) -o bin/static static.c work.c

impl: generate
	$(CC) $(CFLAGS) -o bin/impl impl.c work.c

.PHONY: all generate clean static impl