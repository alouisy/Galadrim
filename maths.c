#include "galadrim.h"

void	get_dist(t_prms *prm)
{
	t_cell	*tmp;

	tmp = prm->cell_list;
	while (tmp != NULL)
	{
		tmp->dist = abs(tmp->x - prm->player->x) + abs(tmp->y - prm->player->y);
		tmp->dist_diag = sqrt(pow((tmp->x - prm->player->x), 2) + pow((tmp->y - prm->player->y), 2));
		tmp->dist_diag_r = ceil(tmp->dist_diag);
//		tmp->dist_diag_r = ceil(sqrt(pow((tmp->x - prm->player->x), 2) + pow((tmp->y - prm->player->y), 2)));
//		tmp->dist_diag = round(sqrt(pow((tmp->x - prm->player->x), 2) + pow((tmp->y - prm->player->y), 2)));
		tmp = tmp->next;
	}
}