/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:44:24 by hthunder          #+#    #+#             */
/*   Updated: 2019/12/15 16:06:21 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"

char	*strrev(char *str)
{
	int				i;
	int				j;
	char			a;
	size_t			len;

	if (str)
	{
		len = ft_strlen((const char *)str);
		i = 0;
		j = len - 1;
		while (i < j)
		{
			a = str[i];
			str[i] = str[j];
			str[j] = a;
			i++;
			j--;
		}
		return (str);
	}
	else
		return (NULL);
}

char	*ft_itoabase(long long int num, int base) 
{
    //printf("snova tut %ld\n", num);
    size_t i = 0; 
    int isNegative = 0; 
	char *str;
    //printf("ya zdeeeeeees %ld", num);
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
	if (!(str = (char *)malloc(sizeof(char) * 21))) // на сколько символов выделить память?
		return (NULL);
    if (num == 0) 
    {
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    }
    if (base != 10 && num < 0)
    {
        num *= -1;
    }
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (num < 0 && base == 10) 
    {
        isNegative = 1; 
        num = -num; 
    }
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
    // If number is negative, append '-' 
    if (isNegative) 
        str[i++] = '-'; 
    str[i] = '\0'; // Append string terminator 
    // Reverse the string 
    //reverse(str, i); 
    //return str;
	 return (strrev(str));
}

char	*ft_itoabase_unsigned(unsigned long long int num, int base) 
{
    //printf("snova tut %ld\n", num);
    size_t i = 0; 
    int isNegative = 0; 
	char *str;
    //printf("ya zdeeeeeees %ld", num);
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
	if (!(str = (char *)malloc(sizeof(char) * 21))) // на сколько символов выделить память?
		return (NULL);
    if (num == 0) 
    {
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    }
    /*if (base != 10 && num < 0)
    {
        num *= -1;
    }*/
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    /*if (num < 0 && base == 10) 
    {
        isNegative = 1; 
        num = -num; 
    }*/
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
    // If number is negative, append '-' 
    if (isNegative) 
        str[i++] = '-'; 
    str[i] = '\0'; // Append string terminator 
    // Reverse the string 
    //reverse(str, i); 
    //return str;
	 return (strrev(str));
} 
