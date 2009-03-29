/*

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                    Version 2, December 2004

 Copyright (C) 2004 Sam Hocevar
  14 rue de Plaisance, 75014 Paris, France
 Everyone is permitted to copy and distribute verbatim or modified
 copies of this license document, and changing it is allowed as long
 as the name is changed.

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

  0. You just DO WHAT THE FUCK YOU WANT TO.

*/

void strncpy(char* dest, char* src, int length)
{
	while((*dest++ = *src++) && --length);
	*(--dest) = '\0';
}

void strncat(char* dest, char* src, int length)
{
	while(*dest++);
	m_strncpy(--dest,src,length);
}

int strcmp(char* a, char* b)
{
	while((*a == *b) && *a++ && *b++);
	return *a - *b;
}

int strncmp(char* a, char* b, int length)
{
	while(--length && (*a == *b) && *a++ && *b++);
	return *a - *b;
}

void strcpy(char* dest, char* src)
{
	while(*dest++ = *src++);
}

void strcat(char* dest, char* src)
{
	while(*dest++);
	strcpy(--dest,src);
}

void strupper(char* str)
{
	while(*str) {
		if (*str >= 'a' || *str <= 'z') {
			*str -= 32;
		}
		str++;
	}
}

void strlower(char* str)
{
    while(*str) {
		if (*str >= 'A' || *str <= 'Z') {
			*str += 32;
		}
		str++;
	}
}
