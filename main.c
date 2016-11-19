/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 15:50:58 by kioulian          #+#    #+#             */
/*   Updated: 2016/11/19 15:00:08 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int		add_args(t_env *e, char *arg)
{
	int	x;

	x = 1;
	while (arg[x] != '\0')
	{
		if (arg[x] == 'l')
			e->l = 1;
		else if (arg[x] == 'a')
			e->a = 1;
		else if (arg[x] == 'r')
			e->r = 1;
		else if (arg[x] == 't')
			e->t = 1;
		else if (arg[x] == 'R')
			e->rr = 1;
		else
		{
			ft_putstr("Invalid argument");
			return (0);
		}
		x++;
	}
	return (1);
}

int		compare_strings(t_dir d1, t_dir d2)
{
	return (ft_strcmp(d1.dir, d2.dir));
}

int		compare_time(t_dir d1, t_dir d2)
{
	if (d1.time < d2.time)
		return (1);
	else
		return (0);
}

void	sort_list(t_dir **head, int (*cmp)(t_dir, t_dir), int done)
{
	t_dir	**src;
	t_dir	*temp;
	t_dir	*next;

	while (!done && *head != NULL && (*head)->next != NULL)
	{
		src = head;
		temp = *head;
		next = (*head)->next;
		done = 1;
		while (next)
		{
			if (cmp(*temp, *next) > 0)
			{
				temp->next = next->next;
				next->next = temp;
				*src = next;
				done = 0;
			}
			src = &temp->next;
			temp = next;
			next = next->next;
		}
	}
}

int		main(int argc, char **argv)
{
	int		i;
	t_env	e;
	t_dir	*temp;

	i = 1;
	e.list = NULL;
	while (i < argc)
	{
		if (argv[i][0] != '-' && (temp = (t_dir *)malloc(sizeof(t_dir))))
		{
			temp->dir = argv[i];
			temp->next = e.list;
			e.list = temp;
		}
		else if (add_args(&e, argv[i]) == 0)
			return (0);
		i++;
	}
	if (e.list == NULL)
		do_list(&e);
	else
		sort_list(&e.list, compare_strings, 0);
	ft_ls(&e);
}
