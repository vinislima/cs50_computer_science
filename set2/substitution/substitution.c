
#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toUpperCase(string key_b);
bool validateKey();
bool verifyOnlyLetters();
bool checkOnlyUniqueLetter();
string convertText(string text);

// Allocate space for the key with null terminator
char key[27];

// Function to uppercase
void toUpperCase(string key_b)
{
	for (int i = 0; i < strlen(key_b); i++)
	{
		key[i] = toupper(key_b[i]);
	}
	key[strlen(key_b)] = '\0'; // Null-terminate the string
}

// Check if key is valid
bool validateKey()
{
	if (!verifyOnlyLetters())
	{
		printf("Key must only contain letters.\n");
		return false;
	}
	if (strlen(key) != 26)
	{
		printf("Key must contain 26 characters.\n");
		return false;
	}
	if (!checkOnlyUniqueLetter())
	{
		printf("Key must contain each character once.\n");
		return false;
	}
	return true;
}

// verify is string contains only letters
bool verifyOnlyLetters()
{
	for (int i = 0; i < strlen(key); i++)
	{
		if (!isupper(key[i]))
		{
			return false;
		}
	}
	return true;
}

// check if only have one letter each
bool checkOnlyUniqueLetter()
{
	int containsLetter[26] = {0}; // Initialize to 0
	for (int i = 0; i < strlen(key); i++)
	{
		if (key[i] >= 'A' && key[i] <= 'Z')
		{
			containsLetter[key[i] - 'A']++;
			if (containsLetter[key[i] - 'A'] > 1)
			{
				return false; // Found duplicate
			}
		}
	}
	return true;
}

// convert text in cipher
string convertText(string text)
{
	// Make sure to create a new string for the ciphertext
	string cipher = malloc(strlen(text) + 1);
	if (cipher == NULL)
	{
		return NULL; // Check for malloc failure
	}

	for (int i = 0; i < strlen(text); i++)
	{
		if (isupper(text[i]))
		{
			cipher[i] = key[text[i] - 'A'];
		}
		else if (islower(text[i]))
		{
			cipher[i] = tolower(key[text[i] - 'a']);
		}
		else
		{
			cipher[i] = text[i]; // Preserve non-letter characters
		}
	}
	cipher[strlen(text)] = '\0'; // Null-terminate the cipher string
	return cipher;
}

// main function
int main(int argc, char *argv[])
{
	// test the argc
	if (argc != 2)
	{
		printf("Usage: ./substitution key\n");
		return 1;
	}

	string key_b = argv[1];
	toUpperCase(key_b);

	if (!validateKey())
	{
		return 1;
	}

	string text = get_string("plaintext: ");
	string ciphertext = convertText(text);
	if (ciphertext != NULL)
	{
		printf("ciphertext: %s\n", ciphertext);
		free(ciphertext); // Free allocated memory
	}
	else
	{
		printf("Error allocating memory for ciphertext.\n");
	}

	return 0;
}
