#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	const char *prompt = "Password must contain:\n"
		"\t-One or more upper-case letters\n"
		"\t-One or more lower-case letters\n"
		"\t-One or more digits from 0 to 9\n"
		"\t-One symbol from the set {\"%\",\"+\",\"#\"}\n"
		"Please enter password: ";
	unsigned char password_str[32];
	password_str[0] = '\0';
	unsigned int c;
	int password_accepted = 0;
	short contents_set = 0;
	short has_lower = 0x01;
	short has_upper = 0x02;
	short has_digit = 0x04;
	short has_symbol = 0x08;

	if (argc == 1 || strncmp(argv[1], "-f", 2)) {
		while (!password_accepted) {
			printf("%s", prompt);

			for (size_t i = 0; ((c = getchar()) != '\n'); ++i) {
				password_str[i] = c;
				password_str[i + 1] = '\0';
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
				case 'z': {
					contents_set = contents_set | has_lower;
					break;
				}
				case 'A':
				case 'B':
				case 'C':
				case 'D':
				case 'E':
				case 'F':
				case 'G':
				case 'H':
				case 'I':
				case 'J':
				case 'K':
				case 'L':
				case 'M':
				case 'N':
				case 'O':
				case 'P':
				case 'Q':
				case 'R':
				case 'S':
				case 'T':
				case 'U':
				case 'V':
				case 'W':
				case 'X':
				case 'Y':
				case 'Z': {
					contents_set = contents_set | has_upper;
					break;
				}
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9': {
					contents_set = contents_set | has_digit;
					break;
				}
				case '%':
				case '+':
				case '#': {
					contents_set = contents_set | has_symbol;
					break;
				}
				}
			}
			if (contents_set == 0x0F)
				password_accepted = 1;
			else {
				if (!(contents_set & has_lower))
					printf("\nPassword does not contain a lower-case letter\n");
				if (!(contents_set & has_upper))
					printf("\nPassword does not contain an upper-case letter\n");
				if (!(contents_set & has_digit))
					printf("\nPassword does not contain a digit\n");
				if (!(contents_set & has_symbol))
					printf("\nPassword does not contain a symbol from the set {\"%\",\"+\",\"#\"}\n");
			}
		printf("Password accepted.\n");
		}
	} else if (argc == 2 && !strncmp(argv[1], "-f", 2)) {

		while (!password_accepted) {
			printf("**%s", prompt);

			for (size_t i = 0; ((c = getchar()) != '\n'); ++i) {
				password_str[i] = c;
				password_str[i + 1] = '\0';
			}
			for (size_t i = 0; password_str[i] != '\0'; ++i) {
				if ((unsigned char)(password_str[i] - 97) <= 25)
					contents_set = contents_set | has_lower;
				else if ((unsigned char)(password_str[i] - 65) <= 25)
					contents_set = contents_set | has_upper;
				else if ((unsigned char)(password_str[i] - 48) <= 9)
					contents_set = contents_set | has_digit;
				else if ((password_str[i] == '%') || (password_str[i] == '+') || (password_str[i] == '#'))
					contents_set = contents_set | has_symbol;
			}
			if (contents_set == 0x0F)
				password_accepted = 1;
			else {
				if (!(contents_set & has_lower))
					printf("\nPassword does not contain a lower-case letter\n");
				if (!(contents_set & has_upper))
					printf("\nPassword does not contain an upper-case letter\n");
				if (!(contents_set & has_digit))
					printf("\nPassword does not contain a digit\n");
				if (!(contents_set & has_symbol))
					printf("\nPassword does not contain a symbol from the set {\"%\",\"+\",\"#\"}\n");
			}
		}
		printf("Password accepted.\n");
	}
}
