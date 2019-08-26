/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:37:45 by odushko           #+#    #+#             */
/*   Updated: 2019/01/09 14:37:49 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;

typedef struct	s_tetro
{
	int				x[4];
	int				y[4];
	struct s_tetro	*next;
	char			symbol;
}				t_tetro;

int				hash_counting(char *arr, int size);
int				check_for_connect(char *arr);
void			file_to_list(int fd, t_tetro **lst);
char			**create_matrix(int size);
void			show_matrix(char **matrix, int size);
char			**arr_to_matrix(char *arr);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_fault(void);
void			ft_usage(void);
void			ft_bzero(char *str, int size);
void			clear_matrix(char **arr, int size);
void			print_list(t_tetro *head);
t_tetro			*new_lst(int *x, int *y, char symbol);
void			add_to_end(t_tetro **lst, t_tetro *new);
void			lstdel_first(t_tetro **lst);
void			lstclear(t_tetro **lst);
int				push_to_matrix(char **matrix, t_tetro *element,
									t_coord position, int size);

#endif
