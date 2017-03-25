/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:46:15 by kioulian          #+#    #+#             */
/*   Updated: 2016/12/02 17:56:57 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"
#include <stdio.h>

t_dir	*ft_rev_list(t_dir *head)
{
	t_dir	*list;
	t_dir	*next;

	list = NULL;
	while (head)
	{
		next = head->next;
		head->next = list;
		list = head;
		head = next;
	}
	free(next);
	return (list);
}

void	big_r(t_dir *list, t_env *e)
{
	t_dir *temp;

	temp = list;
	while (temp != NULL)
	{
		if (temp->is_dir == 1 && temp->dir[0] != '.')
			do_ls(temp->full_path, e);
		temp = temp->next;
	}
}

void	ft_print_ls(t_dir *list, t_env *e, char *path)
{
	t_dir	*temp;

	if (e->t == 1)
		sort_list(&list, compare_time, 0);
	if (e->r == 1)
		list = ft_rev_list(list);
	ft_putstr(ft_strjoin(path, "/"));
	if (e->l == 1)
		print_l(list, e);
	else
	{
		temp = list;
		while (temp != NULL)
		{
			ft_putstr("\n\t");
			ft_putstr(temp->dir);
			//printf("\n\t%s", temp->dir);
			temp = temp->next;
		}
	}
	ft_putchar('\n');
	if (e->rr == 1)
		big_r(list, e);
}

void	do_ls(char *dir, t_env *e)
{
	t_dir			*list;
	t_dir			*temp;

	list = NULL;
	if ((e->dirp = opendir(dir)) != NULL)
	{
		while ((e->dp = readdir(e->dirp)) != NULL)
		{
			if (e->dp->d_name[0] != '.' || e->a == 1)
			{
				temp = (t_dir *)malloc(sizeof(t_dir));
				temp->dir = e->dp->d_name;
				temp->full_path = ft_strjoin(ft_strjoin(dir, "/"),
						e->dp->d_name);
				lstat(temp->full_path, &e->sb);
				temp->time = e->sb.st_mtime;
				if (S_ISDIR(e->sb.st_mode) == 1)
					temp->is_dir = 1;
				temp->next = list;
				list = temp;
				temp = list;
		while (temp != NULL)
		{
			ft_putstr(temp->dir);
			ft_putstr(" ");
			temp = temp->next;
		}
		ft_putstr("\n\n");
				//ft_putstr("Got ");ft_putstr(temp->dir);ft_putstr(" ");
			}
		}
		closedir(e->dirp);
		ft_print_ls(list, e, dir);
		free(temp);
		temp = NULL;
	}
}

void	ft_ls(t_env *e)
{
	t_dir	*temp;

	temp = e->list;
	while (temp != NULL)
	{
		do_ls(temp->dir, e);
		temp = temp->next;
	}
}
