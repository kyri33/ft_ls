/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 13:03:58 by kioulian          #+#    #+#             */
/*   Updated: 2017/03/25 14:50:35 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H

# include "includes/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>

typedef struct	s_dir
{
	char			*dir;
	time_t			time;
	int				is_dir;
	char			*full_path;
	struct s_dir	*next;
}				t_dir;

typedef struct	s_env
{
	int				l;
	int				a;
	int				r;
	int				t;
	int				rr;
	char			*path;
	DIR				*dirp;
	struct dirent	*dp;
	struct stat		sb;
	t_dir			*list;
}				t_env;

void			ft_ls(t_env *e);
int				compare_time(t_dir d1, t_dir d2);
void			do_ls(char *dir, t_env *e);
void			sort_list(t_dir **head, int (*cmp)(t_dir, t_dir), int done);
int				compare_strings(t_dir d1, t_dir d2);
void			do_list(t_env *e);
void			print_l(t_dir *list);
void			init_vals(t_env *e);
int				free_list(t_dir *list);
void			free_vals(t_dir *list, t_dir *temp);
int				get_path(char *dir, char *name, t_dir *temp);

#endif
