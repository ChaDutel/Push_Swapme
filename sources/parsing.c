/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:00:47 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/06/09 15:33:10 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_dup(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if ((ft_strcmp(str[i], "0") == 0 && ft_strcmp(str[j], "-0") == 0) \
				|| (ft_strcmp(str[i], "-0") == 0 \
				&& ft_strcmp(str[j], "0") == 0))
				return (-1);
			if (ft_strcmp(str[i], str[j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_int_min_max(char *str)
{
	if (ft_atoi_push_swap(str) == 0)
	{
		if (ft_strcmp(str, "0") != 0 && ft_strcmp(str, "-0") != 0)
			return (-1);
	}
	return (0);
}

int	check_only_nb(char c, char cnegative)
{
	if ((c < '0' || c > '9') && cnegative != '-')
		return (-1);
	return (0);
}

int	parsing(int argc, char **argv)
{
	int			i;
	int			j;
	int			k;

	i = 1;
	if (argc < 2)
		return (-1);
	while (argv[i])
	{
		j = 0;
		k = i + 1;
		while (argv[i][j])
		{
			if (check_only_nb(argv[i][j], argv[i][0]) == -1)
				return (-1);
			if (check_int_min_max(argv[i]) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	if (check_dup(argv) == -1)
		return (-1);
	return (0);
}
