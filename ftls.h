#ifndef _FT_LS_
# define _FT_LS_

#include "includes/libft.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/stat.h>

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
	int		l;
	int		a;
	int		r;
	int		t;
	int		R;
	char	*path;
	DIR		*dirp;
	struct	dirent	*dp;
	struct stat		sb;
	t_dir	*list;
}				t_env;

void	ft_ls(t_env *e);
int		compare_time(t_dir d1, t_dir d2);
void	do_ls(char *dir, t_env *e);
void	sort_list(t_dir **head, int (*cmp)(t_dir, t_dir));
int		compare_strings(t_dir d1, t_dir d2);

#endif
