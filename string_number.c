/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 23:32:04 by ggambino          #+#    #+#             */
/*   Updated: 2015/09/10 23:32:16 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libzs.h"

int		zatoi(char *str)
{
	long	result;
	int		reverse;
	long	check;
	int		i;
	int		figure;

	result = 0;
	while (zstrpos("\n\v\t\r\f ", zsubstr(str, 0, 1)) >= 0)
		str++;
	check = (*str == '+') ? 1 : 0;
	reverse = (*str == '-') ? 1 : 0;
	i = (reverse == 1 || check == 1) ? 1 : 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		check = result;
		figure = (str[i] - '0');
		result = (result * 10) + figure;
		if ((result / 10) != check)
			return (reverse - 1);
		i++;
	}
	result = (reverse == 1) ? -result : result;
	return ((int)result);
}

char	*zitoa(int n)
{
	char	buff[12];
	char	*result;
	int		byte;
	int		origin;

	origin = n;
	n = ((origin) < 0) ? n : -n;
	byte = 0;
	while (n < 0 || byte == 0)
	{
		buff[byte++] = '0' - (n % 10);
		n /= 10;
	}
	if (origin < 0)
		buff[byte++] = '-';
	result = zstralloc(byte);
	n = 0;
	while (byte-- >= 0)
		result[n++] = buff[byte];
	result[n] = '\0';
	return (result);
}
