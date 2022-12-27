##
# Pokemon Battle Sim
#
# @Makefile
# @version 0.1

CFLAGS=-Iinclude -D DEBUG -D POSIX -D SILENCE_DISCLAIMER -g

all: pokemon.x

pokemon.x: main.o damage.o moves.o types.o dex.o ai.o ability.o
	@gcc $(CFLAGS) -o pokemon.x main.o damage.o moves.o types.o dex.o ai.o ability.o

main.o: main.c
	@gcc $(CFLAGS) -c -o $@ $<
	@echo "main.o"

moves.o: moves.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "moves.o"

types.o: types.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "types.o"

damage.o: damage.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "damage.o"

dex.o: dex.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "dex.o"

ai.o: ai.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "ai.o"

ability.o: ability.c
	@gcc -c $(CFLAGS) -o $@ $<
	@echo "ability.o"

clean:
	@rm *.o
	@rm pokemon.x

# end
