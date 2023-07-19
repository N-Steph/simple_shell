#include "main.h"

/**
 * _strlen - determine the length of a string
 * @s: pointer to the array of character containing
 * the string
 *
 * This function counts the number of bytes in a string
 * except the '\0' character.
 *
 * Return: len (number of bytes)
 */
int _strlen(const char *s)
{
	int len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s += 1;
	}
	return (len);
}
