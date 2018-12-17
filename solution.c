#include "galadrim.h"

t_soluce	*new_solution(int id)
{
	t_soluce	*soluce;

	soluce = (t_soluce *)malloc(sizeof(t_soluce));
	if (soluce)
	{
		soluce->id = id;
		soluce->next = NULL;
	}
	return (soluce);
}

void	add_cell_soluce(t_cell *prev, t_cell *cell, t_prms *prm)
{
	t_soluce	*list;

	list = NULL;
	if (cell != NULL)
	{	
		if ((prm->time - prm->player->dist_diag) > 0)
		{
			if (prm->solution == NULL)
				prm->solution = new_solution(cell->id);
			else
			{
				list = prm->solution;
				while (list->next != NULL)
					list = list->next;
				list->next = new_solution(cell->id);
			}
			if (prev == prm->cell_list)
				prm->cell_list = prev->next;
			else
				prev->next = cell->next;
			prm->nb_cell++;
			printf("%d\n", cell->id);
/*			printf("%d dist : %d time : %d time-d : %d player_x :%d player_y :%d cell_x :%d cell_y :%d\n",
				cell->id,
				prm->player->dist_diag,
				prm->time,
				(prm->time - prm->player->dist_diag),
				prm->player->x,
				prm->player->y,
				cell->x,
				cell->y);
*/			prm->time -= prm->player->dist_diag;
			prm->player->x = cell->x;
			prm->player->y = cell->y;
			prm->player->dist = 0;
			prm->player->dist_diag = 0;
			prm->player->cell = NULL;
			prm->player->prev = NULL;
		}
		else
			prm->time = 0;
	}
	prm->player->dist = 0;
	prm->player->dist_diag = 0;
	prm->player->cell = NULL;
	prm->player->prev = NULL;
}

void	get_next_cell(t_prms *prm)
{
	t_cell	*tmp;
	t_cell	*prev;

	tmp = prm->cell_list;
	prev = prm->cell_list;
	prm->player->dist = tmp->dist;
	prm->player->dist_diag = tmp->dist_diag;
	prm->player->cell = tmp;
	prm->player->prev = prev;
	while (tmp != NULL)
	{
		if (tmp->dist_diag < prm->player->dist_diag)
		{
			prm->player->dist = tmp->dist;
			prm->player->dist_diag = tmp->dist_diag;
			prm->player->cell = tmp;
			prm->player->prev = prev;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	add_cell_soluce(prm->player->prev, prm->player->cell, prm);
}