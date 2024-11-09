
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	// variables
	int k, c, p;
	int count_b;
	int ascii;
	string text;

	// test
	if (argc != 2)
	{
		printf("Usage: ./caesar key\n");
		return (1);
	}
	// test
	k = 0;
	c = 0;
	p = 0;
	while (k < strlen(argv[1]))
	{
		if (isalpha(argv[1][k]))
		{
			printf("Usage: ./caesar key\n");
			return (1);
		}
		k++;
	}

	// get plain text
	k = atoi(argv[1]) % 26;
	text = get_string("plaintext: ");

	// transformation
	printf("ciphertext: ");
	count_b = 0;
	while (count_b < strlen(text))
	{
		// check space
		if (text[count_b] == 32)
		{
			printf("%c", text[count_b]);
			count_b++;
			continue;
		}
		// check is alpha
		if (!isalpha(text[count_b]))
		{
			printf("%c", text[count_b]);
			count_b++;
			continue;
		}
		// check is upper
		if (isupper(text[count_b]))
			ascii = 65;
		else
			ascii = 97;
		p = text[count_b] - ascii;
		c = (p + k) % 26;

		// print letter after change
		printf("%c", c + ascii);
		count_b++;
	}
	printf("\n");
	return (0);
}
