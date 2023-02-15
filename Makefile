##
# Pokemon Battle Sim
#
# @Makefile
# @version 0.1

CFLAGS=-Iinclude -D DEBUG -D POSIX -D SILENCE_DISCLAIMER -g

all: build poke-cli.bin

build:
	@mkdir build

poke-cli.bin: build/main.o build/damage.o build/moves.o build/types.o build/dex.o build/ai.o build/ability.o build/frontier.o build/battle.o
	@gcc $(CFLAGS) -o poke-cli.bin build/main.o build/damage.o build/moves.o build/types.o build/dex.o build/ai.o build/ability.o build/frontier.o build/battle.o

build/main.o: main_menu.c
	@gcc $(CFLAGS) -c -o $@ $<
	@echo "main.o"

build/moves.o: moves.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "moves.o"

build/types.o: types.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "types.o"

build/damage.o: damage.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "damage.o"

build/dex.o: dex.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "dex.o"

build/ai.o: ai.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "ai.o"

build/ability.o: ability.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "ability.o"

build/frontier.o: battlemode/frontier.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "factory.o"

build/battle.o: main.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "battle.o"

build/pool.o: frontier/pool.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "pool.o"

clean:
	@rm -f build/*.o
	@rm -f poke-cli.bin
	@rmdir build

install: poke-cli.bin
	@cp poke-cli.bin /usr/local/bin/poke-cli

uninstall:
	@rm /usr/local/bin/poke-cli

# end
