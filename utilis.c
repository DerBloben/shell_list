#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "utilis.h"

char *get_input(char *buffer, int size)
{
	int i = 0;
	char c;
	int ret;

	while (i < size - 1)
	{
		ret = read (0,&c,1);
		if(ret <= 0)
			break;
		if(c == '\n')
			break;
		buffer[i++] = c;
	}
	buffer[i] = '\0';
	return buffer;
}

int ft_strlen (char *str)
{
	int i = 0;
	while(str[i]!='\0')
		i++;

	return i;
}

void ft_putstr(char *str)
{
	write(1,str,ft_strlen(str));
}

void ft_putchar(char c)
{
	write(1,&c,1);
}

char *ft_strcpy(char *dest, const char *src)
{
	int i=0;
	while (src[i])
	{
		dest[i]=src[i];
		i++;
	}
	dest[i]='\0';
	return dest;
}

int ft_strcmp(const char *a, const char *b)
{
	int i = 0 ;
	while (a[i] && b[i] )
	{
		if(a[i]!=b[i])
			return (a[i]-b[i]);
		i++;
	}
	return (a[i]-b[i]);
}

void ft_putnbr(int n)
{
	if(n >=10)
		ft_putnbr(n / 10);

	ft_putchar((n % 10) + '0');

}
