#include "galadrim.h"

static void		aux_usage(char *str)
{
	printf("Usage: %s <input.txt>\n", str);
	printf("       %s\n", str);
}

static void		prm_init(t_prms *prm)
{
	int		origin[3] = {0, 0, 0};

	prm->time = 0;
	prm->nb_cell = 0;
	prm->nb_cell_total = 0;
	prm->cell_list = NULL;
	prm->player = new_cell(origin);
	prm->solution = NULL;
}

int				main(int argc, char *argv[])
{
	t_prms		prm;
	int			fd;

	prm_init(&prm);
	if (argc == 1 || argc == 2)
	{
		if (!(strcmp(argv[1], "--help")) || !(strcmp(argv[1], "-h")))
			aux_usage(argv[0]);
		else
		{
			fd = (argc == 1) ? 0 : safe_open(argv[1]);
			if (fd != -1)
			{
				get_parsed_data(fd, &prm);
				while (prm.time > 0 && prm.cell_list)
				{
					get_dist(&prm);
					get_next_cell(&prm);
				}
			}
			else
				aux_usage(argv[0]);
		}
	}
	else
		aux_usage(argv[0]);
	return (0);
}
