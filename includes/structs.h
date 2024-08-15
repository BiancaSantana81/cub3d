#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/src/libft.h"

typedef struct s_data
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			**map;
	bool			colors;
	uint32_t		floor;
	uint32_t		ceiling;
	int				size_textures;
	int				lines;
	int				columns;
	int				x_player;
	int				y_player;
	char			pov_player;
}	t_data;

typedef struct s_keys
{
    bool w;
    bool s;
    bool a;
    bool d;
    bool left;
    bool right;
} t_keys;

typedef struct s_validate
{
	int		invalid;
	int		player;
	int		n;
}	t_validate;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	sx;
	int	sy;
	int	dx;
	int	dy;
	int	err;
}	t_line;

typedef struct s_dda
{
	float		plane_multiplier;
	t_vector	dir; //raio que sai do player
	t_vector	camera_pixel; //distancia de dir para raydir
	t_vector	delta_dist; //depois de dist_to_side_x e dist_to_side_y até o próximo encontro com x ou y
	t_vector	dist_side; //distancia ate o proximo lado em x ou y
	t_coord		map; //posicao no mapa
	t_coord		step; //passos dados em x e y
	int			hit_side; //lado que bateu
	float		perp_dist; //distancia do plano de camera ate a parede
	float		wall_hit_x; //onde o raio bateu
}	t_dda;

typedef struct s_wall
{
	int		line_start_y;
	int		line_end_y;
	int		texture_x;
	float	tex_step;
	float	tex_pos;
}	t_wall;

typedef struct s_cub
{
	uint32_t		window_width;
	uint32_t		window_height;
	mlx_t			*mlx;
	mlx_image_t		*mlx_image;
	mlx_texture_t	*texture;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	int				*texture_buffer[4];
	t_keys			keys;
	t_vector		pos; //posicao do player
	t_vector		dir; //direcao do player
	t_vector		camera_plane; //plano da camera
	int				hit_side; //lado que bateu
	float			frame_time;
	t_data			*data;
}	t_cub;

typedef enum e_mlx_action
{
	INIT,
	NEW_IMAGE,
}	t_mlx_action;

#endif
