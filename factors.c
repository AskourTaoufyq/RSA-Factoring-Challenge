#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

/**
 * findFactors - finds the factors of a number
 * @num: number to find its factors
 * Return: void
 */
void findFactors(const mpz_t num)
{
	mpz_t i;
	mpz_t quotient;

	mpz_init(i);
	mpz_init(quotient);

	mpz_set_ui(i, 2);
	mpz_cdiv_q_ui(quotient, num, 2);

	while (mpz_cmp(i, quotient) <= 0)
	{
		if (mpz_divisible_p(num, i))
		{
			mpz_t factor;

			mpz_init(factor);

			mpz_divexact(factor, num, i);
			gmp_printf("%Zd=%Zd*%Zd\n", num, i, factor);

			mpz_clear(factor);
			break;
		}
		mpz_add_ui(i, i, 1);
	}

	mpz_clear(i);
	mpz_clear(quotient);
}

/**
 * main - the main function calls findFactor function
 * @argc: number of argument passed to the program
 * @argv: stores thr argument passed to the program
 * Return: integer
 */
int main(int argc, char *argv[])
{
	FILE *file;
	mpz_t num;

	mpz_init(num);

	if (argc != 2)
	{
		printf("Usage: ./program <filename>\n");
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Failed to open the file.\n");
		return (1);
	}

	while (gmp_fscanf(file, "%Zd", num) != EOF)
	{
		findFactors(num);
	}

	mpz_clear(num);
	fclose(file);

	return (0);
}
