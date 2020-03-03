#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

const uint8_t OFFSET = 97; // Subtract this from a char, 'A' will start at 0
const uint8_t DIFF_BETWEEN_CASES = 32;

int main (int argc, char **argv)
{
	char c = '\0';
	char input_string[256] = {0};

	if (argc == 2 && (!strncmp(argv[1], "-f", 2))) {
		/* My solution to the problem, which allows for easily identifying
		 * the characters that were missing as well as reducing wasted memory.
		 */
		uint32_t all_letters_set = 0x03ffffff;
		uint32_t contents_set = 0x0;
		uint32_t bitval = 0x0;

		for (unsigned int i = 0; ((c = getchar()) != '\n'); ++i) {
			input_string[i] = c;
			if ((c <= 'Z') && (c >= 'A')) 
				c += DIFF_BETWEEN_CASES;
			bitval = 0x01 << (c - OFFSET);
			contents_set = contents_set | bitval;
		}
		if ((contents_set & all_letters_set) >= all_letters_set)
			printf("\"%s\" is a pangram.\n", input_string);
		else {
			uint32_t missing_letters_set = ~contents_set;
			printf("\"%s\" is not a pangram.\n", input_string);
			for (unsigned int i = 0; i < 26; ++i) {
				if ((missing_letters_set >> i) & 0x01)
					printf("%c is missing.\n", (char)i + OFFSET);
			}
		}
	}
	else {
		unsigned int has_letter[26] = {FALSE};
		for (unsigned int i = 0; (c = getchar()); ++i) {
			if (c == '\n')
				break;
			if ((c <= 'Z') && (c >= 'A')) 
				c += DIFF_BETWEEN_CASES;
			switch (c) {
				/* Could just put has_letter[c - offset] = 1 and skip the switch/case structure
				 * but I believe we're required to use the switch/case so I guess I'll do it this way...
				 */ 
			case 'a': {
				has_letter[0] = TRUE;
				break;
			}
			case 'b': {
				has_letter[1] = TRUE;
				break;
			}
			case 'c': {
				has_letter[2] = TRUE;
				break;
			}
			case 'd': {
				has_letter[3] = TRUE;
				break;
			}
			case 'e': {
				has_letter[4] = TRUE;
				break;
			}
			case 'f': {
				has_letter[5] = TRUE;
				break;
			}
			case 'g': {
				has_letter[6] = TRUE;
				break;
			}
			case 'h': {
				has_letter[7] = TRUE;
				break;
			}
			case 'i': {
				has_letter[8] = TRUE;
				break;
			}
			case 'j': {
				has_letter[9] = TRUE;
				break;
			}
			case 'k': {
				has_letter[10] = TRUE;
				break;
			}
			case 'l': {
				has_letter[11] = TRUE;
				break;
			}
			case 'm': {
				has_letter[12] = TRUE;
				break;
			}
			case 'n': {
				has_letter[13] = TRUE;
				break;
			}
			case 'o': {
				has_letter[14] = TRUE;
				break;
			}
			case 'p': {
				has_letter[15] = TRUE;
				break;
			}
			case 'q': {
				has_letter[16] = TRUE;
				break;
			}
			case 'r': {
				has_letter[17] = TRUE;
				break;
			}
			case 's': {
				has_letter[18] = TRUE;
				break;
			}
			case 't': {
				has_letter[19] = TRUE;
				break;
			}
			case 'u': {
				has_letter[20] = TRUE;
				break;
			}
			case 'v': {
				has_letter[21] = TRUE;
				break;
			}
			case 'w': {
				has_letter[22] = TRUE;
				break;
			}
			case 'x': {
				has_letter[23] = TRUE;
				break;
			}
			case 'y': {
				has_letter[24] = TRUE;
				break;
			}
			case 'z': {
				has_letter[25] = TRUE;
				break;
			}
			default : {
				break;
			}
			}
		}
		unsigned int has_all_letters = 1;
		for (unsigned int i = 0; i < 26; ++i) {
			if (!has_letter[i])
				has_all_letters = 0;
		}
		if (has_all_letters)
			printf ("Is pangram.\n");
		else
			printf ("Is not pangram.\n");
	}
}
