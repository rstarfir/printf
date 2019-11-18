#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "../libft/includes/libft.h"

char *ft_itoa(int nbr)
{
	int 	sign;
	char 	*ptr;	
	int	nbr_tmp;
	int	len;

	sign = 1;
	len = 0;	
	nbr_tmp = nbr;
       	if (nbr == -2147483648)
		return ("-2147483648");	
	while(nbr_tmp)
	{
		nbr_tmp /= 10;
		len++;
	}
	if (len == 0)
		return ("0");
	if (nbr < 0)
	{
		sign = -1;
		nbr *= sign;
		len++;
	}
	if (!(ptr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ptr[len] = '\0';
	while(len--)
	{
		if (len == 0 && sign == -1)
			ptr[len] = '-';
		else
			ptr[len] = nbr % 10 + '0';
		nbr /= 10;
		
	}
	return(ptr);	
}
/*
int main()
{
	printf("%s",ft_itoa(-2003450));
	return (0);
}*/
