#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

const size_t SIZE_OF_ARRAY = 10;

int main()
{
	// Part one
    srand(time(NULL));
	unsigned char data[SIZE_OF_ARRAY];
	for (size_t i = 0; i < SIZE_OF_ARRAY; ++i) {
		data[i] = (rand() % 246) + 10;
	}

	// Part two
	for (size_t i = 0; i < SIZE_OF_ARRAY; ++i) {
		printf("%d ", data[i]);
	}
	printf("\n");

	// Part three
	unsigned char greatest_value = 0;
	unsigned int index_of_greatest_value = 0;
	for (size_t i = 0; i < SIZE_OF_ARRAY; ++i) {
		if (data[i] > greatest_value) {
			greatest_value = data[i];
			index_of_greatest_value = i;
		}
	}
	printf("Greatest value is: %d\nIndex of greatest value is: %d\n", greatest_value, index_of_greatest_value);

	// Part four
	unsigned char min_value = UCHAR_MAX;
	unsigned int index_of_min_value = 0;
	for (size_t i = 0; i < SIZE_OF_ARRAY; ++i) {
		if (data[i] < min_value) {
			min_value = data[i];
			index_of_min_value = i;
		}
	}
	printf("Min value is: %d\nIndex of min value is: %d\n", min_value, index_of_min_value);
	
	// Part five
	printf("List of primes: ");
	for (size_t i = 0; i < SIZE_OF_ARRAY; ++i) {
		if (data[i] != 0 && data[i] != 1) {
			if (data[i] == 2) {
				printf("%d ");
			} else {
				int might_be_prime = 1;
				for (unsigned char j = 2; j < data[i]; ++j) {
					if ((data[i] % j) == 0) {
						might_be_prime = 0;
						break;
					}
				}
				if (might_be_prime)
					printf("%d ", data[i]);
			}
		}
	}
	printf("\n");

    return 0;
}
