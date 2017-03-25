/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:01:30 by kioulian          #+#    #+#             */
/*   Updated: 2017/03/25 14:50:59 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int	compare_time(t_dir d1, t_dir d2)
{
	if (d1.time < d2.time)
		return (1);
	else
		return (0);
}

int	compare_strings(t_dir d1, t_dir d2)
{
	return (ft_strcmp(d1.dir, d2.dir));
}

int	get_path(char *dir, char *name, t_dir *temp)
{
	char	*path;
	char	*fullpath;
	
	path = ft_strjoin(dir, "/");
	fullpath = ft_strjoin(path, name);
	temp->full_path = strdup(fullpath);
	free(fullpath);
	free(path);
	fullpath = NULL;
	path = NULL;
	return (1);
}

int	free_list(t_dir *list)
{
	t_dir *temp;
	t_dir *tofree;

	temp = list;
	while (temp != NULL)
	{
		free(temp->dir);
		free(temp->full_path);
		temp->dir = NULL;
		temp->full_path = NULL;
		tofree = temp;
		temp = temp->next;
		free(tofree);
		tofree = NULL;
	}
	return (1);
}
