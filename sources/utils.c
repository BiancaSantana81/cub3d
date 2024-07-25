#include "../includes/cub.h"

void	handle_error(char *error)
{
	t_data	*data;

	data = get_data(NULL);
	if (data)
		free_data(data);
	ft_putstr_fd(error, 2);
	exit(1);
}

t_data	*get_data(t_data *data)
{
	static t_data	*data_ptr;

	if (data)
		data_ptr = data;
	return (data_ptr);
}

void	free_data(t_data *data)
{
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->floor)
		free(data->floor);
	if (data->ceiling)
		free(data->ceiling);
	//if (data->map)
	//	ft_free_matrix(data->map);
}