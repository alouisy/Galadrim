#include "galadrim.h"

t_cell	*new_cell(int tab[3])
{
	t_cell	*cell;

	cell = NULL;
	cell = (t_cell *)malloc(sizeof(t_cell));
	if (cell)
	{
		cell->id = tab[0];
		cell->x = tab[1];
		cell->y = tab[2];
		cell->dist = 0;
		cell->dist_diag = 0;
		cell->dist_diag_r = 0;
		cell->cell = NULL;
		cell->prev = NULL;
		cell->next = NULL;
	}
	return (cell);
}

void	add_cell(int tab[3], t_prms *prm)
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

void	split_line(char *line, t_prms *prm)
{
	int		i, tab[3];
	char	*token, *string, *tofree;

	i = -1;
	tofree = string = strdup(line);
	assert(string != NULL);
	while ((token = strsep(&string, ",")) != NULL)
		tab[++i] = atoi(token);
	free(tofree);
	add_cell(tab, prm);
	prm->nb_cell_total++;
}

void	get_parsed_data(int fd, t_prms *prm)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (i == 0)
			prm->time = (double)atoi(line);
		else
		 	split_line(line, prm);
		i++;
		free(line);
	}
}