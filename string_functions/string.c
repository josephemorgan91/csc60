#include <string.h>
#include <stdio.h>								\

int main()
{
    char name[32];
	char address[32];
	char city[32];
	char state[3];
	char zip[6];
	char data[256];

	printf("Please enter your name: ");
	scanf("%s", name);
	strcpy(address, "5000 Washington Boulevard");
	strcpy(city, "Sacramento");
	strcpy(state, "CA");
	strcpy(zip, "95682");

	strcpy(data, name);
	strcat(data, "\n");
	strcat(data, address);
	strcat(data, "\n");
	strcat(data, city);
	strcat(data, "\n");
	strcat(data, zip);
	strcat(data, "\n");

	char *prompts[5] = {"Name: ", "Address: ", "City: ", "State: ", "Zip: "};
	char *start_substring = data;
	char *end_substring = strchr(data, '\n');
	for (unsigned int i = 0; end_substring != NULL; ++i) {
		printf("%s%.*s\n", prompts[i], end_substring - start_substring, start_substring);
		start_substring = end_substring + 1;
		end_substring = strchr(start_substring, '\n');
	}
	return 0;
}
