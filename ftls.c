/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:46:15 by kioulian          #+#    #+#             */
/*   Updated: 2017/03/25 14:51:58 by kioulian         ###   ########.fr       */
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
	char	*new;

	if (e->t == 1)
		sort_list(&list, compare_time, 0);
	if (e->r == 1)
		list = ft_rev_list(list);
	new = ft_strjoin(path, "/");
	ft_putstr(new);
	free(new);
	if (e->l == 1)
		print_l(list);
	else
	{
		temp = list;
		while (temp != NULL)
		{
			ft_putstr("\n\t");
			ft_putstr(temp->dir);
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
				temp->dir = ft_strdup(e->dp->d_name);
				get_path(dir, e->dp->d_name, temp);
				lstat(temp->full_path, &e->sb);
				temp->time = e->sb.st_mtime;
				if (S_ISDIR(e->sb.st_mode) == 1)
					temp->is_dir = 1;
				temp->next = list;
				list = temp;
			}
		}
		closedir(e->dirp);
		ft_print_ls(list, e, dir);
		free_list(list);
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
