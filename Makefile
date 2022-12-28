##
# Pokemon Battle Sim
#
# @Makefile
# @version 0.1

CFLAGS=-Iinclude -D DEBUG -D POSIX -D SILENCE_DISCLAIMER -g

all: pokemon.bin

pokemon.bin: build/main.o build/damage.o build/moves.o build/types.o build/dex.o build/ai.o build/ability.o build/factory.o build/battle.o
	@gcc $(CFLAGS) -o pokemon.bin build/main.o build/damage.o build/moves.o build/types.o build/dex.o build/ai.o build/ability.o build/factory.o build/battle.o

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

build/factory.o: frontier/factory.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "factory.o"

build/battle.o: main.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "battle.o"

clean:
	@rm build/*.o
	@rm pokemon.bin

# end
