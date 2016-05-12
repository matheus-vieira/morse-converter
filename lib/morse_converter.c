#include <stdlib.h>
#include <string.h>
#include "morse_converter.h"

const char morse_code[][6] = { ".----", "..---", "...--", "....-", ".....","-....", "--...", "---..", "----.", "-----", ".-","-...","-.-.","-..", ".", "..-.", "--.","....","..", ".---", "-.-", ".-..", "--","-.", "---", ".--.", "--.-", ".-.", "...", "-","..-","...-", ".--", "-..-", "-.--", "--.." };

char* convert_to_morse(char character)
{
	if (isalpha(character) == 0 || !isdigit(character) == 0)
	{
		return " ";
	}

	int j = 0;
	int position = 0;
	int morse_position = -1;

	char *morse_result = (char *)malloc(5 * sizeof(char*));

	// ASCII table 0 == 48 and 9 = 57
	morse_position = 0 - '0';

	// ASCII table A == 65 and Z = 90
	if (character > 64 && character < 91)
	{
		morse_position = 0 - 'A';
		morse_position += 10; // Initial morse code position
	}
	// ASCII table A == 97 and Z = 172
	else if (character > 96 && character < 173)
	{
		morse_position = 0 - 'a';
		morse_position += 10; // Initial morse code position
	}

	morse_position += character;

	for (j = 0; j < 5; j++)
	{
		if (morse_code[morse_position][j] == 0) break;

		morse_result[position++] = morse_code[morse_position][j];
	}

	morse_result[position] = '\0';

	return morse_result;
}

char  convert_from_morse(char* morse)
{
	if (strcmp(morse, "") == 0) return '\0';

	// variables
	int i = 0;
	int j = 0;
	int found = 1;
	int len = strlen(morse);

	// printf("%s", morse);
	// printf("%d", strlen(morse));

	// printf("executing morse translate\n");
	for (i = 0; i < 36; i++)
	{
		// printf("morse_code len[%d] %d %s \n", i, strlen(morse_code[i]), morse_code[i]);

		if (strlen(morse_code[i]) != len)
			continue;

		for (j = 0; j < 5; j++)
		{
			if (morse_code[i][j] == '\0')
				break;

			if (morse[j] != morse_code[i][j])
			{
				found = 0;
				break;
			}
			found = 1;
		}

		if (found == 1)
			break;
	}

	// printf("index {%d}\n", i);

	//            number    aplha 
	return i < 10 ? i + 48 : i + 55;
}