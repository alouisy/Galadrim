#ifndef GALADRIM_H
# define GALADRIM_H

# include <math.h>
# include <stdio.h>
# include "libft/includes/libft.h"

typedef struct		s_prms
{
	int				time;
	int				nb_cell;
	int				nb_cell_total;
	char			*text;
	char			**tab;
	struct s_cell	*cell_list;
	struct s_cell	*player;
	struct s_soluce	*solution;
}					t_prms;

typedef struct		s_cell
{
	int				id;
	int				x;
	int				y;
	int				dist;
	float			dist_diag;
	int				id_next_cell;
	struct s_cell	*cell;
	struct s_cell	*prev;
	struct s_cell	*next;
}					t_cell;

typedef struct		s_soluce
{
	int				id;
	struct s_soluce	*next;
}					t_soluce;


/*
** parser.c
*/
void				get_info(t_prms *prm);
int					split_n_get(char *line, t_prms *prm);
void				add_cell(char **tab, t_prms *prm);
t_cell				*new_cell(char **tab);
/*
** maths.c
*/
void				get_dist(t_prms *prm);

/*
** solution.c
*/
t_soluce			*new_solution(int id);
void				add_cell_soluce(t_cell *prev, t_cell *cell, t_prms *prm);
void				get_next_cell(t_prms *prm);

/*
** parser.c
*/

#endif
