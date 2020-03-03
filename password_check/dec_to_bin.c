#include <stdio.h>

const int NUM_BITES = 8;
const int DIVIDEND = 128;

int main()
{
	int input;
	scanf("%d", &input);
	int divisor = 1;
	for (size_t i = 1; i <= NUM_BITES; ++i) {
		if (input / (DIVIDEND / divisor)) {
			input %= (DIVIDEND / divisor);
			putchar('1');
		}
		else
			putchar('0');
		divisor *= 2;
	}
	putchar('\n');
    return 0;
}
