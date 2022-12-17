##
# Pokemon Battle Sim
#
# @Makefile
# @version 0.1

CFLAGS=-Iinclude -D DEBUG -g

all: pokemon.x

pokemon.x: main.o damage.o moves.o types.o dex.o
	@gcc $(CFLAGS) -o pokemon.x main.o damage.o moves.o types.o dex.o

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

clean:
	@rm *.o
	@rm pokemon.x

# end
