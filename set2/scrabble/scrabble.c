
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	string player_1 = get_string("Player 1: ");
	string player_2 = get_string("Player 2: ");

	// array to correlate letter and values
	int alphabet[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
					1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

	// to lower letter before check values
	int j = 0;
	while (player_1[j] != '\0')
	{
		player_1[j] = tolower(player_1[j]);
		j++;
	}

	// to lower letter before check values
	int z = 0;
	while (player_2[z] != '\0')
	{
		player_2[z] = tolower(player_2[z]);
		z++;
	}

	// to sum values correspondents according to the letters
	int i = 0;
	int sum_1 = 0;
	while (player_1[i] != '\0')
	{
		if (player_1[i] >= 'a' && player_1[i] <= 'z')
		{
			sum_1 = sum_1 + alphabet[(player_1[i] - 97)];
			i++;
		}
		else
			i++;
	}

	// to sum values correspondents according to the letters
	int t = 0;
	int sum_2 = 0;
	while (player_2[t] != '\0')
	{
		if (player_2[t] >= 'a' && player_1[t] <= 'z')
		{
			sum_2 = sum_2 + alphabet[(player_2[t] - 97)];
			t++;
		}
		else
			t++;
	}

	// to check the results
	if (sum_1 == sum_2)
		printf("Tie!\n");
	else if (sum_1 > sum_2)
		printf("Player 1 wins!\n");
	else
		printf("Player 2 wins!\n");
	return (0);
}
