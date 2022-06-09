/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:43:38 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/06/09 14:48:15 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	ft_atoi_push_swap(const char *str)
{
	int			i;
	int			negative;
	long long	result;

	i = 0;
	result = 0;
	negative = 1;
	if (str[0] != '+' && str[0] != '-' && !(str[0] >= '0' && str[0] <= '9'))
		return (0);
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	if (result * negative < -2147483648 || result * negative > 2147483647)
		return (0);
	return (result * negative);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
