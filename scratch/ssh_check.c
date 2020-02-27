#include <stdio.h>

int main() {
	unsigned char c;
	int check = 1;

	for (size_t i = 0; i < 3; ++i) {
		c = getchar();
		if (c <= '0' || c >= '9') {
			check = 0;
		}
	}
	c = getchar();
	if (c != '-')
		check = 0;
	for (size_t i = 0; i < 2; ++i) {
		c = getchar();
		if (c <= '0' || c >= '9') {
			check = 0;
		}
	}
	c = getchar();
	if (c != '-')
		check = 0;
	for (size_t i = 0; i < 4; ++i) {
		c = getchar();
		if (c <= '0' || c >= '9') {
			check = 0;
		}
	}
	if (check)
		printf("SSN format is valid.\n");
	else
		printf("SSN format is invalid.\n");
}
