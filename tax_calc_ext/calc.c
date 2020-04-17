/* I may have gone a little overboard with this, but I've been pretty bored at home all day and wanted to challange myself.
 * Hopefully that's not a problem. In the assignment, you said that we shuld extend the program and make it more general.
 * I've made is as general as possible by making it so that arbitrary date.txt files can be placed in same directory as the
 * executable binary, and the calculator will be able to use them. As long as there is a file that matches the date the user
 * inputs, the program will calculate taxes for them.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NUM_BRACKETS 4
#define MAX_INPUT_LEN 5
#define FILENAME_LEN 9

struct Tax_Bracket
{
	int tax_rate[NUM_BRACKETS];
	int bracket_cap[NUM_BRACKETS];
	float full_bracket_tax[NUM_BRACKETS];
};

struct Tax_Bracket *init_tax_bracket(char*);
char* get_tax_year();
float get_tax_burden(float, struct Tax_Bracket*);

int main()
{
	char *year_string = get_tax_year();
	struct Tax_Bracket *b;
	float income;
	if ((b = init_tax_bracket(year_string)) == NULL) {
		printf("Couldn't find a year.txt file for the year %s, aborting execution.\n", year_string);
		exit(1);
	}
	// Not going to validate income because we're not reading a file based on what the user gives us here.
	printf("Please enter your income: ");
	scanf("%f", &income);
	printf("\n");
	printf("Total tax burden is: $%.2f\n", get_tax_burden(income, b));
	return 0;
}

// Initializes a tax-bracket structure based on a filename. Calculates cumulative totals for each bracket at init to prevent repetition.
struct Tax_Bracket *init_tax_bracket(char* year_as_string)
{
	char filename[FILENAME_LEN];
	strcpy(filename, year_as_string);
	strcat(filename, ".txt");
	struct Tax_Bracket *b = (struct Tax_Bracket*) malloc(sizeof (struct Tax_Bracket));
	FILE *infile;
	if ((infile = fopen(filename, "r")) == NULL)
		return NULL;
	for (size_t i = 0; i < NUM_BRACKETS; ++i) {
		fscanf(infile, "%d %d", &(b->tax_rate[i]), &(b->bracket_cap[i]));
		// This is not voodoo. If (i == 0), no need to account for lower brackets. If it's greater than zero, subtract lower bracket cap from income.
		b->full_bracket_tax[i] = (i ? (float)b->bracket_cap[i] - (float)b->bracket_cap[i - 1] : (float)b->bracket_cap[i]) * ((float)b->tax_rate[i] / 100);
	}
	return b;
}

// Gets and validates input in the form of a 4 digit numeric string that's used to create a filename referring to a tax year.
char* get_tax_year() {
	unsigned char have_valid_input = 0;
	char *input = (char*)malloc(sizeof(char) * MAX_INPUT_LEN);
	while (!have_valid_input) {
		for (size_t i = 0; i < MAX_INPUT_LEN; ++i)
			input[i] = '\0';
		have_valid_input = 1;
		printf("Enter tax year (yyyy): ");
		scanf("%s", input);
		printf("\n");
		if (input[MAX_INPUT_LEN - 1] != '\0') {
			have_valid_input = 0;
			printf("Too many characters read\n");
		} else {
			for (size_t i = 0; i < MAX_INPUT_LEN - 1; ++i) {
				if (!isdigit(input[i])) {
					printf("Nondigit character detected. Please enter only numbers in the form of (yyyy)\n");
					have_valid_input = 0;
					break;
				}
			}
		}
	}
	return input;
}

// Gets total tax burden based on income and tax bracket structure for a given year.
float get_tax_burden(float income, struct Tax_Bracket* b)
{
	float tax_burden = 0;
	int bracket = 0;
	for (size_t i = 0; i < NUM_BRACKETS; ++i) {
		if (income >= b->bracket_cap[i])
			tax_burden += b->full_bracket_tax[i];
		else if (i == 1)
			break;
		else if (i) {
			income -= b->bracket_cap[i - 1];
			bracket = i;
			break;
		}
	}
	if (income >= 100000) {
		bracket = 3;
		income -= 100000;
	}
	tax_burden += income * ((float)b->tax_rate[bracket] / 100);
	return tax_burden;
}
