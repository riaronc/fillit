/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbasnaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:57:41 by sbasnaka          #+#    #+#             */
/*   Updated: 2018/12/23 15:57:44 by sbasnaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tetro		*new_lst(int *x, int *y, char symbol)
{
	t_tetro *new;
	int		i;

	if (!(new = (t_tetro *)malloc(sizeof(t_tetro))))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		new->x[i] = x[i];
		new->y[i] = y[i];
		i++;
	}
	new->symbol = symbol;
	new->next = NULL;
	return (new);
}

void		add_to_end(t_tetro **lst, t_tetro *new)
{
	t_tetro *tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void		lstdel_first(t_tetro **lst)
{
	t_tetro *tmp;

	tmp = (*lst)->next;
	free(*lst);
	*lst = NULL;
	*lst = tmp;
}

void		lstclear(t_tetro **lst)
{
	while ((*lst)->next != NULL)
		lstclear(&(*lst)->next);
	lstdel_first(lst);
}
