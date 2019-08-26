/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbasnaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:56:51 by sbasnaka          #+#    #+#             */
/*   Updated: 2018/12/28 15:56:52 by sbasnaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_position(char **matrix, t_tetro *element, t_coord position,
	int size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (element->x[i] + position.x >= size || element->y[i] + position.y
			>= size || matrix[element->x[i] + position.x][element->y[i] +
				position.y] != '.')
			return (0);
		i++;
	}
	return (1);
}

static void	backstep(char **matrix, t_tetro *element, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (matrix[i][j] == element->symbol)
				matrix[i][j] = '.';
			j++;
		}
		i++;
	}
}

static void	change_position(t_coord *position, int size)
{
	if (position->y == size - 1)
	{
		position->x++;
		position->y = 0;
	}
	else
		position->y++;
}

static void	insertion(char **matrix, t_tetro *element, t_coord position)
{
	int i;

	i = 0;
	while (i < 4)
	{
		matrix[element->x[i] + position.x][element->y[i] + position.y] =
		element->symbol;
		i++;
	}
}

int			push_to_matrix(char **matrix, t_tetro *element, t_coord position,
																	int size)
{
	t_coord zeroing;

	if (check_position(matrix, element, position, size))
	{
		insertion(matrix, element, position);
		if (element->next == NULL)
			return (1);
		zeroing.x = 0;
		zeroing.y = 0;
		if (push_to_matrix(matrix, element->next, zeroing, size) == 0)
		{
			backstep(matrix, element, size);
			change_position(&position, size);
			return (push_to_matrix(matrix, element, position, size));
		}
		return (1);
	}
	else
	{
		if (position.x == size - 1 && position.y == size - 1)
			return (0);
		change_position(&position, size);
		return (push_to_matrix(matrix, element, position, size));
	}
}
