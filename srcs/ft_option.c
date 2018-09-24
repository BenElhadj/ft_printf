/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:47:52 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/21 05:12:00 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		error(int j)
{
/*
** 	j == 1 ? ft_putendl("\nneed specifier after parametre or %\n") : 0;
**	j == 2 ? ft_putendl("\ndo you mean for the length 'hh'\n") : 0;
**	j == 3 ? ft_putendl("\ndo you mean for the length 'll'\n") : 0;
**	j == 4 ? ft_putendl("\nerror need va_arg\n") : 0;
*/

	j == 5 ? ft_putstr("error") : 0;

/*
**	j == 6 ? ft_putendl("error") : 0;
**	j == 7 ? ft_putendl("error") : 0;
**
** 	exit(0);
*/
	return (0);
}

int		ft_intlen(long long int n)
{
	int		i;

	i = 0;
	n <= 0 ? i++ : 0;
	n < 0 ? n *= -1 : 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	flush_data(t_data *data)
{
	write(1, data->data, data->index);
	data->index = 0;
}

int		stock(t_data *data, char *fmt, int len)
{
	int	i;

	i = 0;
	while (fmt[i] && i < len)
	{
		data->index == SIZEBUF ? flush_data(data) : 0;
		data->data[data->index] = fmt[i];
		i++;
		data->index++;
		data->len++;
	}
	flush_data(data);
	return (i);
}

void	init_option(t_option *flag, va_list *args, int bt)
{
	flag->sharp = 0;
	flag->zero = 0;
	flag->space = 0;
	flag->plus = 0;
	flag->sign = 0;
	flag->width = 0;
	flag->preci = 0;
	flag->length = '\0';
	flag->speci = '\0';
	bt == 1 ? flag->argptr = args : 0;
}
