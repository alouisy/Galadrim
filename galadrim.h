#ifndef GALADRIM_H
# define GALADRIM_H

# include <math.h>
# include <stdio.h>
# include <assert.h>
# include "libft/includes/libft.h"

typedef struct		s_prms
{
	double			time;
	int				nb_cell;
	int				nb_cell_total;
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
	double			dist_diag;
	double			dist_diag_r;
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
void				get_parsed_data(int fd, t_prms *prm);
void				split_line(char *line, t_prms *prm);
void				add_cell(int tab[3], t_prms *prm);
t_cell				*new_cell(int tab[3]);
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
