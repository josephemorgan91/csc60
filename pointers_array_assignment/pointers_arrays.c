#include <stdio.h>
#include <limits.h>

int main()
{
	unsigned char data[10] = {21, 42, 63, 81, 72, 61, 53, 59, 39, 32};
	unsigned char *ptr; 

	// Problem 1
	ptr = data;
	for (unsigned short i = 0; i < 10; ++i) {
		printf("%d ", ptr[i]);
	}
	printf("\n");

	// Problem 2
	ptr = data + 9;
	for (unsigned short i = 0; i < 10; ++i) {
		printf("%d ", ptr[-i]);
	}
	printf("\n");

	// Problem 3
	ptr = data;
	int max_value = 0;
	unsigned short max_value_index = -1;
	for (unsigned short i = 0; i < 10; ++i) {
		if (ptr[i] > max_value) {
			max_value = ptr[i];
			max_value_index = i;
		}
	}
	printf("Max value is: %d\nIndex of max value: %d\n", max_value, max_value_index);

	// Problem 4
	ptr = data;
	int min_value = INT_MAX;
	unsigned short min_value_index = -1;
	for (unsigned short i = 0; i < 10; ++i) {
		if (ptr[i] < min_value) {
			min_value = ptr[i];
			min_value_index = i;
		}
	}
	printf("Min value is: %d\nIndex of min value: %d\n", min_value, min_value_index);

	// Problem 5
	unsigned int iData[] = {0xf0f1f3f4, 0xf5f6f7f8, 0xf9fAfBfC};
	ptr = iData;
	for (unsigned short i = 0; i < 12; ++i) {
		printf("%x \n", ptr[i]);
	}

	return 0;
}
