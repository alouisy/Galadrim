#include "galadrim.h"

t_cell	*new_cell(char **tab)
{
	t_cell	*cell;

	cell = (t_cell *)malloc(sizeof(t_cell));
	if (cell)
	{
		cell->id = ft_atoi(tab[0]);
		cell->x = ft_atoi(tab[1]);
		cell->y = ft_atoi(tab[2]);
		cell->dist = 0;
		cell->dist_diag = 0;
		cell->next = NULL;
	}
	return (cell);
}

void	add_cell(char **tab, t_prms *prm)
{
	t_cell	*list;

	list = NULL;
	if (prm->cell_list == NULL)
		prm->cell_list = new_cell(tab);
	else
	{
		list = prm->cell_list;
		while (list->next != NULL)
			list = list->next;
		list->next = new_cell(tab);
	}
}

int		split_n_get(char *line, t_prms *prm)
{
	char	**split;

	prm->nb_cell_total++;
	split = ft_strsplit(line, ',');
	add_cell(split, prm);
	return (1);
}

void	get_info(t_prms *prm)
{
	int		i;
	int		check;

	i = 0;
	check = -1;
	prm->time = ft_atoi(prm->tab[0]);
	if (prm->time > 0 && prm->tab != NULL)
	{
		while (prm->tab[++i] != NULL)
			split_n_get(prm->tab[i], prm);
	}
	else
		ft_error("ERROR", 1);
}