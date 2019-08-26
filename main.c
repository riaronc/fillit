/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:40:09 by odushko           #+#    #+#             */
/*   Updated: 2019/01/09 14:40:11 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

static void		initti(int *size, t_tetro **lst, t_coord *position)
{
	*lst = NULL;
	*size = 2;
	position->x = 0;
	position->y = 0;
}

int				main(int argc, char const *argv[])
{
	int		fd;
	int		size;
	char	**matrix;
	t_coord	position;
	t_tetro	*lst;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		initti(&size, &lst, &position);
		file_to_list(fd, &lst);
		matrix = create_matrix(size);
		while (!push_to_matrix(matrix, lst, position, size))
		{
			clear_matrix(matrix, size);
			size++;
			matrix = create_matrix(size);
		}
		show_matrix(matrix, size);
		lstclear(&lst);
		close(fd);
	}
	else
		ft_usage();
	return (0);
}
