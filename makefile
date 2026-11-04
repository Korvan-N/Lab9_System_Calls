CC=gcc
CFLAGS=-Wall -g

SOURCES=finfo.c info.c pinfo.c pmod.c
EXECUTABLES=finfo info pinfo pmod

all: $(EXECUTABLES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES)