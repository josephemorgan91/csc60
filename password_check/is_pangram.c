#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

const uint8_t OFFSET = 97; // Subtract this from a char, 'A' will start at 0
const uint8_t DIFF_BETWEEN_CASES = 32;

int main()
{
	uint32_t all_letters_set = 0x03ffffff;
	uint32_t contents_set = 0x0;
	uint32_t bitval = 0x0;
	char input_string[256] = {0};

	char c = '\0';
	for (size_t i = 0; ((c = getchar()) != '\n'); ++i) {
		input_string[i] = c;
		input_string[i + 1] = '\0';
		if ((c <= 'Z') && (c >= 'A')) 
			c += DIFF_BETWEEN_CASES;
		bitval = 0x01 << (c - OFFSET);
		contents_set = contents_set | bitval;
	}
	if ((contents_set & all_letters_set) >= all_letters_set)
		printf("%s is a pangram.\n", input_string);
	else {
		uint32_t missing_letters_set = ~contents_set;
		printf("%s is not a pangram.\n", input_string);
		for (size_t i = 0; i < 26; ++i) {
			if ((missing_letters_set >> i) & 0x01)
				printf("%c is missing.\n", (char)i + OFFSET);
		}

	}
}

void hidestuff()
{
	char c = 'a';
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	default:
		break;
	}
}
