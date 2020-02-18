#include <stdio.h>
#include <math.h>

enum bracket_cutoff {c_first = 9525, c_second = 38700, c_third = 82500, c_fourth = 100000}; // Want to keep constants isolated
enum bracket_percent {p_first = 10, p_second = 12, p_third = 22, p_fourth = 24};

#define TIER_10_TAX floor(((double)p_first / 100.0) * (c_first))
#define TIER_12_TAX floor(((double)p_second / 100.0) * (c_second - c_first))
#define TIER_22_TAX floor(((double)p_third / 100.0) * (c_third - c_second))
#define TIER_24_TAX floor(((double)p_fourth / 100.0) * (c_fourth - c_third))

double get_total_tax (double);

int main() {
	unsigned int user_income = 0;
	double total_tax = 0;
	printf ("Please enter you annual salary as a whole number: ");
	scanf ("%d", &user_income);
	printf ("\n");
	if (user_income < c_first)
		total_tax = user_income * ((double)p_first / 100);
	else if (user_income < c_second)
		total_tax = TIER_10_TAX + ((user_income - c_first) * ((double)p_second / 100));
	else if (user_income < c_third)
		total_tax = TIER_10_TAX + TIER_12_TAX + ((user_income - c_second) * ((double)p_third / 100));
	else if (user_income < c_fourth)
		total_tax = TIER_10_TAX + TIER_12_TAX + TIER_22_TAX + ((user_income - c_third) * ((double)p_third / 100));
	else
		total_tax = TIER_10_TAX + TIER_12_TAX + TIER_22_TAX + TIER_24_TAX + ((user_income - c_fourth) * ((double)p_fourth / 100));

	printf("Your total taxes are: $%0.2f\n", total_tax);
}
