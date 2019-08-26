/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbasnaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:04:02 by sbasnaka          #+#    #+#             */
/*   Updated: 2018/12/26 15:04:04 by sbasnaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**create_matrix(int size)
{
	int		i;
	int		j;
	char	**matrix;

	matrix = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		matrix[i] = (char *)malloc(sizeof(char) * size);
		j = 0;
		while (j < size)
		{
			matrix[i][j] = '.';
			j++;
		}
		i++;
	}
	return (matrix);
}

void	show_matrix(char **matrix, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_putchar(matrix[i][j]);
		ft_putchar('\n');
	}
}

void	clear_matrix(char **arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**arr_to_matrix(char *arr)
{
	int		i;
	int		j;
	char	**matrix;

	matrix = (char **)malloc(sizeof(char *) * 4);
	i = 0;
	while (i < 4)
	{
		matrix[i] = (char *)malloc(sizeof(char) * 4);
		i++;
	}
	i = 0;
	j = 0;
	while (i * 5 + j < 20)
	{
		if (arr[i * 5 + j] == '\n')
		{
			i++;
			j = 0;
			continue ;
		}
		matrix[i][j] = arr[i * 5 + j];
		j++;
	}
	return (matrix);
}
