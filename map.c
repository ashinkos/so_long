/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:53:34 by aaouni            #+#    #+#             */
/*   Updated: 2022/08/10 00:22:18 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "gnl.h"

int	count_map_height(char *filename)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		return (-1);
	}
	str = getnl (fd);
	while (str)
	{
		i++;
		str = getnl (fd);
	}
	close(fd);
	return (i);
}

int	check_map(char **map, int map_height)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_height)
	{
		j = 0;
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (-1);
		while (j < ft_strlen(map[i]) && (i == 0 || i == map_height - 1))
		{
			if (map[i][j] != '1')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*str;
	int		map_height;
	int		map_width;
	char	**map;
	int		i;

	if (ac != 2)
	{
		write(1, "error", 5);
		exit (1);
	}
	map_height = count_map_height(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "error", 5);
		exit (1);
	}
	map = malloc(sizeof(char *) * map_height);
	str = getnl (fd);
	i = 0;
	// printf("here");
	while (i < map_height)
	{
		map[i] = ft_strtrim(str, "\n");
		if (i == 0)
			map_width = ft_strlen(map[i]);
		else if (map_width != ft_strlen (map[i]))
		{
			write(1, "error_width", 11);
			exit (1);
		}
		i++;
		str = getnl (fd);
	}
	 i = 0;
	// while (i < map_height)
	// {
	// 	printf("%s\n", map[i]);
	// 	i++;
	// }
	if (check_map(map, map_height) != 0)
	{
		write(1, "error_map", 9);
		exit (1);
	}
	return (0);

}
