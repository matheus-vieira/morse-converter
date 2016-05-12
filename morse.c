#include <stdio.h>
#include <stdlib.h>
#include "lib/morse_converter.h"

// char* read_input_console();
void read_input_console();

void main ()
{
	read_input_console();
}

// char* read_input_console()
void read_input_console()
{
	// int position = -1;

	char read;
	char from_morse = '\0';

	// char *phrase = (char *)malloc(0);
	char *to_morse = (char *)malloc(0);

	int show_morse = 1;

	// printf("show morse: ");
	// scanf("%d", &show_morse);

	while(scanf("%c", &read))
	{
		if  (read == '\n') break;

		// position++;

		// phrase = (char *)realloc(phrase, (position + 1) * sizeof(char*));
		// phrase[position] = toupper(read);

		to_morse = convert_to_morse(read);
		from_morse = convert_from_morse(to_morse);

		// printf("morse {%s}\t\t", to_morse);
		// printf("natural {%c}\n", from_morse);

		if (show_morse == 1) printf("%s", to_morse);
		else 				 printf("%c", from_morse);
	}

	// phrase[position] = '\0';

	// return phrase;
}
