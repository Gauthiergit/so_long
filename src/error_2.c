/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:21:16 by gpeyre            #+#    #+#             */
/*   Updated: 2024/01/15 15:39:17 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_error_file(int argc, char **argv)
{
	char	*type_file;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		ft_printf("Error\nNo map in parameter\n");
		exit(1);
	}
	type_file = ft_strrchr(argv[1], '.');
	if (ft_strncmp(type_file, ".ber", 4) != 0)
	{
		ft_printf("Error\nThe parameter isn't of type .ber\n");
		exit(1);
	}
	if (fd == -1)
	{
		ft_printf("Error\nFile not found or empty\n");
		exit(1);
	}
	close(fd);
}

int	is_valid_cara(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (!ft_strchr("01PCWE", map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
