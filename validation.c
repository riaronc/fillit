/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbasnaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:05:10 by sbasnaka          #+#    #+#             */
/*   Updated: 2018/12/26 15:05:11 by sbasnaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		coordinates_left(int *x, int *y)
{
	while (x[0] * x[1] * x[2] * x[3] != 0)
	{
		x[0]--;
		x[1]--;
		x[2]--;
		x[3]--;
	}
	while (y[0] * y[1] * y[2] * y[3] != 0)
	{
		y[0]--;
		y[1]--;
		y[2]--;
		y[3]--;
	}
}

static void		init(int *i, int *j, int *n)
{
	*i = 0;
	*j = -1;
	*n = 0;
}

static t_tetro	*creating_elements(char *arr, char symbol)
{
	int i;
	int j;
	int n;
	int x[4];
	int y[4];

	if (symbol == 'Z' + 1)
		ft_fault();
	init(&i, &j, &n);
	while (i * 5 + ++j < 20)
	{
		if (arr[i * 5 + j] == '#')
		{
			x[n] = i;
			y[n] = j;
			n++;
		}
		if (arr[i * 5 + j] == '\n')
		{
			i++;
			j = -1;
		}
	}
	coordinates_left(x, y);
	return (new_lst(x, y, symbol));
}

void			file_to_list(int fd, t_tetro **lst)
{
	char buf[20];
	char skip[1];
	char symbol;

	symbol = 'A' - 1;
	if (fd == -1)
		ft_fault();
	while (1)
	{
		ft_bzero(buf, 20);
		read(fd, buf, 20);
		if (skip[0] == '\n' && buf[0] == '\0')
			ft_fault();
		ft_bzero(skip, 1);
		read(fd, skip, 1);
		if (hash_counting(buf, 4) != 4 || check_for_connect(buf) != 1)
			ft_fault();
		else
			add_to_end(lst, creating_elements(buf, ++symbol));
		if (skip[0] == '\0')
			break ;
	}
}
