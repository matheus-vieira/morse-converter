all: morse.exe

clean:
	rm morse.exe morse.o lib/morse_converter.o

#morse.o: morse.c
#	gcc -c morse.c -o morse.o

#lib/morse_converter.o: lib/morse_converter.c
#	gcc -c lib/morse_converter.c -o lib/morse_converter.o

%.o: %.c
	gcc -c $< -o $@

morse.exe: morse.o lib/morse_converter.o
	gcc morse.o lib/morse_converter.o -o morse.exe