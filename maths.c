#include "galadrim.h"

void	get_dist(t_prms *prm)
{
	t_cell	*tmp;

	tmp = prm->cell_list;
	while (tmp != NULL)
	{
		tmp->dist = (tmp->x - prm->player->x) + (tmp->y - prm->player->y);
		tmp->dist_diag = sqrt(((tmp->x - prm->player->x) * (tmp->x - prm->player->x)) + ((tmp->y - prm->player->y) * (tmp->y - prm->player->y)));
		tmp = tmp->next;
	}
}