/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 06:02:29 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/24 05:01:24 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long	ft_atoi1(t_format *fmtptr)
{
	long	result;
	long	sign;

	result = 0;
	sign = 0;
	if (fmtptr->fmt[fmtptr->i] == '-')
		sign = 1;
	if (fmtptr->fmt[fmtptr->i] == '+' || fmtptr->fmt[fmtptr->i] == '-')
		fmtptr->i++;
	while (fmtptr->fmt[fmtptr->i] && fmtptr->fmt[fmtptr->i] >= '0' &&
			fmtptr->fmt[fmtptr->i] <= '9')
	{
		result = (result * 10) + (fmtptr->fmt[fmtptr->i] - '0');
		fmtptr->i++;
	}
	if (sign == 1)
		return (-result);
	else
		return (result);
}

char	*ft_itoa2(double n)
{
	char *div;
	char *mod;
	char *ret;

	div = ft_itoa1(n / 1);
	mod = ft_itoa1((n - (long)n) * 1000000);
	ret = ft_strjoin(div, ".\0");
	ret = ft_strjoin(ret, mod);
	return (ret);
}

char	*ft_itoa1(long long n)
{
	char	*ret;
	int		temp_n;
	int		len;
	char	sign;

	sign = (n < 0) ? -1 : 1;
	len = 2 + (n < 0);
	temp_n = n;
	while ((n = n / 10))
		len++;
	n = temp_n;
	if ((ret = (char *)malloc(sizeof(char) * len--)) == NULL)
		return (NULL);
	ret[len--] = '\0';
	ret[len--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		ret[len--] = sign * (n % 10) + '0';
	if (sign < 0)
		ret[len] = '-';
	return (ret);
}

int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char	*ft_itoa_base(int val, int base, int up)
{
	int		i;
	int		n;
	char	*nbr;
	char	c;

	i = 1;
	n = 0;
	up == 1 ? (c = 'A') : 0;
	up != 1 ? (c = 'a') : 0;
	if (val < 0)
		base == 10 ? ((n = 1) && (val *= -1)) : 0;
	while (ft_pow(base, i) - 1 < val)
		i++;
	if ((nbr = (char*)malloc(sizeof(nbr) * i)) == NULL)
		return (NULL);
	nbr[i + n] = '\0';
	while (i-- > 0)
	{
		nbr[i + n] = (val % base) + (val % base > 9 ? c - 10 : '0');
		val = val / base;
	}
	if (n)
		nbr[0] = '-';
	return (nbr);
}
