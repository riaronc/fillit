/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbasnaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:06:19 by sbasnaka          #+#    #+#             */
/*   Updated: 2018/12/26 15:06:20 by sbasnaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			hash_counting(char *arr, int size)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i * 5 + j] == '#')
				count++;
			if (arr[i * 5 + j] != '#' && arr[i * 5 + j] != '.')
				ft_fault();
			j++;
		}
		if (arr[i * 5 + j] != '\n')
			ft_fault();
		i++;
	}
	return (count);
}

static void	neighborhood(char **matrix, int i, int j, int *hash)
{
	if (matrix[i][j] == '#')
	{
		matrix[i][j] = '.';
		*hash += 1;
		if (i != 0)
			neighborhood(matrix, i - 1, j, hash);
		if (j != 0)
			neighborhood(matrix, i, j - 1, hash);
		if (i != 3)
			neighborhood(matrix, i + 1, j, hash);
		if (j != 3)
			neighborhood(matrix, i, j + 1, hash);
	}
}

int			check_for_connect(char *arr)
{
	int		i;
	int		j;
	char	**matrix;
	int		hash;

	matrix = arr_to_matrix(arr);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (matrix[i][j] == '#')
			{
				hash = 0;
				neighborhood(matrix, i, j, &hash);
				if (hash != 4)
					return (0);
			}
			j++;
		}
		i++;
	}
	clear_matrix(matrix, 4);
	return (1);
}
