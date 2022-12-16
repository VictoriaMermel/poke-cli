##
# Pokemon Battle Sim
#
# @Makefile
# @version 0.1

all: pokemon.x

pokemon.x: main.o damage.o moves.o types.o
	@gcc -o pokemon.x main.o damage.o moves.o types.o

main.o: main.c
	@gcc -Iinclude -g -c -o $@ $<
	@echo "main.o"

moves.o: moves.c
	@gcc -Iinclude -c -g -o $@ $<
	@echo "moves.o"

types.o: types.c
	@gcc -Iinclude -c -g -o $@ $<
	@echo "types.o"

damage.o: damage.c
	@gcc -Iinclude -lmath -c -g -o $@ $<
	@echo "damage.o"

clean:
	@rm *.o
	@rm pokemon.x

# end
