files = cmd.o command.o args.o utils.o

compile: bin cl

bin: $(files)
	clang $(files) -o ./bin/output.exe

cmd.o: ./src/cmd.c
	clang -c ./src/cmd.c

command.o: ./src/command.c ./src/command.h
	clang -c ./src/command.c

args.o: ./src/args.c ./src/args.h
	clang -c ./src/args.c

utils.o: ./src/utils.c ./src/utils.h
	clang -c ./src/utils.c

cl:
	rm *.o
	clear