
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	// declared the variables
	int s_size = 0;
	string text;
	int letters, words, sentences;
	int a, b, c, r_index;
	double index, S, L;

	// get input until different void
	do
	{
		text = get_string("Text: ");
		s_size = strlen(text);
	}
	while (s_size <= 0);

	// count the letters
	a = 0;
	letters = 0;
	while (a <= s_size)
	{
		if ((text[a] >= 'a' && text[a] <= 'z') || (text[a] >= 'A' && text[a] <= 'Z'))
		{
			letters++;
			a++;
		}
		else
			a++;
	}

	// count words
	b = 0;
	words = 1;
	while (b <= s_size)
	{
		if (text[b] == 32)
		{
			words++;
			b++;
		}
		else
			b++;
	}

	// count sentences
	c = 0;
	sentences = 0;
	while (c <= s_size)
	{
		if ((text[c] == '?') || (text[c] == '!') || (text[c] == '.'))
		{
			sentences++;
			c++;
		}
		else
			c++;
    }

	// do the math of the index
	L = ((double) letters / words) * 100;
	S = ((double) sentences / words) * 100;

	// do the math of the index and rounded it
	index = 0.0588 * L - 0.296 * S - 15.8;
	r_index = round(index);

	// do the test to print
	if (r_index < 1)
		printf("Before Grade 1\n");
	else if (r_index >= 1 && r_index <= 16)
		printf("Grade %d\n", r_index);
	else
		printf("Grade 16+\n");
	return (0);
}
