/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:00:47 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/06/08 17:13:55 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	ft_atoi_psuh_swap(const char *str)
{
	int			i;
	int			negative;
	long long	result;

	i = 0;
	result = 0;
	negative = 1;
	if (str[0] != '+' || str[0] != '-' || !(str[0] >= '0' && str[0] <= '9'))
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
void	ft_putchar_test(char c)
{
	write(1, &c, 1);
}
void	ft_putnbr(int n, int *i)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*i) += 11;
	}
	else
	{
		if (n < 0)
		{
			(*i)++;
			ft_putchar_test('-');
			n *= (-1);
		}
		(*i)++;
		if (n > 9)
			ft_putnbr(n / 10, i);
		ft_putchar_test(n % 10 + '0');
	}
}

/* int	check_int_max_min(int *tabint)
{
	
}

int	check_dupnb(char *tabstr, char c)
{
	int	i;

	i = 0;
	while (tabstr[i])
	{
		if (tabstr[i] == c)
			return (-1);
		i++;
	}
	tabstr[i] = c;
	return (0);
} */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
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
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (-1);
			if (ft_atoi_psuh_swap(argv[i]) == 0)
			{
				if (ft_strcmp(argv[i], "0") != 0)
					return (-1);
			}
			if (argv[k] && ft_strcmp(argv[i], argv[k]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

/* int	parsing(int argc, char **argv)
{
	int			i;
	int			j;
	int			k;
	//static char	tabstr[1000];
	//static int	tabint[1000];
	i = 1;
	if (argc < 2)
		return (-1);
	while (argv[i])
	{
		j = 0;
		k = i + 1;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (-1);
			if (argv[k] && ft_strcmp(argv[i], argv[k]) == 0)
				return (-1);
			//if (check_dupnb(tabstr, argv[i][j]) == -1)
			//tabint[j] = argv[i][j] - 48;
			j++;
		}
		//if (check_int_max(tabint) == -1)
		if (argv[i] <= "-2147483648" || argv[i] >= "2147483647")
			return (-1);
		i++;
	}
} */
