/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faults.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbasnaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:01:54 by sbasnaka          #+#    #+#             */
/*   Updated: 2018/12/26 15:01:56 by sbasnaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_fault(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	ft_usage(void)
{
	ft_putstr("usage: ./fillit sample\n");
	exit(1);
}

void	ft_bzero(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}
