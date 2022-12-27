##
# Pokemon Battle Sim
#
# @Makefile
# @version 0.1

CFLAGS=-Iinclude -D DEBUG -D POSIX -D SILENCE_DISCLAIMER -g

all: pokemon.bin

pokemon.bin: build/main.o build/damage.o build/moves.o build/types.o build/dex.o build/ai.o build/ability.o
	@gcc $(CFLAGS) -o pokemon.bin build/main.o build/damage.o build/moves.o build/types.o build/dex.o build/ai.o build/ability.o

build/main.o: main.c build
	@gcc $(CFLAGS) -c -o $@ $<
	@echo "main.o"

build/moves.o: moves.c build
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "moves.o"

build/types.o: types.c build
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "types.o"

build/damage.o: damage.c build
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "damage.o"

build/dex.o: dex.c build
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "dex.o"

build/ai.o: ai.c build
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "ai.o"

build/ability.o: ability.c build
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "ability.o"

build:
	@mkdir build

clean:
	@rm build/*.o
	@rm pokemon.bin
	@rmdir build

# end
