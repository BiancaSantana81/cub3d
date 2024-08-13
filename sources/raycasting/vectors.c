#include "../../includes/cub.h"

void	define_dir_vector(t_cub *game)
{
	if (game->data->pov_player == 'N')
		game->dir = create_vector(0, -1);
	else if (game->data->pov_player == 'S')
		game->dir = create_vector(0, 1);
	else if (game->data->pov_player == 'W')
		game->dir = create_vector(-1, 0);
	else if (game->data->pov_player == 'E')
		game->dir = create_vector(1, 0);
}

//inicializar a posição do player e a direção inicial
void	setup(t_cub *game)
{
	
	game->pos = create_vector(game->data->x_player,
			game->data->y_player);
	define_dir_vector(game);
	game->camera_plane = create_vector(0.66, 0);
}
