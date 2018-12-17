#include "galadrim.h"

static void		prm_init(t_prms *prm)
{
	prm->time = 0;
	prm->nb_cell = 0;
	prm->nb_cell_total = 0;
	prm->text = NULL;
	prm->tab = NULL;
	prm->cell_list = NULL;
	prm->player = (t_cell *)malloc(sizeof(t_cell));
	prm->player->x = 0;
	prm->player->y = 0;
	prm->player->dist = 0;
	prm->player->dist_diag = 0;
	prm->player->cell = NULL;
	prm->player->prev = NULL;
	prm->player->next = NULL;
	prm->solution = NULL;
}

int				main(int argc, char *argv[])
{
	t_prms		prm;
	int			fd;

	prm_init(&prm);
	if (argc == 1 || argc == 2)
	{
		fd = (argc == 1) ? 0 : safe_open(argv[1]);
		prm.text = ft_get_file(fd);
		prm.tab = ft_strsplit(prm.text, '\n');
		get_info(&prm);
		while (prm.time > 0 && prm.cell_list)
		{
			get_dist(&prm);
			get_next_cell(&prm);
		}
	}
	else
		ft_error("BAD INPUT !", 1);
	return (0);
}
